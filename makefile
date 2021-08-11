output: Trie_master.o Trie_functions.o
	gcc Trie_master.o Trie_functions.o -o output

Trie_master.o: Trie_master.c Trie.h
	gcc -c Trie_master.c

Trie_functions.o: Trie_functions.c Trie.h
	gcc -c Trie_functions.c

clean:
	rm *.o output