#ifndef CMD_SEVENPHASERLCC_H
#define CMD_SEVENPHASERLCC_H

#define IdLim (5)
#define IqLim (5)

// Called in app init function to register command with system
void cmd_sevenPhaseRLCC_register(void);

// Function called when user types "sevenPhaseRLCC" command into command prompt
// i.e., this is the sevenPhaseRLCC command handler function
int cmd_sevenPhaseRLCC(int argc, char **argv);

#endif // CMD_SEVENPHASERLCC_H
