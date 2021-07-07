#include "MainApp.c.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
#include "paCoreInc/all"
#include "paMods/display/SSD1306/pa_oled.h"
// #include "paCoreHead/paIIC.h"
// #include "paCoreHead/paBase.h"
// #include "paCoreHead/paSPI.h"
// #include "paCoreHead/paBase.h"

#include "Talk.h"
#include "MainAppVar.h"

#include "DemoConfig"
AppVar appVar;
void timerCall_100us()
{
    // app.robotArm.onTimerTick();
}
void mainAppEntry()
{

// app.robotArm.init();

// app.talk.init();
// Talk::init();
// _G_paIIC.init(0);
#if Demo_ILI9341
    _G_paSPI.init(0);
    appVar.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);
#endif

    // _G_paGPIO.init(N_paGPIO::Mode_Output, RobotArm_GPIO_En0);
    // _G_paGPIO.write(RobotArm_GPIO_En0, 0);
    _G_paTimer.initWithCallBack(100, timerCall_100us);

    int helloCnt = 0;
    while (1)
    {

        _G_paBase.delayMs(2);
        // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}