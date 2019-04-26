#include <stdio.h>

//function prototypes
char encrypt_ltr(char alpha, int key); 
void encrypt_text(char text[], int key);


int main()
{
  
  //declare variables.        
  int key;
  char text[100];

  printf("PLease enter message to be encrypted:\n"); //prompts user to type the message to be encrypted.
  scanf("%99[^\n]s", text); //stores input into the variable text, which is a string.
  
  printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
  scanf("%d", &key);
  
  //loop to check if the key that is entered is between 0 and 26.
    if (key <= 0 || key >= 27) 
    {
		printf("Error, please make sure the key is between 0 and 26"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
    
    }
  
  encrypt_text(text, key); //call the function to encrypt the message.
  printf("The encrypted message is: %s\n", text); //display the encrypted message.
  return 0;
}


//this function encrypts one single letter at a time, considering both lower case and upper case.
char encrypt_ltr(char alpha, int key) 
{
  if (alpha >= 'A' && alpha <= 'Z') //considers upper case letters.
  {
      alpha = ((alpha-'A') + key) % 26 + 'A'; //encrypts a letter by adding the particular key to the ASCII value.
  }
  else if(alpha >= 'a' && alpha <= 'z') //considers lower case letters.
  {
      alpha = ((alpha-'a') + key) % 26 + 'a'; //encrypts a letter by adding the particular key to the ASCII value.
  }

  return alpha; //returns the encrypted letters.
}


//this function encrypts a message, which consists of encrypting every letter of that message.
void encrypt_text(char text[], int key)
{
  // declare and or initialise variables.
  int i = 0;
  char result;
  
  while (result = text[i]) //entered message is encrypted using this loop.
  {
    result = encrypt_ltr(result, key); 
    text[i] = result; //the result of above calculation is now stored in the string text, which now contains the encrypted message.
    i++;
  }
}







