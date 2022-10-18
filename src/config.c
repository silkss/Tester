#include <stdlib.h>
#include <stdio.h>

#include "Config.h"

Config* BuildConfigFromArgs(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Not enough arguments!\n");
        return NULL;
    }
    Config* config = malloc(sizeof(Config));
    if (config)
    {
        config->DataPath = argv[1];
        return config;
    }
    else 
    {
        printf("Something wrong with memmory allocation for \"config\"");
        return NULL;
    }
}