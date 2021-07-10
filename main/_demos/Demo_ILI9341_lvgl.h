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

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    // int32_t bufSize = (area->x2 - area->x1) * (area->y2 - area->y1);
    /*It's a very slow but simple implementation.
     *`set_pixel` needs to be written by you to a set pixel on the screen*/
    // appVar.lcd.setAddress(area->x1, area->y1, area->x2, area->y2);
    // appVar.lcd.transmitBuf((uint8_t *)color_p, bufSize * 2);
    _G_paBase.output("hello my_disp_flush\r\n");
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
void lv_app_init()
{
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[1]; /*Declare a buffer for 1/10 screen size*/
    // sizeof(buf1);
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, MY_DISP_HOR_RES * MY_DISP_VER_RES / 10); /*Initialize the display buffer.*/

    lv_disp_drv_t disp_drv;             /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);        /*Basic initialization*/
    disp_drv.flush_cb = my_disp_flush;  /*Set your driver function*/
    disp_drv.draw_buf = &draw_buf;      /*Assign the buffer to the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES; /*Set the horizontal resolution of the display*/
    disp_drv.hor_res = MY_DISP_VER_RES; /*Set the verizontal resolution of the display*/
    lv_disp_drv_register(&disp_drv);    /*Finally register the driver*/
}

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

    int helloCnt = 0;
    while (1)
    {
        // appVar.lcd.flush(0, 0, 200, 200, 0x00ff);
        _G_paBase.output("hello world\r\n");
        _G_paBase.delayMs(1);
        lv_tick_inc(1);
        lv_task_handler();
        // appVar.lcd.flush(0, 0, 200, 200, 0xff00);
        // _G_paBase.delayMs(2);
        // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}