#define QOI_IMPLEMENTATION
#include "qoi.h"
#include "qoi_decoder.h"
#include "../lvgl/lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool qoi_decoder_info_cb(lv_img_decoder_t *decoder, const void *src, lv_img_header_t *header);
static lv_res_t qoi_decoder_open_cb(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc);
static void qoi_decoder_close_cb(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc);

static bool is_qoi_path(const char *path) {
    if (!path) return false;
    size_t len = strlen(path);
    if (len < 4) return false;
    return strcasecmp(path + len - 4, ".qoi") == 0;
}

void qoi_decoder_init(void) {
    lv_img_decoder_t *dec = lv_img_decoder_create();
    lv_img_decoder_set_info_cb(dec, qoi_decoder_info_cb);
    lv_img_decoder_set_open_cb(dec, qoi_decoder_open_cb);
    lv_img_decoder_set_close_cb(dec, qoi_decoder_close_cb);
}

static bool qoi_decoder_info_cb(lv_img_decoder_t *decoder, const void *src, lv_img_header_t *header) {
    LV_UNUSED(decoder);
    if (lv_img_src_get_type(src) != LV_IMG_SRC_FILE) return false;
    if (!is_qoi_path((const char *) src)) return false;

    // MODIFIED: Use lv_fs_open to handle muOS virtual path prefixes (M:, S:, etc.)
    lv_fs_file_t f;
    if (lv_fs_open(&f, (const char *) src, LV_FS_MODE_RD) != LV_FS_RES_OK) return false;

    uint8_t buf[14];
    uint32_t rn;
    bool ok = lv_fs_read(&f, buf, sizeof(buf), &rn) == LV_FS_RES_OK && rn == sizeof(buf);
    lv_fs_close(&f);

    if (!ok) return false;
    if (buf[0] != 'q' || buf[1] != 'o' || buf[2] != 'i' || buf[3] != 'f') return false;

    uint32_t w = ((uint32_t)buf[4] << 24) | ((uint32_t)buf[5] << 16) | ((uint32_t)buf[6] << 8) | buf[7];
    uint32_t h = ((uint32_t)buf[8] << 24) | ((uint32_t)buf[9] << 16) | ((uint32_t)buf[10] << 8) | buf[11];

    header->always_zero = 0;
    header->w = (lv_coord_t) w;
    header->h = (lv_coord_t) h;
    header->cf = LV_IMG_CF_TRUE_COLOR_ALPHA;

    return true;
}

static lv_res_t qoi_decoder_open_cb(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc) {
    LV_UNUSED(decoder);
    if (lv_img_src_get_type(dsc->src) != LV_IMG_SRC_FILE) return LV_RES_INV;
    if (!is_qoi_path((const char *) dsc->src)) return LV_RES_INV;

    // MODIFIED: Use lv_fs_open for compatibility with muOS virtual file system
    lv_fs_file_t f;
    if (lv_fs_open(&f, (const char *) dsc->src, LV_FS_MODE_RD) != LV_FS_RES_OK) return LV_RES_INV;

    uint32_t file_size;
    lv_fs_seek(&f, 0, LV_FS_SEEK_END);
    lv_fs_tell(&f, &file_size);
    lv_fs_seek(&f, 0, LV_FS_SEEK_SET);

    if (file_size <= 0) { lv_fs_close(&f); return LV_RES_INV; }

    void *file_data = malloc((size_t) file_size);
    if (!file_data) { lv_fs_close(&f); return LV_RES_INV; }

    uint32_t rn;
    if (lv_fs_read(&f, file_data, file_size, &rn) != LV_FS_RES_OK || rn != file_size) {
        free(file_data);
        lv_fs_close(&f);
        return LV_RES_INV;
    }
    lv_fs_close(&f);

    qoi_desc desc;
    void *pixels = qoi_decode(file_data, (int) file_size, &desc, 4);
    free(file_data);
    if (!pixels) return LV_RES_INV;

    uint32_t pixel_count = desc.width * desc.height;
    uint8_t *src_px = (uint8_t *) pixels;

    lv_color32_t *lv_buf = malloc(pixel_count * sizeof(lv_color32_t));
    if (!lv_buf) { free(pixels); return LV_RES_INV; }

    for (uint32_t i = 0; i < pixel_count; i++) {
        lv_buf[i].ch.red   = src_px[i * 4 + 0];
        lv_buf[i].ch.green = src_px[i * 4 + 1];
        lv_buf[i].ch.blue  = src_px[i * 4 + 2];
        lv_buf[i].ch.alpha = src_px[i * 4 + 3];
    }
    free(pixels);

    dsc->img_data  = (const uint8_t *) lv_buf;
    dsc->header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
    dsc->header.w  = (lv_coord_t) desc.width;
    dsc->header.h  = (lv_coord_t) desc.height;

    return LV_RES_OK;
}

static void qoi_decoder_close_cb(lv_img_decoder_t *decoder, lv_img_decoder_dsc_t *dsc) {
    LV_UNUSED(decoder);
    if (dsc->img_data) {
        free((void *) dsc->img_data);
        dsc->img_data = NULL;
    }
}
