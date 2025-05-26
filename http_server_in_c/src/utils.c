#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *extract_path(const char *request_line) {
    char method[8], path[1024], version[16];
    sscanf(request_line, "%s %s %s", method, path, version);

    char *clean_path = malloc(strlen(path) + 1);
    if (clean_path) {
        strcpy(clean_path, path);
    }

    return clean_path;
}