// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int counter=0;
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int a = hash(word);
    node *cursor=table[a];
    while(cursor!=NULL){
        if(strcasecmp(cursor->word,word)==0){
            return true;
        }
        cursor=cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int a= word[0]-97;
    return a;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict=fopen(dictionaries/large,"r");
    if(dict==NULL){
        printf("Unable to read!\n");
        return false;
    }
    while(fscanf(dict,"%s",word)!=EOF)
    {
        node copyword=malloc(sizeof(node));
        if(copyword==NULL){
            return false;
        }
        copyword=strcpy(copyword->word , word);
        copyword->next=NULL;
        counter++;


    int hashno = hash(word);
    if(table[hashno]==NULL){
        table[hashno]=copyword;
    }
    else{
        copyword->next=table[hashno];
        table[hashno]=copyword;
    }

}
fclose(dict);
return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i=0;i<N;i++)
    {
        node *head=table[i];
        node *tmp=head;
        node *cursor=head;
        while( cursor!=NULL){
            cursor=cursor->next;
            free(tmp);
            tmp=cursor;
        }
    }
    if(cursor!=NULL){
        return false;
    }
    return true;
}
