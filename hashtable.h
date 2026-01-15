//
// Created by Jonas Seidler on 15.01.26.
//

#ifndef MY_HASHTABLE_HASHTABLE_H
#define MY_HASHTABLE_HASHTABLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_Strings.h"

/// @brief Adds the Key Value Pair to the Hashtable, collisions are handelt with Linked lists and dupplicate keys are OVERWRITEN
/// @param key
/// @param value
void hash_Put(char *key, char *value);

/// @brief Searches the Value with the Key, returns null if not found
/// @param key
/// @return Value
char *hash_GetValue(char *key);

void hash_RemoveKeyValuePair(char *key);


u_int32_t hash_GetSize(void);

#endif //MY_HASHTABLE_HASHTABLE_H