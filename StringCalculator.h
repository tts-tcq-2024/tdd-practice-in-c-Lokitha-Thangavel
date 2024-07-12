#include <stdlib.h>
#include <string.h>

int tokenizeString(const char* num)
{
    char* inputCopy = strdup(num);
    char* token = strtok(inputCopy, ",");
    int sum = 0;

    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, ",");
    }

    free(inputCopy);
    return sum;
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
    return tokenizeString(str);
  }
}
