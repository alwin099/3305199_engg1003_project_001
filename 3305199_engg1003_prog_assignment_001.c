        /* ENGG1003 Programming Assignment 1
        *  Name: Alwin Wilson
        *  Student number: 3305199
        *  Date: 29/4/19
        *  Description: Encrypts and decrypts a message using either a rotation cipher method or a substitution cipher method.*/
        
        //List of Libraries used.
        #include <stdio.h>
        #include <string.h> //Used for string handling.
        #include <stdlib.h>
        #include <conio.h> //This library allows to use clrscr().
        

        //Function prototypes
        int rot(); //Rotation cipher menu and operations.
        char encrypt_ltr(char ltr, int key); //Encrypts each letter in the message.
        void encrypt_text(char text[], int key); //Encrypts a whole message by using values from encrypt_ltr
        char decrypt_ltr(char ltr, int key); //Decrypts each letter in the message.
        void decrypt_text(char text[], int key); //Decrypts a whole messsage by using values from decrypt_ltr.
        int sub(); //Substitution cipher menu and operations.
        int locate_index(char cipher_alpbt[], char locate_ltr); //Find the cipher index of each letter in the message.
        char* encrypt_sub(char *text, char cipher_alpbt[]); //Encrypts the entered message.
        char* decrypt_sub(char *text, char cipher_alpbt[]); //Decrypts the entered message.


int main()
{
        //Declare variable
        int prime_option;
    
        //Displays the main menu to select between the two cyptography methods.
        printf("*****Welcome to the cryptography program main menu*****");
        printf("\nPlease select from the following options:\n");
        printf("To use the rotation cipher method, enter 1\n");
        printf("To use the substitution cipher method, enter 2\n");
        printf("To exit the program, enter 3\n");
        scanf("%d", &prime_option); //Stores the user's choice as an integer in the variable prime_option.
    
        clrscr(); //Clears the screen once an appropriate choice from the main menu has been made.
    
        //This loop determines which sub-menu to direct the user to based on their initial choice.
        if(prime_option == 1) //If the user's initial choice is 1, they are directed to the rotation cipher menu.
    {
        rot(); //This function executes the rotation cipher menu and operations.
    }   
    
        else if (prime_option == 2) //If the user's initial choice is 2, they are directed to the substitution cipher menu.
    {
        sub(); //This function executes the substitution cipher menu and operations.
    } 
    
        else if(prime_option == 3) //If the user's initial choice is 3, the program exits.
    {
        return(0);
    } 
    
        else
    {
        printf("Please choose a vaild option"); //Displays if the user has entered an invaid option.
    }
 
} //End of main.


//This function executes the rotation cipher menu and its operations. 
//In this method each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet.
//The key is the number of positions by which the alphabet is shifted.
int rot()
{
        //Declare variables.
        int key, rot_option;
        char text[100]; //Variaable to store message.
    
        //Displays the rotation cipher menu.
        printf("*****Welcome to the Rotation Cipher menu*****");
        printf("\nPlease choose the from following options:\n");
        printf("To encrypt the message enter 1.\n");
        printf("To decrypt the message enter 2.\n");
        printf("To exit the program enter 3.\n");
        scanf("%d", &rot_option); //Stores the user's choice in the variable rot_option, which is an integer datatype.
    
        clrscr(); //Clears the screen once an appropriate choice from the sub menu has been made.


        if(rot_option == 1) //Executes if the user has entered 1 from the rotation cipher menu, signifying encryption.
    {
        printf("Please enter the message to be encrypted:\n"); //Prompts the user to type the message to be encrypted.
        while (getchar()!='\n'); //Clears the input buffer.
        scanf("%99[^\n]", text); //Stores input into the variable text, which is a string, [^\n] allows to read whitespace.
        
        for(int i = 0; i < 100; i++) //This loops converts the message to UPPER CASE, if needed.
    {
        text[i] = toupper(text[i]);
    }
        
        printf("Please enter the key:\n"); //Prompts the user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key); //Stores the value of the key in the variable key, which is an integer datatype.
  
        //Loop to check if the entered key is between 0 and 26.
        //If the key is 26, it implies no encryption.
        if (key <= -1 || key >= 27) 
    {
		printf("Error, please make sure the key is between 0 and 26\n"); //Displays an error message if the key is out of the range (0 - 26).
		return(0); //Exits the program due to error.
    }
        encrypt_text(text, key); //Call the function encrypt_text to encrypt the message.
        printf("The encrypted message is: %s\n", text); //Display the encrypted message.
    }
    
    
        if(rot_option == 2) //Executes if the user has entered 2 from the rotation cipher menu, signifying decryption.
    {
    
        printf("Please enter the message to be decrypted:\n"); //Prompts the user to type the message to be decrypted.
        while (getchar()!='\n'); //Clears the input buffer.
        scanf("%99[^\n]", text); //Stores input into the variable text, which is a string, [^\n] allows to read whitespace.
        
        for(int i = 0; i < 100; i++) //This loops converts the message to UPPER CASE, if required.
    {
        text[i] = toupper(text[i]);
    }
        
        printf("Please enter the key:\n"); //Prompts the user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key); //Stores the value of the key in the variable key, which is an integer datatype.
  
        //Loop to check if the entered key is between 0 and 26.
        if (key <= -1 || key >= 27) 
    {
		printf("Error, please make sure the key is between 0 and 26\n"); //Displays an error message if the key is out of the range (0 - 26).
		return 0; //Exits the program due to error.
    }
        decrypt_text(text, key); //Call function decrypt_text to decrypt message.
        printf("The decrypted message is: %s\n", text); //Display the decrypted message. 
    }
        
        
        if(rot_option == 3) //Executes if the user has entered 3 from the rotation cipher menu, signifying exiting the program.
    {
        return(0);   
    }
     
} //End of function.


 
//This function executes the subsituion cipher menu and its operations. 
//This method uses a fixed alphabetical substitution over the entire message. 
//The ciphertext alphabet may be a shifted, reversed or mixed version of the plaintext alphabet.
int sub()
{
        //Declare and or initialise variables.
        int sub_option;
        char text[100]; //Variable to store message.
        char cipher_alpbt[26] = {'H','G','Q','T','Y','P','L','J','M','D','W','I','Z','X','C','F','S','O','R','B','N','U','A','K','V','E'}; //The substitution cipher alphabet.

        //Displays the substitution cipher menu.
        printf("****Welcome to the Substitution Cipher menu****");
        printf("\nPlease choose the following options:\n");
        printf("To encrypt the message enter 1.\n");
        printf("To decrypt the message enter 2.\n");
        printf("To exit the program enter 3.\n");
        scanf("%d", &sub_option); //Stores the user's choice in the variable sub_option, which is an integer datatype. 
    
        clrscr(); //Clears the screen once an appropriate choice from the menu has been made.
        
        
        //Executes if the user has entered 1 from the substitution cipher menu, signifying encryption.
        if(sub_option == 1)
    {
        printf("Please enter the message to be encrypted\n"); //Prompts the user to type the message to encrypt.
        while (getchar()!='\n'); //Clears the input buffer.
        scanf("%99[^\n]", text); //Stores the input in the variable text, which is a string, [^\n] allows to read whitespace .
  
        char *encrypted_text = encrypt_sub(text, cipher_alpbt); //Calls the function encrypt_sub to decrypt the message.
        printf("The encrypted message is: %s\n", encrypted_text); //Display the encrypted message. 
    }
     
    
        //Executes if the user has entered 2 from the substitution cipher menu, signifying decryption. 
        if(sub_option == 2)
    {
    
        printf("Please enter the message to be decrypted\n"); //Prompts the user to enter a message to decrypt.
        while (getchar()!='\n'); //Clears the input buffer.
        scanf("%99[^\n]", text); //Stores the input in the variable text, which is a string, [^\n] allows to read whitespace.
  
        char *decrypted_text = decrypt_sub(text, cipher_alpbt); //Calls the function decrypt_sub to decrypt the message.
        printf("The decrypted message is: %s\n", decrypted_text); //Display the decrypted message. 
    }
     
     
        //Executes if the user has entered 3 from the subtitution cipher menu, signifying exiting from the program
        if(sub_option == 3)
    {
        return(0);
    }
     
} //End of function.


                    /********************The following are function definitions********************/        
    
//This function encrypts (rotation cipher) one single letter at a time, considering both lower case and upper case.
//It outputs a char datatype and takes inputs of a char and int datatypes.
char encrypt_ltr(char ltr, int key) //Function prototype.
{
        if (ltr >= 'A' && ltr <= 'Z') //Considers upper case letters.
    {
        ltr = ((ltr-'A') + key) % 26 + 'A'; //Encrypts a letter by adding the particular key to the ASCII value.
    }
        else if(ltr >= 'a' && ltr <= 'z') //Considers lower case letters.
    {
        ltr = ((ltr -'a') + key) % 26 + 'a'; //Encrypts a letter by adding the particular key to the ASCII value.
    }

        return ltr; //Returns the encrypted letters.
}


//This function encrypts (rotation cipher) a message, which consists of encrypting every letter of that message.
//It uses values from the previous function.
void encrypt_text(char text[], int key) //function prototype.
{
        //Declare and or initialise variables.
        int i = 0;
        char result;
  
        while (result = text[i]) //Entered message is encrypted using this loop.
    {
        result = encrypt_ltr(result, key); 
        text[i] = result; //The result of above calculation is now stored in the string text, which now contains the encrypted message.
        i++;
    }
}
    
    
//This function decrypts (rotation cipher) one single letter at a time, considering both lower case and upper case.
//It outputs a char datatype and takes inputs of a char and int datatypes.
char decrypt_ltr(char ltr, int key) //Function prototype.
{
        if (ltr >= 'A' && ltr <= 'Z') //Considers upper case letters.
    {
         ltr = ((ltr -'A') - key + 26) % 26 + 'A'; //Decrypts a letter by subtracting the particular key from the ASCII value.
    }                                             //26 is added to ensure that the value is positive before the modulo operator is applied.    
        else if(ltr >= 'a' && ltr <= 'z') //Considers lower case letters.
    {
        ltr = ((ltr -'a') - key + 26) % 26 + 'a'; //Decrypts a letter by subtracting the particular key from the ASCII value.
    }                                            //26 is added to ensure that the value is positive before the modulo operator is applied.

        return ltr; //Returns the decrypted letters.
}


//This function decrypts (rotation cipher) a message, which consists of decrypting every letter of that message.
//It uses values from the previous function.
void decrypt_text(char text[], int key) //Function prototype.
{
        //Declare and or initialise variables.
        int i = 0;
        char result;
  
        while (result = text[i]) //Entered message is encrypted using this loop.
    {
        result = decrypt_ltr(result, key); 
        text[i] = result; //The result of above calculation is now stored in the string text, which now contains the encrypted message.
        i++;
    }
}
    
    
//This function acquires the cipher index (substitution cipher) of each letter in the message.
//Used for both encryption and decryption of a substitution cipher.
//It outputs an int datatype and takes inputs of two variables both of which are char datatypes.
int locate_index(char cipher_alpbt[], char locate_ltr)
{
        for(int k = 0 ; k < 26; k ++)
    {
        if(cipher_alpbt[k] == locate_ltr) //Compares between the letters in the text and the substitution alphabet.
    {
        return k; //Returns the index.
    }
    }
        return -1;
} 
 
 
//This function encrypts (substitution cipher) the entered text.
//It outputs a char datatype and takes inputs of two variables both of which are char datatypes. 
//The asterisk after char implies a pointer to a character.
char* encrypt_sub(char *text, char cipher_alpbt[]) //Function prototype.
{
        int txtlength = strlen(text); //Acquire length of the text using the strlen function to know how many iterations is required.
        char* encrypted_text = (char *) malloc(sizeof(char)*txtlength); //malloc dynamically allocates space in memory, when size of memory required can vary.
       
        //Convert to characters to upper case 
        //'A' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
        for(int k = 0; k < txtlength; k++)
    {
        int encrypt_index = toupper(text[k]) - 'A'; //Converts to upper case.
        if(encrypt_index >= 0 && encrypt_index < 26)
    {
        encrypted_text[k] = cipher_alpbt[encrypt_index];
    }
        else
    {
        encrypted_text[k] = text[k]; 
    }
    }
        return encrypted_text; //Return the encrypted message.
}    
    
        
//This function decrypts (substitution cipher) the entered message.
//It outputs a char datatype and takes inputs of two datatypes both of which are char datatypes.
//The asterisk after char implies a pointer to a character.
char* decrypt_sub(char *text,char cipher_alpbt[]) //Function prototype. 
{ 
        int txtlength = strlen(text); // Acquire length of the text using the strlen function.
        char* decrypted_text = (char *) malloc(sizeof(char)*txtlength); //malloc dynamically allocates space in memory, when size of memory required can vary.
    
  
        //Convert to lower case as it is easier to work with only 26 letters, as opposed to both upper case and lower case.
        //'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
        for(int k = 0; k < txtlength; k++)
    {
        int decrypt_index = toupper(text[k]) - 'A'; //Converts to upper case.
        if(decrypt_index >= 0 && decrypt_index < 26)
    {
        int cipher_alpbt_index = locate_index(cipher_alpbt, toupper(text[k])); 
        decrypted_text[k] = 'A' + cipher_alpbt_index;
    }
        else
    {
        decrypted_text[k] = text[k];
    }
    }
    
    return decrypted_text; //Return the decrypted message.
}

                    /********************End of ENGG1003 Programming Assignment 1********************/
