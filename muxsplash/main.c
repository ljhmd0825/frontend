#include "../lvgl/lvgl.h"
#include "../lvgl/drivers/display/fbdev.h"
#include "ui/ui.h"
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <time.h>
#include <libgen.h>
#include "../common/common.h"
#include "../common/device.h"
#include "../common/mini/mini.h"

struct mux_device device;

void setup_background_process() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Failed to fork");
        exit(1);
    } else if (pid > 0) {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    load_device(&device);
    srand(time(NULL));

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <full path to PNG image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    setup_background_process();

    lv_init();
    fbdev_init(device.SCREEN.DEVICE);

    static lv_disp_draw_buf_t disp_buf;
    uint32_t disp_buf_size = device.SCREEN.BUFFER;

    lv_color_t * buf1 = (lv_color_t *) malloc(disp_buf_size * sizeof(lv_color_t));
    lv_color_t * buf2 = (lv_color_t *) malloc(disp_buf_size * sizeof(lv_color_t));

    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, disp_buf_size);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.hor_res = device.SCREEN.WIDTH;
    disp_drv.ver_res = device.SCREEN.HEIGHT;
    disp_drv.sw_rotate = device.SCREEN.ROTATE;
    disp_drv.rotated = device.SCREEN.ROTATE;
    lv_disp_drv_register(&disp_drv);

    ui_init();

    char init_wall[MAX_BUFFER_SIZE];
    snprintf(init_wall, sizeof(init_wall), "M:%s", argv[1]);

    lv_obj_t * img = lv_img_create(ui_scrSplash);
    lv_img_set_src(img, init_wall);

    lv_task_handler();

    usleep(device.SCREEN.WAIT);

    return 0;
}

uint32_t mux_tick(void) {
    static uint64_t start_ms = 0;

    if (start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);

    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}