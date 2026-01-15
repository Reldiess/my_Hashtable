#include <stdio.h>
#include "hashtable.h"

int main(void) {
    hash_Put("Test1", "Bdhawhdoawdawdaw");
    hash_Put("Test2", "gdrfsaefwe");

    printf("%s", hash_GetValue("Test1"));

    printf("/n%s", hash_GetValue("Test2"));

    return 0;
}