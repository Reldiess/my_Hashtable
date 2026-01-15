//
// Created by Jonas Seidler on 15.01.26.
//

#include "my_Strings.h"

// Custom implementation of memcpy
void *my_strcpy(void *dest, const void *src)
{
    // Cast pointers to unsigned char* to perform byte-wise arithmetic
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    int i = 0;
    while (s[i] != '\0') {
        d[i] = s[i];
        i++;
    }
    return dest;
}

bool my_strcomp(char *value1, char *value2)
{
    if (sizeof(&value1) != sizeof(&value2))
        return false;

    while (*value1)
    {
        if (*value1++ != *value2++)
            return false;
    }
    return true;
}