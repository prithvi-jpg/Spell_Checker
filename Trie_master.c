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

int main()
{

    // root is the dictionary trie
    struct trie_node *root = create_trie_node();

    FILE *fp;
    char buffer[100];
    fp = fopen("dictionary.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%s[^\n]", buffer);
        insert(root, buffer);
    }
    fclose(fp);

    printf("Dictionary trie has been created!\n");

    //reading input file and checking root
    fp = fopen("input.txt", "r");

    printf("The following words couldnt be found in the dictionary:\n");
    while (!feof(fp))
    {
        fscanf(fp, "%s[^\n]", buffer);
        if (!search_trie(root, buffer))
        {
            printf("%s\n", buffer);
        }
    }
    fclose(fp);

    printf("End of Program! Exiting ..\n");
    return 0;
}