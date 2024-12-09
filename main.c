#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


// STRUCTS AND STUFF
typedef struct{
	char* key;
	char* value;
}ht_item;
typedef struct{
	int size;
	int count;// Number of elements in the hash table 
	ht_item** items;
}ht_hash_table;


static ht_item HT_DELETED_ITEM = {NULL, NULL};
static int HT_PRIME_1 = 7;
static int HT_PRIME_2 = 13;


//MANAGING THE HASHTABLE AND THE ITEMS !!!INSIDE THE HASHTABLE STRUCT NO ht_hash
ht_item* ht_new_item(const char* k, const char* v){
	ht_item* i = malloc(sizeof(ht_item));
	i->key = strdup(k);
	i->value= strdup(v);
	return i;
}
ht_hash_table* ht_new(){
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));
	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size,sizeof(ht_item));
	return ht;
}
void ht_del_item(ht_item* i){
	free(i->key);
	free(i->value);
	free(i);
}

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}
//ht_hash
static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}
//Managing Collisions by adding a hash fouk el hash
static int ht_get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}
// METHODS USED BY THE HASH TABLE
void ht_insert(ht_hash_table* ht, const char* key , const char* value){
	ht_item* item = ht_new_item(key, value);
	int index = ht_get_hash(item->key, ht->size, 0);
	ht_item* currentItem = ht->items[index];
	int i = 1;
	while(currentItem != NULL && currentItem != &HT_DELETED_ITEM){
		if(strcmp(currentItem->key, item->key) == 0){
			ht_del_item(currentItem);
			ht->items[index] = item;
			return;
		}
		index = ht_get_hash(item->key , ht->size, i);
		currentItem = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key){
	int index = ht_get_hash(key , ht->size, 0);// NLAWEJ AALA LBUCKET
	ht_item* it = ht->items[index];// LKIT EL BUCKET
	int i = 1;
	while(it!=NULL){ //Bch nlawjou fwest el bucket
		if(it!=&HT_DELETED_ITEM){
		if(strcmp(it->key,key) == 0 ){
			return it->value;//Lkina el value mtaa lkey
		}
		}
		index = ht_get_hash(key, ht->size,i);//thashi aal collision
		it = ht->items[index];
		i++;
	}
	return NULL;
}
void ht_delete(ht_hash_table* ht, const char*key){
	int index = ht_get_hash(key, ht->size, 0);
	ht_item* it = ht->items[index];
	int i = 1;
	while(it!=NULL){
		if(it != &HT_DELETED_ITEM){
			if(strcmp(it->key, key) == 0){
				ht_del_item(it);
				ht->items[index] = &HT_DELETED_ITEM;
			}
		}
		index = ht_get_hash(key, ht->size,i);//thashi aal collision
		it = ht->items[index];
		i++;
	}
	ht->count--;
}

int main(){
	return 0;
}

