#ifndef BARS_H_INCLUDE
#define BARS_H_INCLUDE

typedef double Price;

typedef struct 
{
    Price Open;
    Price High;
    Price Low;
    Price Close;
    int Volume;
} Bar;

typedef struct
{
    Bar* Items;
    int Length;
} Bars;

Bars* read_from_file(const char* file_path);

#endif /*BARS_H_INCLUDE*/