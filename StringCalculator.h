#include <stdlib.h>
#include <string.h>

int isNumGreaterThanThousand(int num)
{
    if(num > 1000)
    {
        return 0;
    }
    return num;
}

int tokenizeString(char *input)
{
    char *token;
    int total = 0;
    const char delimiters[] = "$#\n:,;//\\&#%";

    token = strtok(input, delimiters);
    while (token != NULL) 
    {
        // Convert token to integer using atoi
        int num = atoi(token);

        total += isNumGreaterThanThousand(num);
        // Get the next token
        token = strtok(NULL, delimiters);
    }

    return total;
}

int createCopy(const char *input)
{
    if (strlen(input) == 1)
    {
        return atoi(input);
    }
    // Create a modifiable copy of the input
    char inputCopy[100];
    strcpy(inputCopy, input);
    return tokenizeString(inputCopy); // Provide sum only if it is not a single character
}

int isEmptyString(const char* input)
{
  if (input == NULL || input[0] == '\0') 
  {
     return 1; 
  }
  return 0;
}

int add (const char* str)
{
  if(isEmptyString(str))
  {
     return 0;
  }
  else
  {
    return createCopy(str);
  }
}
