
/**
 * print hexvalues from file(gif)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE 256

typedef struct Gif {

unsigned int width;
unsigned int height;
unsigned char lsd; //Logical Screen Descriptor
int gctf; //Global Color Table Flag (boolean)
unsigned short resolution; //per Pixel
unsigned int ColorTable; //2^(N+1) bytes N->lsd		

}Gif;

void printHexFile(FILE *stream, int n);
void printHexArray(unsigned char *stream, int n);
int charCounter(FILE *file);
FILE* openFile(char *fileName);

int main() {

    FILE *fr;
    char fileName[] = "testImages/rgb.gif";
    fr = openFile(fileName);

    int i, n = charCounter(fr);

    unsigned char stream[n];

	for(i = 0; i < n; i++) {

    	stream[i] = fgetc(fr);
    }

	 fclose(fr);

	int width, height;
	printf("signature & version : %c%c%c%c%c%c\n",stream[0],stream[1],stream[2],stream[3],stream[4],stream[5]);
	printf("width in hex : %d\n",stream[7] * BYTE + stream[6]);
	printf("height in hex : %d\n",stream[9] * BYTE + stream[8]);

	

    return 0;
}

/**
*
* Function for count the characters of a File
*
**/

int charCounter(FILE *file) {

    char p;
    
    int n = 0;

    while(p = fgetc(file) != EOF) n++;

	rewind(file);
   
    return n;
}

/**
*
*Function for open a file
*
**/

FILE* openFile(char *fileName) {

	FILE *file = fopen(fileName,"r");
	
	if(file == NULL) {
	printf("Error 404 File not Found");
	exit(0);
    }
	return file;
}

/**
*
* Function for print the HexValue of a File
*
**/

void printHexFile(FILE* stream,int n) {

	int i;

	printf("\n\n");

	for(i = 0; i < n; i++) {

       printf("%X", fgetc(stream));
    }

	printf("\n\n");

	rewind(stream);
	
}

/**
*
* Function for print the HexValue of an Array (useful if you imported the file characters in it)
*
**/

void printHexArray(unsigned char* stream,int n) {

	int i;

	printf("\n\n");

	for(i = 0; i < n; i++) {

		printf("%X", stream[i]);
	}

	printf("\n\n");
}
