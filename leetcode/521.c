//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-20.
//

#include <string.h>

int findLUSlength(char* a, char* b) {
    if (strcmp(a, b) != 0) {
        int al = strlen(a);
        int bl = strlen(b);
        return al > bl ? al : bl;
    }
    return -1;
}