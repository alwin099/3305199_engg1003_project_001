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
  
  //declare variables.        
  int key;
  char text[100];

  printf("PLease enter message to be encrypted:\n"); //prompts user to type the message to be encrypted.
  scanf("%[^\n]s", text); //stores input into the variable text, which is a string.
  
  printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
  scanf("%d", &key);
  
  //loop to check if the key that is entered is between 0 and 26.
    if (key <= 0 || key >= 26) 
    {
		printf("Error, please make sure the key is between 0 and 26"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
    
    }
  
  encrypt_text(text, key); //call the function to encrypt the message.
  printf("The encrypted message is: %s\n", text); //display the encrypted message.
  return 0;
}
