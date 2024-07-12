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

char* extractCustomDelimiter(const char* start, const char* end, int isBracketed) {
    size_t delimiterLength = end - start + (isBracketed ? -1 : 1);
    char* customDelimiter = (char*)malloc(delimiterLength + 1);
    strncpy(customDelimiter, start, delimiterLength);
    customDelimiter[delimiterLength] = '\0';
    return customDelimiter;
}

const char* extractDelimiters(const char* numbers, const char** delimiters) {
    if (numbers[0] != '/' || numbers[1] != '/') {
        return numbers; // No custom delimiter format
    }

    const char* delimiterEnd = strstr(numbers, "\n");
    if (delimiterEnd == NULL) {
        return numbers; // No newline found after custom delimiter declaration
    }

    const char* delimiterStart = numbers + 2;
    int isBracketed = (delimiterStart[0] == '[');
    if (isBracketed) {
        delimiterStart++;
    }
    *delimiters = extractCustomDelimiter(delimiterStart, delimiterEnd - 1, isBracketed);

    return delimiterEnd + 1;
}

int tokenizeString(const char* number)
{
   
    const char* delimiters = ",\n";
    const char* numberStart = extractDelimiters(number, &delimiters);
     char* inputCopy = strdup(numberStart);
    char* token = strtok(inputCopy, delimiters);
    int sum = 0;
    int num = 0;

    

    while (token != NULL) {
        num = atoi(token);
        if(!isNumGreaterThanThousand(num))
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
