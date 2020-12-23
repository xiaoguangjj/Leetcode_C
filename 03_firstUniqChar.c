#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct UT_hash_handle {
   struct UT_hash_table *tbl;
   void *prev;                       /* prev element in app order      */
   void *next;                       /* next element in app order      */
   struct UT_hash_handle *hh_prev;   /* previous hh in bucket order    */
   struct UT_hash_handle *hh_next;   /* next hh in bucket order        */
   void *key;                        /* ptr to enclosing struct's key  */
   unsigned keylen;                  /* enclosing struct's key len     */
   unsigned hashv;                   /* result of hash-fcn(key)        */
} UT_hash_handle;

struct hashTable{
  int key;
  int val;
  UT_hash_handle hh;
};

int firstUniqChar(char * s){
  struct hashTable * frequency = NULL;
  int n = strlen(s);
  for (int i=0; i < n; i++){
    int ikey = s[i];
    struct hashTable* tmp;
    HASH_FIND_INT(frequency, &ikey,tmp);
    if (tmp == NULL){
      tmp = malloc(sizeof(struct hashTable));
      tmp->key = ikey;
      tmp->val = 1;
      HASH_ADD_INT(frequency, ikey, tmp);
    } else {
      tmp->val++;
    }
    
  }
  for (int i = 0; i < n; i++){
    int ikey = s[i];
    struct hashTable* tmp;
    HASH_FIND_INT(frequency, &ikey,tmp);
    if (tmp != NULL && tmp->val == 1){
      return i;
    }
  }
  return -1;
  
}

int main(){
  char * s ="leetcode";
  int ret = 0;
  ret = firstUniqChar(s);
  printf("%d\n",ret);
}
