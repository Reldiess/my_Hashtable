#include <stdio.h>
#include "hashtable.h"

int main(void) {
    hash_Put("Alice Smith", "+44 20 7946 0958");
    hash_Put("Jean Dupont", "+33 1 42 68 53 00");
    hash_Put("Hans Müller", "+49 30 12345678");
    hash_Put("Giulia Rossi", "+39 06 6982 3411");
    hash_Put("Mateo García", "+34 912 34 56 78");
    hash_Put("Lars Jensen", "+45 35 32 06 00");
    hash_Put("Sofia Novak", "+420 224 111 111");
    hash_Put("Elena Popescu", "+40 21 318 3000");
    hash_Put("Sven Larsson", "+46 8 123 45 67");
    hash_Put("Isabelle Dubois", "+32 2 501 18 11");

    printf("%s\n", hash_GetValue("Lars Jensen"));
    return 0;
}