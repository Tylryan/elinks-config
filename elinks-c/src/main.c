#include <stdio.h>
#include <string.h>
#include <stdlib.h> // EXIT_SUCCESS/EXIT_FAILURE

#include "./functions.c"

#define TRUE 1
#define FALSE 0

/* 
 * This code is probably pretty easy to break
*/

// Pretty much never allowed to use constants.
char ALTERNATIVE_GUI_BROWSER[] = "otter-browser ";
char ELINKS_CONFIG_PATH[] = "-config-dir ~/.config/elinks ";

// #######################  MAIN #############################################
int main(int argc, char *argv[]){

    /* char * PROGRAM_NAME = argv[0]; */

    UserEntry user_entry = {
        // application_binary 25
        malloc(1 * sizeof(char)), 
        // elinks_config_path
        ELINKS_CONFIG_PATH, 
        // SearchEngine
        duck, 
        // base_search
        malloc(1 * sizeof(char)), 
        // search_terms 100
        malloc(1 * sizeof(char)), 
        // arg_num
        argc, 
        // args
        argv, 
        //  flag
        argv[1], 
        // has_flag
        0, 
        // use_gui
        0, 
        // final_url 100
        malloc(1 * sizeof(char)),
        ALTERNATIVE_GUI_BROWSER
    };

    int max_args = 20;
    if (user_entry.arg_num > max_args){
        printf("Error: Entry too big.\n");
        exit(EXIT_FAILURE);
    }

    // Don't miss this guy
    options_parser(&user_entry);

    int entered_no_args = (argc == 1)                   || 
        (argc == 2 && user_entry.search_engine != duck) ||
        (argc == 2 && user_entry.use_gui == TRUE);
    if (entered_no_args) {
        run_with_no_args(user_entry);
        exit(EXIT_SUCCESS);
    }


    // If there is a "." in arg1, it's probably a url
    int start_of_args = 1;
    if ( user_entry.has_flag ) 
        start_of_args = 2;
    char * first_argument = argv[start_of_args];
    int is_complete_url = contains_a_dot(first_argument, strlen(first_argument));
    
    if (is_complete_url){
        run_as_complete_url(user_entry, start_of_args);

        exit(EXIT_SUCCESS);
    }

    else {
        run_as_search_query(user_entry);

        exit(EXIT_SUCCESS);
        }

    }
