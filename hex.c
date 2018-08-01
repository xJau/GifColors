
/**
 * print hexvalues from file(gif)
 */

#include <stdio.h>
#include <string.h>


int main() {
    FILE *fr;
    char fileName[] = "testImages/randomGradient.gif";
    fr = fopen(fileName,"r");

    char p;
    
    int i, n = 0;

    while(p = fgetc(fr) != EOF) n++;
    fr = fopen(fileName,"rb");

    char c[n];

     for(i = 0; i < n; i++) {
    //    c[i] = fgetc(fr);
       printf("%X", fgetc(fr));
    }


    printf("\n\n%d\n\n\n",n);

    fclose(fr);
    return 0;
}