#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv){
    int  num_space;
    num_space = atoi(argv[2]);
    int c;
    int count = 0;
    if (strcmp(argv[1] ,"-d") == 0){
        while ((c = getchar()) != EOF){
            if (c == '\t'){
               for (int i = 0; i < num_space; i++){
                    putchar(' ');
                } 
            }else{
                putchar(c);
            }
        }
    }else if(strcmp(argv[1], "-e") == 0){
         while ((c = getchar()) != EOF){
             if (c == ' '){
                 count += 1;
             }else{
                if (count == num_space ){
                     putchar('\t');
                    
                 }else{

                   for (int i = 0; i < count; i++){
                         putchar(' ');
                    }
                 }
                putchar(c);
                count = 0;
                
             }
        }    
   }else{
        printf("Error input");
   }
    return 0;
}
