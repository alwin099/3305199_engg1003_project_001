#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //this library allows to use clrscr().

//function prototypes
int rotation();
char encrypt_ltr(char alpha, int key);
void encrypt_text(char text[], int key);
char decrypt_ltr(char alpha, int key);
void decrypt_text(char text[], int key);

int substitution();
int locate_index(char cipher_alpha[], char alpha_locate);
char* encrypt_sub(char *text, char cipher_alpha[]);
char* decrypt_sub(char *text, char cipher_alpha[]);


int main()
{
        //declare variable
        int prime_option;
    
        //Displays the main menu to select between the two cyptography methods.
        printf("****Welcome to the cryptography program****");
        printf("\nPlease select the following options:\n");
        printf("To use the rotation cipher method, enter 1\n");
        printf("To use the substitution cipher method, enter 2\n");
        printf("To exit the program, enter 3\n");
        scanf("%d", &prime_option); //Stores the user's choice as an integer in the variable prime_option.
    
        clrscr(); //clears the screen once an appropriate choice from the menu has been made.
    
        //This loop determines which sub-menu to direct the user to based on their initial choice.
        if(prime_option == 1) //if the user's initial choice is 1, they are directed to the rotation cipher menu.
    {
        rotation();
    }   
    
        else if (prime_option == 2) //if the user's initial choice is 2, they are directed to the substitution cipher menu.
    {
        substitution();
    } 
    
        else if(prime_option == 3) //if the user's initial choice is 4, the program exits.
    {
        return(0);
    } 
    
        else
    {
        printf("Please choose a vaild option"); //Displays if the user has entered an invaid option.
    }
 
} 
 

//This function displays the rotation cipher menu and its operations. 
int rotation()
{
        //declare variables.
        int key, rot_option;
        char text[100];
    
        //Displays the rotation cipher menu.
        printf("*****Welcome to the Rotation Cipher menu****");
        printf("\nPlease choose the following options:\n");
        printf("To encrypt the message enter 1.\n");
        printf("To decrypt the message enter 2.\n");
        printf("To exit the program enter 3.\n");
        scanf("%d", &rot_option); //store the user's choice as an integer in the variable rot_option.
    
        clrscr(); //clears the screen once an appropriate choice from the menu has been made.


        if(rot_option == 1) //Executes if the user has entered 1 from the rotation cipher menu, signifying encryption.
    {
        
        printf("Please enter message to be encrypted:\n"); //prompts user to type the message to be encrypted.
        scanf("%99[^\n]", text); //stores input into the variable text, which is a string.
  
        printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key);
  
        //loop to check if the key that is entered is between 0 and 26.
        if (key <= 0 || key >= 27) 
        {
		printf("Error, please make sure the key is between 0 and 26\n"); //displays an error message if the key is out of the range (0 - 26).
		return(0); //exits the program due to error.
    
        }
  
        encrypt_text(text, key); //call the function to encrypt the message.
        printf("The encrypted message is: %s\n", text); //display the encrypted message.
         
    }
     
     
        if(rot_option == 2) //Executes if the user has entered 2 from the rotation cipher menu, signifying decryption.
    {
    
        printf("Please enter message to be decrypted:\n"); //prompts user to type the message to be decrypted.
        scanf("%99[^\n]", text); //stores input into the variable text, which is a string.
  
        printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key);
  
        //loop to check if the key that is entered is between 0 and 26.
        if (key <= 0 || key >= 27) 
        {
		printf("Error, please make sure the key is between 0 and 26\n"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
        }
  
        decrypt_text(text, key); //call the function to decrypt the message.
        printf("The decrypted message is: %s\n", text); //display the decrypted message. 
    }
    
     
        if(rot_option == 3) //Executes if the user has entered 3 from the rotation cipher menu signfiying exiting the program.
    {
        return(0);   
    }
     
 }
 
 
//This function displays the subsituion cipher menu and its operations. 
int substitution()
{
        //Declare variables.
        int sub_option;
        char text[100];
        char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'};  

        //Displays the Substitution cipher menu.
        printf("*****Welcome to the Substitution Cipher program****");
        printf("\nPlease choose the following options:\n");
        printf("To encrypt the message enter 1.\n");
        printf("To decrypt the message enter 2.\n");
        printf("To exit the program enter 3.\n");
        scanf("%d", &sub_option); //stores the user's choice as an integer in the variable sub_option. 
    
        clrscr(); //clears the screen once an appropriate choice from the menu has been made.
        
    
        //Executes if the user has entered 1 from the substitution cipher menu, signifying encryption.
        if(sub_option == 1)
    {
        
        printf("Please enter the message to be encrypted\n"); //prompts user to type text to encrypt.
        scanf("%99[^\n]", text); //stores input in the variable text, which is a string.
  
        char *encrypted_text = encrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
        printf("The encrypted message is: %s\n", encrypted_text); //displays the decrypted text. 

    }
     
    
        //Executes if the user has entered 2 from the substitution cipher menu, signifying decryption. 
        if(sub_option == 2)
    {
    
        printf("Please enter the message to be decrypted\n"); //prompts user to enter a text to decrypt.
        scanf("%99[^\n]", text); //stores input in the variable text, which is a string.
  
        char *decrypted_text = decrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
        printf("The decrypted message is: %s\n", decrypted_text); //displays the decrypted text. 

    }
     
    
        //Executes if the user has entered 3 from the subtitution cipher menu, signifying exiting from the program
        if(sub_option == 3)
    {
        return(0);
    }
     
 }

    //Function definitions.
    
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
    }
        else
    {
        encrypted_text[k] = text[k]; 
    }
  }
        return encrypted_text; //Return the encrypted text to the function.
}    
    
    
    
        //this function decrypts the entered text.
        char *decrypt_sub(char *text,char cipher_alpha[]) 
    { 
        int txtlength = strlen(text); //Acquire length of the text using the strlen function.
        char *decrypted_text = (char *) malloc(sizeof(char)*txtlength);
    
  
        //convert to lower case as it is easier to work with only 26 letters, as opposed to a larger value.
        //'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
        for(int k = 0; k < txtlength; k++)
    {
        int decryption_index = tolower(text[k]) - 'a';
        if(decryption_index >= 0 && decryption_index < 26){
        int cipher_alpha_index = locate_index(cipher_alpha, tolower(text[k])); 
        decrypted_text[k] = 'a' + cipher_alpha_index;
    }
        else
    {
        decrypted_text[k] = text[k];
    }
  }
    return decrypted_text; //Return the decrypted text to the function.
}    
        

  
