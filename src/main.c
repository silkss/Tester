#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include <string.h>

#include "config.h"
#include "bars.h"

int main(int argc, char* argv[])
{
    Config* config = read_config_from_args(argc, argv);
    if (config == NULL)
    {
        printf("Error while creating config!\n"); 
        goto exit;
    }
    Bars* bars = read_from_file(config->file_path); 
    if (bars == NULL)
    {
        printf("Something wrong with reading file!\n");
        goto exit;
    }
    else 
    {
        printf("Config:\n\tfile-path: %s\n", config->file_path);
    }
    for (int i = 10; i < 20; i++)
    {
        printf("bar[%d]: O:%f\tH:%f\tL:%f\tC:%f\tV:%d\n", i,
            bars->Items[i].Open, 
            bars->Items[i].High, 
            bars->Items[i].Low, 
            bars->Items[i].Close, 
            bars->Items[i].Volume);
    }

    exit:
    //if (bars != NULL) fre(bars);
    if (config != NULL) free(config);
    if (bars != NULL)
    {
        if (bars->Items)
            free(bars->Items);
        free(bars);
    }
    _CrtDumpMemoryLeaks();
    return 0;
}