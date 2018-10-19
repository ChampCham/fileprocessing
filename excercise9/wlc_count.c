#include <stdio.h>

int main (int argc, char **argv){
    int c;
    int numWords = 1;
    int numLines = 0;
    int numChars = 0;
    FILE *fin;
    if (argv[1] != NULL){
        fin = fopen(argv[1],"r");
    }else{
        fin = stdin;
    }
    while ((c = fgetc(fin))!= EOF){
        if (c == ' '){
            numWords++;
        }else if (c == '\n'){
            numLines++;
        }else{
            numChars++;
        }
    }
    numChars += numWords;
    fprintf(stderr, "WORDS: %d\n", numWords);
    fprintf(stderr,"LINES: %d\n",numLines);
    fprintf(stderr,"CHAR: %d\n", numChars);
    return 0;
}
