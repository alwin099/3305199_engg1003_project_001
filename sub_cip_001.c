#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* ENGG1003 Programming Assignment 1
*  Name: Alwin Wilson
*  Student number: 3305199
*  Date: 29/4/19
*  Description: Encrypts and decrypts a message using the substitution cipher method.*/


// Function to 
int locate_index(char cipher_alpha[], char alpha_locate)
    {
  for(int k = 0 ; k < 26; k ++){
    if(cipher_alpha[k] == alpha_locate){
      return k;
    }
  }
  return -1;
}


//Function to encrypt the given  text.
char* encrypt(char *text,char cipher_alpha[]) //Function prototype.
    {
  int txtlength = strlen(text); //Acquire length of the text using the strlen function to know how many iterations is required.
  char *encrypted_text = (char *) malloc(sizeof(char)*txtlength);

 //convert to lower case as it is easier to work with only 26 letters, as opposed to a larger value.
 // 'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
  for(int k = 0; k < txtlength; k++){
    int encryption_index = tolower(text[k]) - 'a'; 
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_text[k] = cipher_alpha[encryption_index];
    }else{
      encrypted_text[k] = text[k]; 
    }
  }
  return encrypted_text; //Return the encrypted text to the function.
}


//Function to decrypt the given text.
char *decrypt(char *text,char cipher_alpha[]) //Function prototype
    { 
  int txtlength = strlen(text); // Acquire length of the text using the strlen function.
  char *decrypted_text = (char *) malloc(sizeof(char)*txtlength);
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

int main(){
  char *text = "The quick brown fox jumps over the lazy dog"; //hard coded text to be encrypted and decrypted.
  char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'}; //substitution alphabet.

  char *encrypted_text = encrypt(text, cipher_alpha);
  printf("The original text was: %s\nThe encrypted text is: %s\n",text,encrypted_text); //Display original text and encrypted text.
  char *decrypted_text = decrypt(encrypted_text,cipher_alpha);
  printf("The decrypted text is: %s\n",decrypted_text); //Display decrypted text.
}
