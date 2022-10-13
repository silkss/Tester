#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char* file_path;
} Config;
void errAndExit(char* err)
{
    printf("ERROR:\n\t%s", err);
    exit(-1);
}
Config parseArgsToConfig(int argc, char* argv[])
{
    if (argc == 1)
        errAndExit("Not enough args!!");

    Config config;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp( argv[i],"-f") == 0 || strcmp(argv[i], "--file") == 0)
        {
            config.file_path = argv[i + 1];
            if (config.file_path == NULL)
                errAndExit("Can`t read file path!!");
        }
    }
    return config;
}
int countLines(FILE* f)
{
    int count = 0; char c;
    for (c = getc(f); c != EOF; c = getc(f)){
        if (c == '\n') 
            count = count + 1;
    }
    fseek(f, 0L, SEEK_SET);
    return count;
}
void readAndParseFile(char* file_path)
{
    FILE* f = fopen(file_path, "r");
    if (f != NULL)
    {
        char buffer[100];
        int file_size = countLines(f);
        printf("File size is %d\n", file_size);
        while (fgets(buffer, 100, f) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(f);
    }
    else
    {
        errAndExit("Can`t open file");
    }
}
int main(int argc, char* argv[])
{
    Config config = parseArgsToConfig(argc, argv);
    printf("Trying to open file \"%s\"..\n", config.file_path);
    readAndParseFile(config.file_path);
    return 0;
}