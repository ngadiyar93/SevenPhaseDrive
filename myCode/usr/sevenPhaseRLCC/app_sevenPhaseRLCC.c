#ifdef APP_SEVENPHASERLCC

#include "usr/sevenPhaseRLCC/app_sevenPhaseRLCC.h"
#include "usr/sevenPhaseRLCC/cmd/cmd_sevenPhaseRLCC.h"
#include "usr/sevenPhaseRLCC/task_sevenPhaseRLCC.h"
#include "drv/gpio_mux.h"

void app_sevenPhaseRLCC_init(void)
{
    // Register "sevenPhaseRLCC" command with system
    cmd_sevenPhaseRLCC_register();

    // Initialize sevenPhaseRLCC task with system
    task_sevenPhaseRLCC_init();


    // Set up GPIO mux for the AMDS board
    // 0 means top AMDC port
    // GPIO_MUX_DEVICE2 means which mux I/O in the fpga that the AMDS driver is hooked up to.
    gpio_mux_set_device(0, GPIO_MUX_DEVICE2);

}

#endif // APP_SEVENPHASERLCC
