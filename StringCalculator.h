#include <stdlib.h>
#include <string.h>

int isNumGreaterThanThousand(int num)
{
    if(num > 1000)
    {
        return 1;
    }
    return 0;
}
int tokenizeString(const char* num)
{
    char* inputCopy = strdup(num);
    const char* delimiters = ",\n";
    char* token = strtok(inputCopy, delimiters);
    int sum = 0;
    int num = 0;

    while (token != NULL) {
        num = atoi(token);
        if(!isNumGreaterThanThousand(num)
        {
            sum += num;
        }
        
        token = strtok(NULL, delimiters);
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
