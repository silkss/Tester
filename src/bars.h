#ifndef BARS_H_INCLUDE
#define BARS_H_INCLUDE

typedef double Price;

typedef struct {
    Price Open;
    Price High;
    Price Low;
    Price Close;
    int Volume;
} Bar;

typedef struct {
    Bar* Items;
    int Length;
} ListofBars;

ListofBars* ReadBarsFromFile(char* filePath);

#endif /*BARS_H_INCLUDE*/