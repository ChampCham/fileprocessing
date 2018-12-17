#include <stdio.h>

int main (int argc, char **argv){

    FILE *fin;
    FILE *fout;
    char buffer[1000];
    int c;

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    while ((c = fread(buffer, 1,1000, fin)) > 0){
        fwrite(buffer,1,c,fout); 
        printf("%s\n",buffer);    
    }

    fclose(fin);
    fclose(fout);
    return 0;


}
