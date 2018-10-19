#include <stdio.h>
#include <string.h>
int main(int argc, char **argv){
	int lm;
	int um;
	printf("lower limit: ");
	scanf("%d", &lm);
	printf("upper limit: ");
	scanf("%d", &um);
	printf("\nCelcius         Fahrenheit\n");
	printf("==========================\n");
	int i;
	for (i = lm; i <= um; i = i+5 ){
	char n[100];
        sprintf(n,"%d",lm);
	for (int c = 6 - strlen(n); c >= 0; c = c-1){
                printf(" ");
        }
	printf("%d",lm);
	char dn[100];
	sprintf(dn,"%.1f",((double)(lm) * 9/5.0) + 32.0);
	for (int c = 18 - strlen(dn); c >= 0; c = c-1){
		printf(" ");
	}
	
	printf("%.1f\n",((double)(lm) * 9/5.0) + 32.0);
	lm = lm+5;		
	}
	printf("--------------------------\n");
	return 0;

}
