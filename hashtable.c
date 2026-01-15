#include "hashtable.h"
#pragma region Variables
static u_int32_t size = 0;
#define constTableLength 100
const u_int32_t constStringLenght = 100;
#pragma endregion
#pragma region Structs
typedef struct
{
    char key[100];
    char value[100];
} KeyValuePair;
typedef struct Node
{
    KeyValuePair keyValuePair;
    struct Node *nextNode;
} Node;
#pragma endregion
static Node hashtable[constTableLength];
#pragma region Internal Methods
// Simple DBJ2 Hashfunction
static u_int32_t HashDBJ2(char *str)
{
    u_int32_t hash = 5381; // Seed
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
static u_int32_t GetIndex(char *str)
{
    return HashDBJ2(str) % constTableLength - 1;
}
/// @brief Traverses the nodes untill the Value is found or we have reached the end
/// @param key
/// @param Node
/// @return Value if found, else NULL
static char *GetNextValueRecursively(char *key, Node *node)
{
    if (my_strcomp(key, node->keyValuePair.key))
        return node->keyValuePair.value;
    else if (node->nextNode == NULL)
        return NULL;

    return GetNextValueRecursively(key, node->nextNode);
}
static void Put(char *key, char *value, Node *node)
{
    my_memcpy(node->keyValuePair.key, key, 100);
    my_memcpy(node->keyValuePair.value, value, 100);
}
/// @brief Traverses the nodes untill the next node is empty, Puts a new Node there
/// @param key
/// @param value
/// @param node
static void PutOnNextFreeNodeRecursively(char *key, char *value, Node *node)
{
    if (node->nextNode == NULL)
    {
        node->nextNode = malloc(sizeof(Node));
        Put(key, value, node->nextNode);
        return;
    }
    return PutOnNextFreeNodeRecursively(key, value, node->nextNode);
}
/// @brief Copys the KeyValuePair into the node
/// @param key
/// @param value
/// @param node

#pragma endregion
#pragma region External Functions
/// @brief Adds the Key Value Pair to the Hashtable, collisions are handelt with Linked lists and dupplicate keys OVERWRITE the value
/// @param key
/// @param value
void hash_Put(char *key, char *value)
{
    u_int32_t index = GetIndex(key);

    if (my_strcomp(hashtable[index].keyValuePair.key, ""))
    {
        my_memcpy(hashtable[index].keyValuePair.key, key, constStringLenght);
        my_memcpy(hashtable[index].keyValuePair.value, value, constStringLenght);
    }
    else
    {
        PutOnNextFreeNodeRecursively(key, value, &hashtable[index]);
    }

    size++;
    return;
};
/// @brief Searches the Value with the Key, returns null if not found
/// @param key
/// @return Value if found else NULL
char *hash_GetValue(char *key)
{
    u_int32_t index = GetIndex(key);

    if (my_strcomp(hashtable[index].keyValuePair.key, "")) // TODO test if empty or null prt
        return NULL;
    else if (my_strcomp(hashtable[index].keyValuePair.key, key))
        return hashtable[index].keyValuePair.value;

    return GetNextValueRecursively(key, hashtable[index].nextNode);
};

void hash_RemoveKeyValuePair(char *key)
{
    // TODO
    size--;
    return;
};

u_int32_t hash_GetSize(void)
{
    return size;
};
#pragma endregion