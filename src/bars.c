#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bars.h"

static int get_file_length(FILE * f)
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
static void parse_bar(char* str, Bar* bar)
{
    char * column = strtok(str, " ,");
    int column_number = 0; /* 0 - Date; 1 - Time; 2 - Open; 3 - Hith; 4 - Low; 5 - Close; 6 - Volume*/
    while (column != NULL)
    {
        // printf("%d:\t%s\n", pos, column);
        if (column_number == 2)
        {
            bar->Open = atof(column);
        } 
        else if (column_number == 3)
        {
            bar->High = atof(column);
        }
        else if (column_number == 4)
        {
            bar->Low = atof(column);
        }
        else if (column_number == 5)
        {
            bar->Close = atof(column);
        }
        else if (column_number == 6){
            bar->Volume = atoi(column);
        }
        column = strtok(NULL, " ,");
        column_number++;
    }
}
Bars* read_from_file(char* file_path)
{
    printf("Opening file %s\n", file_path);
    FILE* f = fopen(file_path, "r");
    if (f == NULL) return NULL;
    int length = get_file_length(f);
    Bar* items = malloc(sizeof(Bar) * length);
    Bars* bars = malloc(sizeof(Bars));
    if (bars) {
        bars->Items = items;
        bars->Length = length;
    } else {
        printf("Something wrong with memory allocation\n");
        return NULL;
    }

    char buffer[100]; int current_line = 0;
    if (bars->Items) {
        retru
    }
    while (fgets(buffer, 100, f) != NULL)
    {
        if (current_line > (bars->Length)) break;
        parse_bar(buffer, &bars->Items[current_line]);
        current_line++;
    }
    fclose(f);
    return bars;
}
