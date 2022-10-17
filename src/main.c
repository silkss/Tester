#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <conio.h>

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

    Price* fr_ema = calc_ema(bars, 30);
    if (fr_ema == NULL)
    {
        goto exit;
    }

    printf("Config:\n\tfile-path: %s\n", config->file_path);
    for (int i = 25; i < 40; i++)
    {
        printf("bar[%d]: C:%f\tEMA:%f\n", i,
            bars->Items[i].Close, 
            fr_ema[i]);
    }

    getch();

    exit:
    if (config) free(config);
    if (bars)
    {
        if (bars->Items)
            free(bars->Items);
        free(bars);
    }
    if (fr_ema)
    {
        free(fr_ema);
    }
    _CrtDumpMemoryLeaks();
    return 0;
}