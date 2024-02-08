#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define KEYWORD 	1
#define IDENTIFIER 	2
#define OPERATOR 	3
#define CONSTANT 	4
#define SEPARATOR 	5

struct Lexeme
{
    int tokenType;
};

bool isStringInArray(const char* array[], const char* string, int size) 
{
    for (int i = 0; i < size; i++) {
        if (strcmp(string, array[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isKeyWord(const char *buffer) 
{
    const char *keyWords[11] = {"void", "char", "int", "float", "double", "+", "-", "*", "/", "="};
    int numKeywords = sizeof(keyWords) / sizeof(keyWords[0]);

    return isStringInArray(keyWords, buffer, numKeywords);
}

bool isDataType(const char *buffer) 
{
    const char *keyWords[5] = {"void", "char", "int", "float", "double"};
    int numKeywords = sizeof(keyWords) / sizeof(keyWords[0]);

    return isStringInArray(keyWords, buffer, numKeywords);
}

bool isSeparator(const char *buffer) 
{
    const char *keyWords[3] = {" ", ";", ","};
    int numKeywords = sizeof(keyWords) / sizeof(keyWords[0]);

    return isStringInArray(keyWords, buffer, numKeywords);
}

char fileToString(FILE *file)
{
	char buffer[1024];
	int position = 0;
	char character;

	while ((character = fgetc(file)) != EOF)
	{
		buffer[position++] = character;
	}

	buffer[position] = '\0';
	return buffer;
}

void printAllTokenTypes(const char* string, int size)
{

}

void executeCode(const char* path)
{
	FILE *file = fopen(path, "r");
	
	if (file == NULL)
		printf("error to open the file");

	char code[] = fileToString(file);
	int size = sizeof(code);
	printAllTokenTypes(code, size)
}

int main() 
{
	int *tokens = malloc(10 * sizeof(int));

    executeCode("code.txt");
    return 0;
}
