int isSingleInput(const char* input)
{
  if (input[1] == '\0') 
  {
     return 1; // The string is empty
  }
  return 0;
}

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
  else if(isSingleInput(str))
  {
     return int(str);
  }
  return -1;
}
