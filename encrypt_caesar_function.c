#include <stdio.h>

char encrypt_ltr(char alpha, int key)
{
  if (alpha >= 'A' && alpha <= 'Z')
  {
      alpha = ((alpha-'A') + key) % 26 + 'A';
  }
  else if(alpha >= 'a' && alpha <= 'z')
  {
      alpha = ((alpha-'a') + key) % 26 + 'a';
  }

  return alpha;
}


void encrypt_text(char text[], int key)
{
  int i = 0;
  char result ;
  while (result = text[i])
  {
    result = encrypt_ltr(result, key);
    text[i] = result;
    i++;
  }
}


int main()
{
  int key;
  char text[100];

  printf("PLease enter message to be encrypted:\n");
  scanf("%s", text);
  
  printf("Please enter the key:\n");
  scanf("%d", &key);
  
  encrypt_text(text, key);
  printf("The encrypted message is: %s\n", text);
  return 0;
}
