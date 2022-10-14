#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Price;

typedef struct 
{
    char* file_path;
} Config;

typedef struct
{
    Price open;
    Price high;
    Price low;
    Price close;
    int volume;
} Bar;

void errAndExit(char* err)
{
    printf("ERROR:\n\t%s", err);
    exit(-1);
}

Config parseArgsToConfig(int argc, char* argv[])
{
    if (argc == 1)
        errAndExit("Not enough args!!");

    Config config = { "D:\\data\\1.txt" };
    printf("Reading argumets...\n");
    for (int i = 1; i < argc; i++)
    {
        if (strcmp( argv[i],"-f") == 0 || strcmp(argv[i], "--file") == 0)
        {
            if (argv[i + 1] == NULL)
                errAndExit("Can`t read file path!!");
            else
            {
                config.file_path = argv[i + 1];
            }
        }
    }
    printf("File path readed. %s\n", config.file_path);
    return config;
}

int countLines(FILE* f)
{
    printf("Counting lines in file..");
    if (f == NULL)
    {
        errAndExit("Can`t read file.");
    }

    int count = 0; char c;
    for (c = getc(f); c != EOF; c = getc(f)){
        if (c == '\n') 
            count = count + 1;
    }
    printf("Counting is ended. Lines in file: %d\n", count);
    fseek(f, 0L, SEEK_SET);
    return count;
}

Bar* readAndParseFile(char* file_path, int * number_of_lines)
{
    FILE* f = fopen(file_path, "r");
    if (f != NULL)
    {
        char buffer[100];
        Bar* bars;
        *number_of_lines = countLines(f);

        bars = malloc(sizeof(Bar) * (*number_of_lines));
        
        printf("Parsing file..\n");
        
        int current_line = 0;
        while (fgets(buffer, 100, f) != NULL)
        {
            if (current_line > (*number_of_lines)) break;
            char * column = strtok(buffer, " ,");
            int pos = 0; /* 0 - Date; 1 - Time; 2 - Open; 3 - Hith; 4 - Low; 5 - Close; 6 - Volume*/
            while (column != NULL)
            {
                // printf("%d:\t%s\n", pos, column);
                if (pos == 2)
                {
                    bars[current_line].open = atof(column);
                }
                if (pos == 3)
                {
                    bars[current_line].high = atof(column);
                }
                if (pos == 4)
                {
                    bars[current_line].low = atof(column);
                }
                if (pos == 5){
                    bars[current_line].close = atof(column);
                }
                if (pos == 6){
                    bars[current_line].volume = atoi(column);
                }
                column = strtok(NULL, " ,");
                pos++;
            }
            current_line++;
        }
        
        fclose(f);
        return bars;
    }
    else
    {
        errAndExit("Can`t open file");
        return NULL;
    }
}
int main(int argc, char* argv[])
{
    Config config = parseArgsToConfig(argc, argv);
    printf("Trying to open file \"%s\"..\n", config.file_path);
    int array_size = 0;
    Bar* bars = readAndParseFile(config.file_path, &array_size);
    for (int i = 10; i < 20; i++)
    {
        printf("bar[%d]: O:%f\tH:%f\tL:%f\tC:%f\tV:%d\n", i, bars[i].open, bars[i].high, bars[i].low, bars[i].close, bars[i].volume);
    }
    free(bars);
    return 0;
}