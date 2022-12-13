#ifdef APP_MILL

#include "usr/mill/cmd/cmd_mill.h"
#include "sys/commands.h"
#include "sys/debug.h"
#include "sys/defines.h"
#include "sys/util.h"
#include "usr/mill/task_mill.h"
//#include "usr/mill/task_mill.c"
#include <stdlib.h>
#include <string.h>
#include "usr/mill/autogen/PMSMController.h"

// Stores command entry for command system module
static command_entry_t cmd_entry;

// Defines help content displayed for this command
// when user types "help" at command prompt
static command_help_t cmd_help[] = {
    { "hello <name>", "Print hello to screen" },
    { "init", "Start task" },
    { "Speed", "Set speed reference [RPM]" },
	{ "id", "Set d axis-current ref [A]"}
};

void cmd_mill_register(void)
{
    // Populate the command entry block
    //
    // Here is where you define the base command string: "mill"
    // and what function is called to handle command
    commands_cmd_init(&cmd_entry, "mill", "Mill test application commands", cmd_help, ARRAY_SIZE(cmd_help), cmd_mill);

    // Register the command with the system
    commands_cmd_register(&cmd_entry);
}

int cmd_mill(int argc, char **argv)
{
    // This function is called every time the user types "mill"
    // followed by a space and any number of characters.
    //
    // Example user input: mill foo 123
    //
    // It is up to the application developer to handle this
    // incoming command in a manner that reflects this command's
    // help message, as to not confuse the user.
    //
    // The arguments passed into this function (argc & argv)
    // follow standard C convention for main() programs called
    // via command line interface (CLI).
    //
    // 'argc' is the number of CLI arguments, including the base command
    // For above example: argc = 3
    //
    // 'argv' is an array of char strings which contain the CLI arguments
    // For above example:
    // - argv[0] => "mill"
    // - argv[1] => "foo"
    // - argv[2] => "123"
    //
    // NOTE: The system constrains user CLI input to ensure responsive
    // behavior for arbitrary commands. This involves limiting individual
    // command argument length as well as the total number of arguments
    // (this is defined in sys/commands.c)

    // Handle 'hello' sub-command
    //
    // First, verify correct number of arguments (2)
    // Second, verify second argument is "hello"
    if (argc == 3 && strcmp("hello", argv[1]) == 0) {
        // Perform desired action for command...

        // Fun example: hello message based on name
        if (strcmp("Nishanth", argv[2]) == 0) {
            // Wow, happy to talk to Nathan!
            debug_printf("Nishanth, your Mill test code works!!!\r\n");
            debug_print("\r\n");

            // Indicate success, but hide SUCCESS message
            return CMD_SUCCESS_QUIET;

        } else if (strcmp("fred", argv[2]) == 0) {
            // We don't want to talk to Fred... :(
            // Treat this case as an invalid command input from user
            return CMD_INVALID_ARGUMENTS;

        } else {
            // Normal hello for anyone else
            debug_printf("Hello, %s\r\n", argv[2]);
            debug_print("\r\n");

            // Indicate success, but hide SUCCESS message
            return CMD_SUCCESS_QUIET;
        }

        // If user typed a valid command, return SUCCESS
        return CMD_SUCCESS;
    }

    if (argc == 2 && strcmp("init", argv[1]) == 0) {
        if (task_mill_init() != SUCCESS) {
            return CMD_FAILURE;
        }

        return CMD_SUCCESS;
    }

    if (argc == 3 && strcmp("id", argv[1]) == 0){
		double id = strtod(argv[2], NULL);

		if (id > IdLim|| id < -IdLim){
			debug_printf("Value too high\n");
			return CMD_INVALID_ARGUMENTS;
		}

		PMSMController_U.Id_ref = id;

		return CMD_SUCCESS;
	}

	if (argc == 3 && strcmp("Speed", argv[1]) == 0){
		double omega_ref = strtod(argv[2], NULL);

		if (omega_ref > omega_max || omega_ref < -omega_max){
			debug_printf("Speed too high\n");
			return CMD_INVALID_ARGUMENTS;
		}

		PMSMController_U.omega_ref  = omega_ref*2*PI/60;

		return CMD_SUCCESS;
	}


    // At any point, if an error is detected in given input command,
    // simply return an error code (defined in sys/defines.h)
    //
    // The return statement below is used to catch all user input which
    // didn't match the if statements above. In general, to handle commands,
    // assume they are invalid. Only after checking if each argument is
    // valid should you trust them.
    //
    // Common error return values are: FAILURE, INVALID_ARGUMENTS
    return CMD_INVALID_ARGUMENTS;
}

#endif // APP_MILL
