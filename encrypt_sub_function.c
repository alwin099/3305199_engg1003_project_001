#include <stdio.h>
#include <string.h>


//function prototypes
int locate_index(char cipher_alpha[], char alpha_locate);
char* encrypt_sub(char *text, char cipher_alpha[]);


//this function acquires the cipher index of each letter in the text.
int locate_index(char cipher_alpha[], char alpha_locate)
    {
  for(int k = 0 ; k < 26; k ++){
    if(cipher_alpha[k] == alpha_locate) //compares between the letters in the text and the substitution alphabet.
    {
      return k;
    }
  }
  return -1;
} 
 
  
  char* encrypt_sub(char *text,char cipher_alpha[]) //Function prototype.
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
  

int main()
{
 
  //declare variables
  char text[100];
  char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'}; //substitution alphabet.

  
  printf("Please enter the text to be encrypted\n"); //prompts user to type text to encrypt.
  scanf("%99[^\n]", text); //stores input in the variable text, which is a string.
  
  char *encrypted_text = encrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
  printf("The encrypted text is: %s\n", encrypted_text); //displays the decrypted text.
  
  return 0;
}
