#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Trie.h"

#define array_size(a) sizeof(a) / sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define get_index(c) ((int)c - (int)'a')

struct trie_node
{
    struct trie_node *arr[ALPHABET_SIZE];

    // end_of_word is true if the node represents
    // end of a word
    bool end_of_word;
};

typedef struct trie_node trie_node;

struct trie_node *create_trie_node()
{
    struct trie_node *temp = NULL;

    temp = (struct trie_node *)malloc(sizeof(struct trie_node));

    if (temp)
    {
        int i;

        temp->end_of_word = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            temp->arr[i] = NULL;
    }

    return temp;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct trie_node *root, const char *key)
{
    int l;
    int len = strlen(key);
    int index;

    struct trie_node *p = root;

    for (l = 0; l < len; l++)
    {
        index = get_index(key[l]);
        if (!p->arr[index])
            p->arr[index] = create_trie_node();

        p = p->arr[index];
    }

    // mark last node as leaf
    p->end_of_word = true;
}

// Returns true if key presents in trie, else false
bool search_trie(struct trie_node *root, const char *key)
{
    int l;
    int len = strlen(key);
    int index;
    struct trie_node *p = root;

    for (l = 0; l < len; l++)
    {
        index = get_index(key[l]);

        if (!p->arr[index])
            return false;

        p = p->arr[index];
    }

    return (p != NULL && p->end_of_word);
}
