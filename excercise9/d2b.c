#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
    int b10 = atoi(argv[1]);
    int num = 0;
    while (b10 != 0){
        int k = 0;
         while (pow(2,k) <=  b10){
             k++;
         }
        b10 = b10 - pow(2,k-1);
        num += pow(10,k-1);
    }

    printf ("%d\n",num);
    
    return 0;





}
