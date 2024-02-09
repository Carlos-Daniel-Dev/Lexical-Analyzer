#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

enum TokenType {
    INT,
    ID,
    ASSIGN,
    NUMBER,
    SEMICOLON,
    PRINT,
    LPAREN,
    RPAREN,
    ERROR
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

bool isKeyword(const char *buffer) 
{
    const char *keywords[11] = {"void", "char", "int", "float", "double", "+", "-", "*", "/", "="};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    return isStringInArray(keywords, buffer, numKeywords);
}

bool isDataType(const char *buffer) 
{
    const char *keywords[5] = {"void", "char", "int", "float", "double"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    return isStringInArray(keywords, buffer, numKeywords);
}

bool isSeparator(const char *buffer) 
{
    const char *separators[3] = {" ", ";", ","};
    int numSeparators = sizeof(separators) / sizeof(separators[0]);

    return isStringInArray(separators, buffer, numSeparators);
}

char* fileToString(FILE *file)
{
    char *buffer = malloc(1024 * sizeof(char));
    int position = 0;
    char character;

    while ((character = fgetc(file)) != EOF)
    {
        buffer[position++] = character;
    }

    buffer[position] = '\0';
    return buffer;
}

void printAllTokenTypes(const char* string)
{
    int position = 0;
    while (string[position] != '\0')
    {
        printf("%c", string[position]);
        if (isSeparator(&string[position]))
        {
            printf("\n");
            printf("Separator found at position %d, %c\n", position, string[position]);
        }
        position++;
    }
}

FILE *getFile(const char* path)
{
    FILE *file = fopen(path, "r");
    
    if (file == NULL)
        printf("Error: Failed to open the file\n");
    return file;
}

void executeCode(const char* path)
{
	FILE *file = getFile(path);
	char *code = fileToString(file);
	printAllTokenTypes(code);
	free(code);
	fclose(file);

}

int main() 
{
    executeCode("code.txt");
    return 0;
}