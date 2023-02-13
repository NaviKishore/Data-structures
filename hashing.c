#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define NOT_FOUND -1

int hash(int key) {
    return key % TABLE_SIZE;
}
int probe(int h) {
    return (h + 1) % TABLE_SIZE;
}
int search(int key, int *table) {
    int h = hash(key);
    int i = 0;
    while (table[h] != NOT_FOUND && i < TABLE_SIZE) {
        if (table[h] == key) return h;
        h = probe(h);
        i++;
    }
    return NOT_FOUND;
    
}
void insert(int key, int *table) {
    int h = hash(key);
    int i = 0;
    while (table[h] != NOT_FOUND && i < TABLE_SIZE) {
        h = probe(h);
        i++;
    }
    table[h] = key;
}
int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
	 {
        table[i] = NOT_FOUND;
    }
    insert(10, table);
    insert(22, table);
    insert(31, table);
    insert(4, table);
    insert(15, table);
    insert(28, table);
    insert(17, table);
    insert(88, table);
    insert(59, table);
    printf("%d\n", search(31, table));
    printf("%d\n", search(17, table));
    printf("%d\n", search(59, table));
    printf("%d\n", search(100, table));

    return 0;
}
