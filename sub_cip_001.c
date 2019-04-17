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
int locate_index(char cipher_alpha[], char alpha_locate){
  for(int i = 0 ; i < 26; i ++){
    if(cipher_alpha[i] == alpha_locate){
      return i;
    }
  }
  return -1;
}


//encrypts the given text.
char* encrypt(char *text,char cipher_alpha[]){
  int length = strlen(text); //Acquire length of text using the strlen function.
  char *encrypted_text = (char *) malloc(sizeof(char)*length);

//convert to lower case.
  for(int i = 0; i < length; i++){
    int encryption_index = tolower(text[i]) - 'a'; // substracts 'a' to get encryption index.
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_text[i] = cipher_alpha[encryption_index];
    }else{
      encrypted_text[i] = text[i];
    }
  }
  return encrypted_text;
}


//decrypts the given text.
char *decrypt(char *text,char cipher_alpha[]){
  int length = strlen(text);
  char *decrypted_text = (char *) malloc(sizeof(char)*length);
  for(int i = 0; i <length; i++){
    int decryption_index = tolower(text[i]) - 'a';
    if(decryption_index >= 0 && decryption_index < 26){
      int cipher_alpha_index = locate_index(cipher_alpha, tolower(text[i])); 
      decrypted_text[i] = 'a' + cipher_alpha_index;
    }else{
      decrypted_text[i] = text[i];
    }
  }
  return decrypted_text;
}

int main(){
  char *text = "Hello, how are you today?"; //hard coded text to be encrypted and decrypted.
  char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'}; //substitution alphabet.

  char *encrypted_text = encrypt(text, cipher_alpha);
  printf("The original text was: %s\nThe encrypted text is: %s\n",text,encrypted_text); //Display original text and encrypted text.
  char *decrypted_text = decrypt(encrypted_text,cipher_alpha);
  printf(" The decrypted text is: %s\n",decrypted_text); //Display decrypted text.
}
