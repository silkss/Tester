#ifndef CONFIG_H_INCLUDE
#define CONFIG_H_INCLUDE

typedef struct {
    char* DataPath;
} Config;

Config* BuildConfigFromArgs(int argc, char* argv[]);

#endif /*CONFIG_H_INCLUDE*/