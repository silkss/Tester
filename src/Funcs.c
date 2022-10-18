#include "Funcs.h"

Price* EMA(ListofBars* bars, int period)
{
    int real_period = period - 1; 
    if (real_period > bars->Length)
    {
        printf("Not enough bars!\n");
        return NULL;
    }

    Price* values = malloc(sizeof(Price) * bars->Length);
    if (values == NULL)
    {
        printf("Can`t alloc memory for \"Value\"\n");
        return NULL;
    }

    Price temp = 0.0;
    for (int i = 0; i < real_period; i++)
    {
        values[i] = 0;
    }
    for (int i = real_period; i < bars->Length; i++)
    {
        temp = 0.0;
        for (int j = (i - real_period); j <= i; j++)
        {
            temp = temp + bars->Items[j].Close;
        }
        values[i] = temp / period;
    }

    return values;
}