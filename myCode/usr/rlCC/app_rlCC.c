#ifdef APP_RLCC

#include "usr/rlCC/app_rlCC.h"
#include "usr/rlCC/cmd/cmd_rlCC.h"
#include "usr/rlCC/task_rlCC.h"
#include "drv/gpio_mux.h"

void app_rlCC_init(void)
{
    // Register "rlCC" command with system
    cmd_rlCC_register();

    // Initialize rlCC task with system
    task_rlCC_init();


    // Set up GPIO mux for the AMDS board
    // 0 means top AMDC port
    // GPIO_MUX_DEVICE2 means which mux I/O in the fpga that the AMDS driver is hooked up to.
    gpio_mux_set_device(0, GPIO_MUX_DEVICE2);

}

#endif // APP_RLCC
