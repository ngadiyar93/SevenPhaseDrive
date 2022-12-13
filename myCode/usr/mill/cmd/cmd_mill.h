#ifndef CMD_MILL_H
#define CMD_MILL_H

#define IdLim (50)
#define omega_max (1000)

// Called in app init function to register command with system
void cmd_mill_register(void);

// Function called when user types "mill" command into command prompt
// i.e., this is the mill command handler function
int cmd_mill(int argc, char **argv);

#endif // CMD_MILL_H
