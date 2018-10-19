#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char words[500000][51];

int compare (const void *a, const void * b){ 
    return ( *(char *)a - *(char *)b ); 
}

int compare_length (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);
    return (fa > fb) - (fa < fb);
}

int main (int argc, char **argv){
    FILE *jumb;
    FILE *dic;
    dic  = fopen(argv[1], "r");    
    jumb = fopen(argv[2], "r");
    char oldstr[50];
    char newstr[50];
    char w[50];
    char nw[50];
    int word_len = 0;
    int count = 0; 

    while (fgets(w, 50, dic) != NULL){
            int lw = strlen(w);
            if(w[lw - 1] == '\n'){
                w[lw - 1] = '\0';
             }
             strcpy(words[word_len], w);
             word_len++;
    }
    fclose(dic);
    qsort(words, word_len, 51, compare_length);
    
    while ( fgets(oldstr,50,jumb) != 0){
        if(oldstr[strlen(oldstr) - 1] == '\n'){
		    oldstr[strlen(oldstr) - 1] = '\0';
        }
        size_t ls = strlen(oldstr);
        strcpy(newstr,oldstr);
        qsort( newstr, ls, sizeof( char ), compare );
        printf("%s: ",oldstr);
        for (int i = 0; i <= word_len; i++){
            int len = strlen(words[i]);
            if (ls < len){
                break;
            }else{
                 strcpy (nw, words[i]);
                 qsort(nw, len, sizeof (char), compare);
                 if (strcmp(newstr, nw) == 0 ){
                    printf("%s ", words[i]);
                    count = 1;
                 }
            }
        }   
        if (count == 0){
            printf("NO MATCHES");
        }
        printf("\n");
        count = 0;
    }
    fclose(jumb);
    return 0;
}
