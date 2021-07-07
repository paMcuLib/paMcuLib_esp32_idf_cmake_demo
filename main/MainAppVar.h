#ifndef __MAINAPPVAR_H__
#define __MAINAPPVAR_H__
#include "paMods/display/ILI9341/pa_ILI9341.h"

#include "DemoConfig"
// #include "RobotArm/RobotArmApp/RobotArmApp.h"
struct AppVar
{
#if Demo_ILI9341
    pa_ILI9341 lcd;
#endif
    // RobotArmApp robotArm;
    // Talk talk;
};

extern AppVar app;

#endif // __MAINAPPVAR_H__