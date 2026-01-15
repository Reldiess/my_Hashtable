#include <stdio.h>
#include "hashtable.h"

int main(void) {
    hash_Put("Test1", "Bdhawhdoawdawdaw");
    hash_Put("Test2", "gdrfsaefwe");
    hash_Put("Test3", "dawddawdawd");
    hash_Put("Test4", "dawdwdawdaxcrgdrg");
    hash_Put("Test5", "dggrgdrg");
    hash_Put("Test6", "rdgrrdgd");
    hash_Put("Test7", "fadwdwad");

    printf("%s\n", hash_GetValue("Test1"));

    printf("%s\n", hash_GetValue("Test2"));

    return 0;
}