#include <stdio.h>

char encrypt_rot(char in, int key)
{
  if (in >= 'A' && in <= 'Z')
  {
      in = ((in-'A') + key) % 26 + 'A';
  }
  else if(in >= 'a' && in <= 'z')
  {
      in = ((in-'a') + key) % 26 + 'a';
  }

  return in;
}


void encryptphrase(char phrase[], int key)
{
  int i = 0;
  char c ;
  while (c = phrase[i])
  {
    c = encryptchar(c, key);
    phrase[i] = c;
    i++;
  }
}


int main()
{
  int key;
  char phrase[100];

  printf("Enter shift amount (1-25):\n");
  scanf("%d", &key);

  printf("Enter message to be encrypted:\n");
  scanf("%s", phrase);
  encryptphrase(phrase, key);
  printf("%s\n", phrase);
  return 0;
}
