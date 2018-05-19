//	POPIS:
//	Hlavny subor obsahujuci funkciu main().
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"

int main(int argc, char* argv[])
{
	int end;
	char *inTxt, *subTxt, *outTxt, *origTxt;
	int test = nacitanie(argc, argv, &inTxt, &subTxt, &outTxt);
	if (test < 2) {
		printf("Nacitanie nebolo uspesne.\n");
		return -1;
	}
	printf("Povodny text:\n%s\n", inTxt);
	printf("Substitucia:\n%s\n", subTxt);
	
	origTxt = malloc(strlen(inTxt) + 1 * sizeof(char));
	strcpy(origTxt, inTxt); //string na uchovanie povodneho textu
	
	char** sub = rozdelenie(subTxt);
	char** input = rozdelenie(inTxt);  //rozdelenie textu na jednotlive slova
	
	nahradenie(input, sub, inTxt);


	if (outTxt == NULL || argc < 6) {
		end = zapis(input, origTxt, "file_out.txt");
		char* output = read_file("file_out.txt");
		printf("Opraveny text:\n%s\n", output);
	}
	else {
		end = zapis(input, origTxt, outTxt);
	}
	if (end == 0)
		printf("Zapis neuspesny.\n");
	else if (end == 1)
		printf("Zapis uspesny. \n");

    return 0;
}
