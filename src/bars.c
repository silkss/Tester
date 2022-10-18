#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bars.h"

static int getFileLength(FILE* f)
{
    printf("Counting lines in file\n");
    int length = 0; char c;
    for (c = getc(f); c != EOF; c = getc(f)){
        if (c == '\n') 
            length = length + 1;
    }
    fseek(f, 0L, SEEK_SET);
    printf("In file %d lines\n", length);
    return length;
}

static void parsingBars(char* str, Bar* bar)
{
    char * column = strtok(str, " ,");
    int colNumber = 0; /* 0 - Date; 1 - Time; 2 - Open; 3 - Hith; 4 - Low; 5 - Close; 6 - Volume*/
    while (column != NULL)
    {
        // printf("%d:\t%s\n", pos, column);
        if (colNumber == 2)
        {
            bar->Open = atof(column);
        } 
        else if (colNumber == 3)
        {
            bar->High = atof(column);
        }
        else if (colNumber == 4)
        {
            bar->Low = atof(column);
        }
        else if (colNumber == 5)
        {
            bar->Close = atof(column);
        }
        else if (colNumber == 6){
            bar->Volume = atoi(column);
        }
        column = strtok(NULL, " ,");
        colNumber++;
    }
}
ListofBars* ReadBarsFromFile(char* filePath)
{
    printf("Opening file %s\n", filePath);
    FILE* f = fopen(filePath, "r");
    if (f == NULL) return NULL;
    int length = getFileLength(f);
    Bar* items = malloc(sizeof(Bar) * length);
    ListofBars* bars = malloc(sizeof(ListofBars));
    if (bars) {
        bars->Items = items;
        bars->Length = length;
    } else {
        printf("Something wrong with memory allocation\n");
        return NULL;
    }

    char buffer[100]; int currentLine = 0;
    while (fgets(buffer, 100, f) != NULL)
    {
        if (currentLine > (bars->Length)) break;
        parsingBars(buffer, &bars->Items[currentLine]);
        currentLine++;
    }
    fclose(f);
    return bars;
}