#include <stdio.h>

//function prototypes
 char decrypt_ltr(char alpha, int key);
 void decrypt_text(char text[], int key);


int main()
{
  
  //declare variables.        
  int key;
  char text[100];

  printf("Please enter message to be decrypted:\n"); //prompts user to type the message to be decrypted.
  scanf("%99[^\n]s", text); //stores input into the variable text, which is a string.
  
  printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
  scanf("%d", &key);
  
  //loop to check if the key that is entered is between 0 and 26.
    if (key <= 0 || key >= 27) 
    {
		printf("Error, please make sure the key is between 0 and 26"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
    }
  
  decrypt_text(text, key); //call the function to decrypt the message.
  printf("The decrypted message is: %s\n", text); //display the decrypted message.
  return 0;
}


//this function decrypts one single letter at a time, considering both lower case and upper case.
char decrypt_ltr(char alpha, int key) 
{
  if (alpha >= 'A' && alpha <= 'Z') //considers upper case letters.
  {
      alpha = ((alpha-'A') - key) % 26 + 'A'; //decrypts a letter by subtracting the particular key to the ASCII value.
  }
  else if(alpha >= 'a' && alpha <= 'z') //considers lower case letters.
  {
      alpha = ((alpha-'a') - key) % 26 + 'a'; //decrypts a letter by subtracting the particular key to the ASCII value.
  }

  return alpha; //returns the decrypted letters.
}


//this function decrypts a message, which consists of decrypting every letter of that message.
void decrypt_text(char text[], int key)
{
  // declare and or initialise variables.
  int i = 0;
  char result;
  
  while (result = text[i]) //entered message is encrypted using this loop.
  {
    result = decrypt_ltr(result, key); 
    text[i] = result; //the result of above calculation is now stored in the string text, which now contains the encrypted message.
    i++;
  }
}
