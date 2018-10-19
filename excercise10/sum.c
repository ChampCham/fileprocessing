#include <stdio.h>

void prefix_sum(int *a, int *b, int *c){
    *b = *a+*b;
    *c = *b+*c;

}
int main(){
    int a,b,c;
    printf("Input a: ");
    scanf("%d",&a);
    printf("Input b: ");
    scanf("%d",&b);
    printf("Input c: ");
    scanf("%d",&c);
    
    printf("a: %d, b: %d, c: %d\n",a,b,c);
    
    prefix_sum(&a, &b, &c);
    
    printf("a: %d, b: %d, c: %d\n",a,b,c);    
    return 0;
}


