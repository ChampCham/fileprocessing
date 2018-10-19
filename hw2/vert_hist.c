#include <stdio.h>
#include <ctype.h>
int main (){
    int c;
    int freq[26];
    int max = 0;

    for(int i = 0; i < 26; i++){
        freq[i] = 0;
    }

    while ((c = getchar()) != EOF){
        if (isalpha(c)){
            c = toupper(c);
            freq[c -65] +=1;
        }   
           
    }

    for(int i = 0; i < 26; i++){
        if (max < freq[i]){
            max = freq[i];
        }
    }
    
    for (int m = max; m > 0; m--){
        for (int j = 0; j < 26; j++){
            if(m == freq[j]){
                printf("*");
                freq[j] -= 1;
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("abcdefghijklmnopqrstuvwxyz\n");

    return 0;



}
