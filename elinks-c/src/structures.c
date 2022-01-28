#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // EXIT_SUCCESS/EXIT_FAILURE
#include <sysexits.h>
#include <errno.h>

typedef enum { duck, google } SearchEngine;

typedef struct {
    char * application_binary;
    char * elinks_config_path;
    SearchEngine search_engine;
    char * base_search;
    char * search_terms;
    int arg_num;
    char ** args;
    char * flag;
    int has_flag;
    int use_gui;
    char * final_url;
} UserEntry;
