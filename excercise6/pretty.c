#include<stdio.h>
#include<string.h>
int main (int argc, char **argv){
	int n;
	char str[10];
	int count = 0; 
 	while (scanf("%s %d",str, &n) == 2){
		if (count == 0){
		printf("\n================================");	
		}
		printf("\n%s",str);
		int c;
		for (c = 15-strlen(str); c >= 0; c=c-1 ){
		 	printf(" ");	
		}	
		if (n >= 100){
			printf("%d",n);
		}else if( n >= 10){
			printf("%d%d",0,n);
		}else{
			printf("%s%d","00",n);
		}
		count = count +1;
	}
	printf("================================\n");
	return 0;
}
