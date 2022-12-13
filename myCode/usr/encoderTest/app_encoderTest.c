#ifdef APP_ENCODERTEST

#include "usr/encoderTest/app_encoderTest.h"
#include "usr/encoderTest/cmd/cmd_encoderTest.h"
#include "usr/encoderTest/task_encoderTest.h"

void app_encoderTest_init(void)
{
    // Register "encoderTest" command with system
    cmd_encoderTest_register();

    // Initialize encoderTest task with system
    task_encoderTest_init();
}

#endif // APP_ENCODERTEST
