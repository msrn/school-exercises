#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define  HASHTABLE_SIZE 2000000

/*
 * Node struct
 * Contains key array, value and pointer to next node
 */
typedef struct Node {
    char *key;
    unsigned int value;
    struct Node *next;
} Node;

/*
 * Hashtable implementation
 * Contains table size and array Node's
 */
typedef struct HashTable {
    long size;
    Node **items;
} HashTable;

unsigned int totalWords = 0; //Global variable for total words found in file
unsigned int uniqueWords = 0; //Global variable for unique words found in file

HashTable* createHashTable(unsigned long);

void readFile(HashTable* table, FILE *f);

unsigned long hash(char *key, unsigned long size);
void insertWord(HashTable* table, char* key);
int searchWord(HashTable* table, char* key);

Node** sort(HashTable *table);
int compareWords(const void *elem1, const void *elem2);


int main(int argc, char** argv) {

    clock_t startTime, endTime;
    FILE* file;

    if ((argc < 2) || (argc > 2)) {
        printf("No input file given\n");
        printf("Usage: ./a.out [FILE] Eg: ./a.out big.txt\n");
        return 0;
    }
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Given file doesn't exist");
        return 0;
    }

    startTime = clock(); //Start counting execution time
    HashTable* hashTable;
    hashTable = createHashTable(HASHTABLE_SIZE);

    readFile(hashTable, file);

    fclose(file);

    printf("Total Words: %d \n", totalWords);
    printf("Unique Words: %d \n", uniqueWords);

    //Node array of sorted hashtable
    Node** list = sort(hashTable);;


    printf("TOP 100 UNIQUE WORDS \n");
    printf("WORD \t\t VALUE \n");
    for (int i = 0; i < 100; i++) {
            printf("%s \t\t %d \n", list[i]->key, list[i]->value);//}
    }
    endTime = clock();
    printf("\nExecution time: %.4f seconds \n", (double)(endTime - startTime)/CLOCKS_PER_SEC);

    free(list);
    free(hashTable);

    return 0;
}

/*
 * createHashTable function
 * Allocate memory for hashtable itself and HashTable items. Assign size paramater to Hashtable.
 * Initialize Hashtable items with empty values by using memset
 * @param unsigned long size
 * @return Hashtable* hashtable
 */
HashTable* createHashTable(unsigned long size) {
    HashTable *hashtable;

    hashtable = malloc(sizeof(HashTable));

    hashtable->items = malloc(sizeof(Node*) * size);

    hashtable->size = size;

    memset(hashtable->items, 0 , size);

    /*for (int i = 0; i < size; i++) {
        hashtable->items[i] = NULL;
    }*/

    return hashtable;
}

/*
 * readFile function.
 * Reads words from a file with fscanf and checks if it is alphabet and if it contains apostrophe
 * If isWord is true. Then proceed to insert word to a hashtable and increment wordCount by one (1);
 * @param Hashtable* table, FILE* f
 */

void readFile(HashTable* table, FILE* f) {

    int i, isWord;
    char word[100];
    char temp[100];

    //Initialize word char array with \0
    memset(word, 0, 100);

    while (!feof(f)) {
        isWord = 0;

        //empty temp char array to prevent accidental entries
        memset(temp, 0, 100);

        fscanf(f, "%s", temp);

        int j = 0;
        for (i = 0; i < strlen(temp); i++) {
            if ((isalpha(temp[i]) || (temp[i] == '\''))) {
                word[j] = tolower(temp[i]);
                j++;
            } else {
                isWord = 0;
            }
            isWord = 1;
        }

        if( (isWord == 1)) {
            word[j] = '\0';
            insertWord(table, word);
            totalWords++;
        }
    }
}
/* hash function
 * Traverse the whole word and multiply the hashValue with prime number.
 * Then addition with key's ascii and adding current i value to it.
 * Return hashValue with modulo of hashtable size
 * @param char *key, unsigned long size
 * @return hashValue % size *
 */

unsigned long hash(char *key, unsigned long size) {

    int i;
    unsigned long hashValue = 0;
    int length = strlen(key);

    for (i = 0; i < length; i++) {
        hashValue = (hashValue * 43) + (key[i] + i);
    }

    return hashValue % size;

}
/* insertWord function
 * First checks if there already is entry for given key with searchWord function.
 * If there is, then use previously calculated hashCode for finding current index for the key. Then increment said key's value by one.
 * We are using chaining to avoid collisions. So every new node next pointer gets assigned with current index.
 * If there is no existing key, then we make new one and assign to current position in our hashtable array. Also increment uniqueWords.
 * @param Hashtable* table, char* key
 */

void insertWord(HashTable* table, char* key) {

    Node *newNode;

    int hashCode = hash(key, HASHTABLE_SIZE);
    int returnValue = searchWord(table, key);

    if (returnValue == 1 && hashCode != 0) {
        newNode = table->items[hashCode];
        newNode->value = newNode->value + 1;
    } else if (returnValue == 0 && hashCode != 0) {
        newNode = malloc(sizeof(*newNode));

        newNode->key = strdup(key);

        newNode->value = 1;
        newNode->next = table->items[hashCode];
        table->items[hashCode] = newNode;
        uniqueWords++;


    }

    newNode = NULL;
    free(newNode);



}
/* searchWord function
 * Assign node for with generated hashCode to the node we are comparing to.
 * Traverse oldNode long as there is no match for key and check chained nodes as well.
 * If there is a match then return 1, otherwise return 0;
 * @param HashTable* table, char* key
 * return int
 */

int searchWord(HashTable* table, char* key) {

    Node *oldNode;
    int hashCode = hash(key, HASHTABLE_SIZE);

    oldNode = table->items[hashCode];
    while (oldNode != NULL) {
        if (strcmp(key, oldNode->key) == 0) {
            return 1;
        }
        oldNode = oldNode->next;
    }

    return 0;
}
/* Comparewords function
 * Function for qsort which compares two elements
 * @param const void *elem1, const void *elem2
 * return int
 */

int compareWords(const void *elem1, const void *elem2) {


    return (*(Node**)elem2)->value - (*(Node**)elem1)->value;

    /*
    Node* one = *( Node**) elem1;
    Node* two = *( Node**) elem2;

    if (one->value < two->value) {
        return 1;
    } else if (one->value > two->value) {
        return -1;
    }
    return 0;
    */

}
/*
 * Sort function
 * Allocate list with size of unique words. Traverse hashtable and store each node to list. Also check chained nodes.
 * Use qsort function to sort given list and then return it
 * @param HashTable* table
 * return Node** list
 */
Node** sort(HashTable* table) {

    Node** list = malloc((uniqueWords * sizeof(Node*)));
    int j = 0;
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        Node* temp = table->items[i];
        while (temp != NULL) {
            list[j] = temp;
            temp = temp->next;
            j++;
        }
    }

    qsort((void*)list, uniqueWords, sizeof(Node*), (int (*) (const void *, const void *)) compareWords);

    return list;

}




