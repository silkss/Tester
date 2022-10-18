#ifndef TESTER_TRADER_INCLUDE
#define TESTER_TRADER_INCLUDE

#define MIN_BARS 100

enum TraderStatus
{
    NeedToOpenLong,
    Long,
    NeedToOpenShort,
    Short,
    Flat
};

typedef struct
{
    enum TraderStatus Status;
    int Position;
    Price PnL;
    int NumberOfShorts;
    int NumberOFLongs;
} Trader;

#endif /* TESTER_TRADER_INCLUDE */
