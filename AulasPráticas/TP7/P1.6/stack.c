/* stack.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
	char buffer[24];
	/* The following statement has a buffer overflow problem */
    /* Correção
    * Truncar o array de caracteres ao tamanho do buffer, inserindo
    * o caracter de fim de string na posição x do array str
    * onde x é o comprimento do buffer
    */
    if(strlen(str) > 24)
        str[24] = '\0';
	strcpy(buffer, str);
	return 1;
}

int main(int argc, char **argv)
{
	char str[517];
	FILE *badfile;
	badfile = fopen("badfile", "r");
	fread(str, sizeof(char), 517, badfile);
	bof(str);
	printf("Returned Properly\n");
	return 1;
}
