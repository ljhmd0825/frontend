CSRCS += lv_draw_arc.c
CSRCS += lv_draw.c
CSRCS += lv_draw_img.c
CSRCS += lv_draw_label.c
CSRCS += lv_draw_line.c
CSRCS += lv_draw_mask.c
CSRCS += lv_draw_rect.c
CSRCS += lv_draw_transform.c
CSRCS += lv_draw_layer.c
CSRCS += lv_draw_triangle.c
CSRCS += lv_img_buf.c
CSRCS += lv_img_cache.c
CSRCS += lv_img_decoder.c

DEPPATH += --dep-path $(LVGL_DIR)/$(LVGL_DIR_NAME)/src/draw
VPATH += :$(LVGL_DIR)/$(LVGL_DIR_NAME)/src/draw

CFLAGS += "-I$(LVGL_DIR)/$(LVGL_DIR_NAME)/src/draw"

include $(LVGL_DIR)/$(LVGL_DIR_NAME)/src/draw/sdl/lv_draw_sdl.mk
include $(LVGL_DIR)/$(LVGL_DIR_NAME)/src/draw/sw/lv_draw_sw.mk
