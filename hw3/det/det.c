#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_pointer(int **p, int n){
    for (int i = 0; i < n; i++){
        free(p[i]);
        p[i] = NULL;
    }
    free(p);
    p = NULL;

}
double compute_det(int **a, int n) {
    if (n ==1){
        return (double)a[0][0];
    }else{
        double result = 0.0;
        int i = 1;
        for (int M = 0; M < n; M++){
            int **sub = (int **)malloc((n-1)*sizeof(int *));
            for (int j = 0; j < n-1; j++){
                 sub[j] = (int *)malloc((n-1)*sizeof(int));
            }
            
            for (int row = 1; row < n; row++){
                int count = 0;
                for (int col =0; col < n; col++){
                    if(col != M){
                        sub[row-1][count] = a[row][col];
                        count++;
                    }       
                }
            }
            result += i*a[0][M]*compute_det(sub, n-1);
            i *= -1;
            free_pointer(sub, n-1);
        }
        return result;
    }
}


/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
    int n;
    scanf("%d",&n);
    int **a = (int **)malloc(n*sizeof(int *));
    
    for (int i = 0; i < n; i++){
        a[i] = (int *)malloc(n*sizeof(int));
    }
   
    for (int row = 0; row < n; row++){
       for (int col = 0; col < n; col ++){
           scanf("%d",  &a[row][col]); 
        }
    }

   // for (int row = 0; row < n; row++){
   //     for (int col = 0; col < n; col ++){
   //         printf("%d ", a[row][col]);
   //     }
   //     printf("\n");
  //  }

    printf("%.5f", compute_det(a, n));
    free_pointer(a,n);
}
