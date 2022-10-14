#ifndef CONFIG_H_INCLUDE
#define CONFIG_H_INCLUDE

typedef struct 
{
    char* file_path;
} Config;

Config* read_config_from_args(int argc, char* argv[]);

#endif /*CONFIG_H_INCLUDE*/