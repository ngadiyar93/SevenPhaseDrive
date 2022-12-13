#include "usr/user_apps.h"

// Adding applications:
//
// To add a new application, create a block
// like the other example(s) below which
// conditionally includes the app's header file.
//
// Also, conditionally call the app's init function.

//#ifdef APP_PCBTEST
//#include "usr/pcbtest/app_pcbtest.h"
//#endif

#ifdef APP_SEVENPHASERLCC
#include "usr/sevenPhaseRLCC/app_sevenPhaseRLCC.h"
#endif

//#ifdef APP_BLINK
//#include "usr/blink/app_blink.h"
//#endif

//#ifdef APP_BETA_LABS
//#include "usr/beta_labs/app_beta_labs.h"
//#endif
//
//#ifdef APP_DEMO
//#include "usr/demo/app_demo.h"
//#endif
//
//#ifdef APP_DAC
//#include "usr/dac/app_dac.h"
//#endif

//#ifdef APP_RLCC
//#include "usr/rlCC/app_rlCC.h"
//#endif
//
//#ifdef APP_MILL
//#include "usr/mill/app_mill.h"
//#endif
//
//#ifdef APP_TEST
//#include "usr/test/app_test.h"
//#endif

//#ifdef APP_ENCODERTEST
//#include "usr/encoderTest/app_encoderTest.h"
//#endif

void user_apps_init(void)
{
//#ifdef APP_PCBTEST
//    app_pcbtest_init();
//#endif

#ifdef APP_SEVENPHASERLCC
    app_sevenPhaseRLCC_init();
#endif

//#ifdef APP_BLINK
//    app_blink_init();
//#endif

//#ifdef APP_BETA_LABS
//    app_beta_labs_init();
//#endif
//
//#ifdef APP_DEMO
//    app_demo_init();
//#endif
//
//#ifdef APP_DAC
//    app_dac_init();
//#endif

//#ifdef APP_RLCC
//    app_rlCC_init();
//#endif
//
//#ifdef APP_MILL
//    app_mill_init();
//#endif
//
//#ifdef APP_TEST
//    app_test_init();
//#endif

//#ifdef APP_ENCODERTEST
//     app_encoderTest_init();
//#endif


}
