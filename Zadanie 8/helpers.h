//	POPIS:
//	Hlavickovy subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie funkcii, ktore su implementovane v file_io.c a functions.c
//		* pomocne makra

#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#define MAX_ARG 10
#define MAX_SIZE 1000
// deklaracie premennych

// deklaracie funkcii zo suboru file_io.c
char* read_file(char* fname);
int write_file(char* fname, char* text);

// deklaracie funkcii zo suboru functions.c
// TODO: sem idu deklaracie vasich funkcii...
int nacitanie(int argc, char *argv[MAX_ARG], char **in, char **sub, char **out);
char **rozdelenie(char *text);
void nahradenie(char** text, char** sub, char* inTxt);
int zapis(char** arrText, char* text, char* fname);
// makra

// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#endif // HELPERS_H_INCLUDED
