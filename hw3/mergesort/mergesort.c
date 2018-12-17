/* Name::
 * ID:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"



void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i,j,k;
     i = j = k = 0;
    while(k < (nL+nR)){
        if ( (nL > i && nR > j &&  L[i].data < R[j].data) || j >= nR){
            memcpy(&output[k], &L[i], sizeof(Entry));
            i++;
        }else{
            memcpy(&output[k], &R[j], sizeof(Entry));
            j++;
        }
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if (n>1){
        int mid = n/2;
        Entry *L = (Entry *)malloc(sizeof(Entry)*mid);
        Entry *R = (Entry *)malloc(sizeof(Entry)*(n-mid));
        Entry *tmp = (Entry *)malloc(sizeof(Entry)*n);


        memcpy(L, entries, mid*sizeof(Entry));
        memcpy(R, entries+mid, (n-mid)*sizeof(Entry));
        
        merge_sort(L, mid);
        merge_sort(R, n-mid);
        merge(tmp, L,mid, R, n-mid);
        
        memcpy(entries, tmp, n*sizeof(Entry));
        
        free(L);
        free(R);
        free(tmp);
        L = NULL;
        R = NULL;
        tmp = NULL;
    }
}


/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int n;
    scanf("%d", &n);
    Entry *entries = (Entry *)malloc(n*sizeof(Entry));
    
    for (int i=0; i < n; i++){
        int tmp;
        char str[MAX_NAME_LENGTH];
        scanf("%d", &tmp);
        scanf("%s", str);
       
        Entry *entry = (Entry *)malloc(sizeof(Entry));
        entry->data = tmp;
        char *new_str  = (char *)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(new_str, str);
        entry->name = new_str;
        entries[i] = *entry; 
        free(entry);
    }


    merge_sort(entries, n);
   
    for (int i = 0; i < n; i++){
        printf("%d ",entries[i].data);
        printf("%s\n", entries[i].name);
    }

    for (int i = 0; i < n; i++){
        free(entries[i].name);
    }
    free(entries);
    entries = NULL;
    
}   
