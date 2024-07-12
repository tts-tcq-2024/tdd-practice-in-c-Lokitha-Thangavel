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

const char* extractDelimiters(const char* numbers, const char** delimiters) 
{    
    const char* numberStart = numbers;

    if (numbers[0] == '/' && numbers[1] == '/') 
    {
        const char* delimiterEnd = strstr(numbers, "\n");
        if (delimiterEnd != NULL) 
        {
            numberStart = delimiterEnd + 1;
            size_t delimiterLength;
            if (numbers[2] == '[') 
            {
                delimiterLength = delimiterEnd - numbers - 3;
                char* customDelimiter = (char*)malloc(delimiterLength);
                strncpy(customDelimiter, numbers + 3, delimiterLength);
                customDelimiter[delimiterLength - 1] = '\0';
                *delimiters = customDelimiter;
            } 
            else 
            {
                delimiterLength = delimiterEnd - numbers - 2;
                char* customDelimiter = (char*)malloc(delimiterLength + 1);
                strncpy(customDelimiter, numbers + 2, delimiterLength);
                customDelimiter[delimiterLength] = '\0';
                *delimiters = customDelimiter;
            }
        }
    }
    return numberStart;
}

int tokenizeString(const char* number)
{
    char* inputCopy = strdup(number);
    const char* delimiters = ",\n";
    const char* numberStart = extractDelimiters(number, &delimiters);
    char* token = strtok(inputCopy, delimiters);
    int sum = 0;
    int num = 0;

    

    while (token != NULL) {
        num = atoi(token);
        if(!isNumGreaterThanThousand(numberStart))
        {
            sum += numberStart;
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
