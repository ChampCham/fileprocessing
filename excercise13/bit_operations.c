#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get(unsigned char *arr,int idx){
    int bit_index = idx%8;
    int byte_index = idx/8;
    return (arr[byte_index] >> bit_index) & 1;
}
void set(unsigned char *arr, int idx, int val){
    unsigned char mask = 1 << idx;
    int byte_index = idx/8;
    if (val == 1){
        arr[byte_index] |= mask;
    }else{
        arr[byte_index] &= ~mask;
    }
}


int main(){
    unsigned char str [30];
    scanf("%s", str);
    int n = strlen((char *)str);
    unsigned char *c =  (unsigned char *)malloc(sizeof(char)*n);
    strcpy((char *)c,(char *)str);

    for (int i = 0; i < 8*n; i++){
            if (i%8 == 0)printf(" ");
             printf("%d", get(c, i));
    }
   printf("\n"); 
    for (int i =8*n-1; i >= 0; i--){
        if ((i+1)%8 == 0)printf(" ");
        printf("%d", get(c, i));
    };

    set(c, 5,0);
    printf("\n");
    for (int i = 8*n-1; i >= 0; i--){
        if ((i+1)%8 == 0)printf(" ");
           printf("%d", get(c, i));
    }
    free(c);

}
