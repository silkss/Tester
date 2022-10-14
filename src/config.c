#include <stdlib.h>

#include "config.h"

Config* read_config_from_args(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Not enough arguments!\n");
        return NULL;
    }
    Config* config = malloc(sizeof(Config));
    if (config)
    {
        config->file_path = argv[1];
        return config;
    }
    else 
    {
        printf("Something wrong with memmory allocation for \"config\"");
        return NULL;
    }
}