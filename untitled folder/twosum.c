#include <stdio.h>
#define MAX 1000
int main(){
   int n,t;
   int arr[MAX];
   int found = 0;
   scanf("%d %d",&n,&t);
   for(int i =0;i<n;i++){
    int num;	
    scanf("%d",&num);
    arr[i] = num;	
   }	
   
   for(int r = 0; r < n-1; r++){
 	for (int s = 1; s < n; s++){
		if (arr[r]+arr[s] == t){
			found +=1;
		}
	} 
   }	
   if(found >= 1){
       printf("YES\n");
   }else{
       printf("NO\n");		
   }
   return 0;

}
