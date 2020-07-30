#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Combine 2 strings lexicographically with a space inbetween

void perfect_square(char *string1, char *string2, char *resultant)
{
	if(strcmp(string1, string2) < 0)
	{
		strcat(resultant, string1);
		strcat(resultant, " ");
		strcat(resultant, string2);
	}
	else if(strcmp(string1, string2) > 0)
	{
		strcat(resultant, string2);
		strcat(resultant, " ");
		strcat(resultant, string1);
	}
	else
	{
		strcat(resultant, string1);
		strcat(resultant, " ");
		strcat(resultant, string1);
	}
}

int main(void)
{
	int strlen1 = 3, strlen2 = 3;
	char *string1 = malloc(sizeof(char) * (strlen1 + 1)), *string2 = malloc(sizeof(char) * (strlen2 + 1)), *resultant = malloc(sizeof(char) * (strlen1 + strlen2 + 2));
	
	strcpy(string1, "abc");
	strcpy(string2, "bcd");
	perfect_square(string1, string2, resultant);
	
	printf("String1: %s\nString2: %s\nResultant: %s\n", string1, string2, resultant);
	printf("Length of resultant: %d\n", strlen1 + strlen2 + 1);
	
	free(string1);
	free(string2);
	free(resultant);
	return 0;
}
