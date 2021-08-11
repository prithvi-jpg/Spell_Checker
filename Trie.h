typedef struct trie_node trie_node;

struct trie_node *create_trie_node();
void insert(struct trie_node *, const char *);
bool search_trie(struct trie_node *, const char *);