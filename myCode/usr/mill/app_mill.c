#ifdef APP_MILL

#include "usr/mill/app_mill.h"
#include "usr/mill/cmd/cmd_mill.h"
#include "usr/mill/task_mill.h"
#include "drv/gpio_mux.h"

void app_mill_init(void)
{
    // Register "mill" command with system
    cmd_mill_register();

    // Initialize mill task with system
    task_mill_init();


    // Set up GPIO mux for the AMDS board
    // 0 means top AMDC port
    // GPIO_MUX_DEVICE2 means which mux I/O in the fpga that the AMDS driver is hooked up to.
    gpio_mux_set_device(0, GPIO_MUX_DEVICE2);

}

#endif // APP_MILL
