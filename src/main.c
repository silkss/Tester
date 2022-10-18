#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <conio.h>

#include <stdio.h>
#include <string.h>

#include "Config.h"
#include "Bars.h"
#include "Tester.h"

#define FREE_POINTER(p) if (p) free(p)

Config*     config  = NULL;
ListofBars* bars    = NULL;

int main(int argc, char* argv[])
{
    config = BuildConfigFromArgs(argc, argv);
    if (config == NULL)
    {
        printf("Error while creating config!\n"); 
        goto exit;
    }
    bars = ReadBarsFromFile(config->DataPath);
    if (bars == NULL)
    {
        printf("Something wrong with reading file!\n");
        goto exit;
    }

    StartTest(bars);
    /*Price* long_ema = malloc(sizeof(Price) * bars->Length);
    if (long_ema == NULL)
    {
        printf("Can`t alloc memory for LONG_EMA array!\n");
        goto exit;
    }
    Price* short_ema = malloc(sizeof(Price) * bars->Length);
    if (short_ema == NULL)
    {
        printf("Can`t alloc memory for SHOR_EMA array!\n");
        goto exit;
    }*/

    //printf("Short#\t| Long#\t| Position\t| PnL\t Longs\t| Shorts\n");
    //for (int long_period = 5; long_period <= 50; long_period++)
    //{
    //    for (int short_period = 5; short_period <= 50; short_period++)
    //    {
    //        Trader trader = { Flat, 0, 0.0, 0, 0 };
    //        if (calc_ema(bars, long_ema, long_period) < 0)
    //        {
    //            printf("Something wrong with calculating LONG_EMA %d!\n", long_period);
    //            break;
    //        }
    //        if (calc_ema(bars, short_ema, short_period) < 0)
    //        {
    //            printf("Something wrong with calculating SHORT_EMA %d!\n", short_period);
    //            break;
    //        }
    //        for (int num_bar = MIN_BARS; num_bar < bars->Length; num_bar++)
    //        {
    //            if (trader.Status == NeedToOpenLong)
    //            {
    //                if (trader.Position != 1)
    //                {
    //                    trader.Position = 1;
    //                    trader.PnL = trader.PnL - bars->Items[num_bar].Open;
    //                    trader.NumberOFLongs++;
    //                }
    //            }
    //            else if (trader.Status == NeedToOpenShort)
    //            {
    //                if (trader.Position != -1)
    //                {
    //                    trader.Position = -1;
    //                    trader.PnL = trader.PnL + bars->Items[num_bar].Open;
    //                    trader.NumberOfShorts++;
    //                }
    //            }

    //            if (bars->Items[num_bar].Close > long_ema[num_bar])
    //            {
    //                /* need to buy */
    //                trader.Status = NeedToOpenLong;
    //            }
    //            else if (bars->Items[num_bar].Close < short_ema[num_bar])
    //            {
    //                /* need to sell */
    //                trader.Status = NeedToOpenShort;
    //            }
    //        }
    //        printf("%d\t| %d\t| %d\t| %f\t| %d\t| %d\n",
    //            short_period, long_period,
    //            trader.Position,
    //            trader.PnL,
    //            trader.NumberOFLongs,
    //            trader.NumberOfShorts);
    //    }
    //}
    //
    getch();

exit:
    FREE_POINTER(config);
    FREE_POINTER(bars);
    _CrtDumpMemoryLeaks();
    return 0;
}
