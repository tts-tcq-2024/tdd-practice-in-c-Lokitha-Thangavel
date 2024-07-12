int isEmptyString(const char* input)
{
  if (input == NULL || input[0] == '\0') 
  {
     return 1; // The string is empty
  }
  return 0;
}

int add (const char* str)
{
  if(isEmptyString(str))
  {
     return 0;
  }
  return -1;
}
