#ifndef CMD_ENCODERTEST_H
#define CMD_ENCODERTEST_H

// Called in app init function to register command with system
void cmd_encoderTest_register(void);

// Function called when user types "encoderTest" command into command prompt
// i.e., this is the encoderTest command handler function
int cmd_encoderTest(int argc, char **argv);

#endif // CMD_ENCODERTEST_H
