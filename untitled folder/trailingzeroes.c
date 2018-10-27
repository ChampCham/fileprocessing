#include <stdio.h>
#include <string.h>
int main(){
   int n;
   int result = 1;
   char num[1000];
   int count = 0;
   printf("Input: ");
   scanf("%d",&n);
   for (int i = 1; i <=  n; i++){
    	result *= i;
   }
   sprintf(num,"%d",result);
   for (int i = strlen(num)-1; i >=0; i--){
     if(num[i] == '0'){
       count++;
     }else{
      break;
     }
   }
   printf("Output: %d\n",count);
   return 0;

}
