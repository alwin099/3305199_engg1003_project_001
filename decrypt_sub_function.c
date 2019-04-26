#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//function prototypes
int locate_index(char cipher_alpha[], char alpha_locate);
char* decrypt_sub(char *text, char cipher_alpha[]);


//this function acquires the cipher index of an encrypted letter.
int locate_index(char cipher_alpha[], char alpha_locate)
    {
  for(int k = 0 ; k < 26; k ++){
    if(cipher_alpha[k] == alpha_locate // compares between the letters in the text and the substitution alphabet.
    {
      return k;
    }
  }
  return -1;
} 
 
 
 //this function decrypts the entered text.
 char *decrypt_sub(char *text,char cipher_alpha[]) 
    { 
  int txtlength = strlen(text); // Acquire length of the text using the strlen function.
  char *decrypted_text = (char *) malloc(sizeof(char)*txtlength);
  
  
  //convert to lower case as it is easier to work with only 26 letters, as opposed to a larger value.
 //'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
  for(int k = 0; k < txtlength; k++)
    {
    int decryption_index = tolower(text[k]) - 'a';
    if(decryption_index >= 0 && decryption_index < 26){
      int cipher_alpha_index = locate_index(cipher_alpha, tolower(text[k])); 
      decrypted_text[k] = 'a' + cipher_alpha_index;
    }else{
      decrypted_text[k] = text[k];
    }
  }
  return decrypted_text; //Return the decrypted text to the function.
}
  

int main()
{
  
  //declare variables.
  char text[100];
  char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'}; //substitution alphabet.

  
  printf("Please enter the text to be decrypted\n"); //prompts user to enter a text to decrypt.
  scanf("%99[^\n]", text); //stores input in the variable text, which is a string.
  
  char *decrypted_text = decrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
  printf("The decrypted text is: %s\n", decrypted_text); //displays the decrypted text.
  
  return 0;
}
