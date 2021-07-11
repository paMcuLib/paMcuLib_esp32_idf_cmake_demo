#include "MainApp.c.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
#include "paCoreInc/all"
#include "paMods/display/ILI9341/pa_ILI9341.h"
#include "paMods/display/lvgl/lvgl.h"
// #include "paMods/display/SSD1306/pa_oled.h"
// #include "paCoreHead/paIIC.h"
// #include "paCoreHead/paBase.h"
// #include "paCoreHead/paSPI.h"
// #include "paCoreHead/paBase.h"

#include "Talk.h"

struct AppVar
{
    pa_ILI9341 lcd;
    // RobotArmApp robotArm;
    // Talk talk;
};

AppVar appVar;
void timerCall_100us()
{
    // app.robotArm.onTimerTick();
}

#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 320

void palv_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int32_t bufSize = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
    /*It's a very slow but simple implementation.
     *`set_pixel` needs to be written by you to a set pixel on the screen*/
    appVar.lcd.setAddress(area->x1, area->y1, area->x2, area->y2);
    appVar.lcd.transmitBuf((uint8_t *)color_p, bufSize * 2);
    // appVar.lcd.flush(area->x1, area->y1, area->x2, area->y2, 0xff00);
    // _G_paBase.output("hello my_disp_flush\r\n");
    // for (y = area->y1; y <= area->y2; y++)
    // {
    //     for (x = area->x1; x <= area->x2; x++)
    //     {
    //         set_pixel(x, y, *color_p);
    //         color_p++;
    //     }
    // }

    lv_disp_flush_ready(disp); /* Indicate you are ready with the flushing*/
}
void my_log_cb(const char *buf)
{
    //   serial_send(buf, strlen(buf));
    _G_paBase.output(buf);
}

lv_disp_drv_t disp_drv;
void lv_app_init()
{
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[MY_DISP_HOR_RES * MY_DISP_VER_RES / 10]; /*Declare a buffer for 1/10 screen size*/
    // sizeof(buf1);
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, MY_DISP_HOR_RES * MY_DISP_VER_RES / 10); /*Initialize the display buffer.*/

    // static      /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);         /*Basic initialization*/
    disp_drv.flush_cb = palv_disp_flush; /*Set your driver function*/
    disp_drv.draw_buf = &draw_buf;       /*Assign the buffer to the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES;  /*Set the horizontal resolution of the display*/
    disp_drv.hor_res = MY_DISP_VER_RES;  /*Set the verizontal resolution of the display*/
    lv_disp_drv_register(&disp_drv);     /*Finally register the driver*/
    lv_log_register_print_cb(my_log_cb);
}
///////////////////////////////////////////////////////////////////////
static void anim_x_cb(void *var, int32_t v)
{
    lv_obj_set_x((lv_obj_t *)var, v);
}

static void anim_size_cb(void *var, int32_t v)
{
    lv_obj_set_size((lv_obj_t *)var, v, v);
}

/**
 * Create a playback animation
 */
void lv_example_anim_2(void)
{

    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);

    lv_obj_align(obj, LV_ALIGN_LEFT_MID, 10, 0);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 10, 50);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_playback_time(&a, 300);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);

    lv_anim_set_exec_cb(&a, anim_size_cb);
    lv_anim_start(&a);
    lv_anim_set_exec_cb(&a, anim_x_cb);
    lv_anim_set_values(&a, 10, 240);
    lv_anim_start(&a);
}
///////////////////////////////////////////////////////////////////////
void mainAppEntry()
{

    // app.robotArm.init();

    // app.talk.init();
    // Talk::init();
    // _G_paIIC.init(0);
    _G_paSPI.init(0);
    _G_paBase.delayMs(10);
    appVar.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);

    // _G_paGPIO.init(N_paGPIO::Mode_Output, RobotArm_GPIO_En0);
    // _G_paGPIO.write(RobotArm_GPIO_En0, 0);
    _G_paTimer.initWithCallBack(100, timerCall_100us);
    lv_init();
    lv_app_init();
    lv_example_anim_2();
    int helloCnt = 0;
    while (1)
    {
        // appVar.lcd.flush(0, 0, 200, 200, 0x00ff);
        // _G_paBase.output("hello world1\r\n");
        _G_paBase.delayMs(1);
        lv_tick_inc(1);
        // _G_paBase.output("hello world2\r\n");
        lv_timer_handler();
        // _G_paBase.output("hello world3\r\n");
        // appVar.lcd.flush(0, 0, 200, 200, 0xff00);
        // _G_paBase.delayMs(1);
        // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}