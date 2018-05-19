//	POPIS:
//	Subor obsahujuci implementacie vasich funkcii.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "helpers.h"

int nacitanie(int argc, char *argv[MAX_ARG], char **in, char **sub, char **out) {
	int i,x = 0;
	for (i = 0;i < argc;i++) {
		if (strcmp(argv[i], "-i") == 0) {
			*in = read_file(argv[i + 1]);
			if (*in != NULL) {
				x++;
				printf("Input.txt nacitany...\n");
			}
		}
		else if (strcmp(argv[i], "-s") == 0) {
			*sub = read_file(argv[i + 1]);
			if (*sub != NULL) {
				x++;
				printf("Sub.txt nacitany...\n");
			}
		}
		else if (strcmp(argv[i], "-o") == 0) {
			*out = argv[i+1];
			if (*out != NULL) {
				x++;
				printf("Output.txt nacitany...\n");
			}
		}
	}
	Sleep(1000);
	CLEAR_SCREEN();
	return x;
}
char **rozdelenie(char *text) {
	int i = 0;
	char **arr = malloc (MAX_SIZE * sizeof(char));
	const char del[6] = "= \n.,";
	arr[i] = malloc(20 * sizeof(char));
	arr[i] = strtok(text, del);
	while (arr[i] != NULL) {
		arr[++i] = malloc(20 * sizeof(char));
		arr[i] = strtok(NULL, del);
	}
	return arr;
}
void nahradenie(char** text, char** sub, char* inTxt) {
	int i, j;
	
	for (i = 0;text[i] != NULL;i++) {
		for (j = 0;sub[j] != NULL; j++) {			
			if (strcmp(text[i], sub[j++]) == 0) {
				strcpy(text[i], sub[j]);				
			}
		}
	}
}
int zapis(char** arrText, char* text, char* fname) {
	
	FILE * f;
	f = fopen(fname, "w"); 
	if (f == NULL) 
		return 0;
	int i, pos;

	for (i = 0;arrText[i] != NULL; i++) {
		fprintf(f, "%s", arrText[i]);
		pos = ftell(f);
		if (text[pos] == '.') {
			putc('.',f);
		}
		else if (text[pos] == ',') {
			putc(',',f);
		}
		else if (text[pos] == '\n') {
			putc('\n', f);
		}
		putc(' ',f);
		

	}
	fclose(f); 

	return 1;
}