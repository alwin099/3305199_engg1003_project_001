#include <stdio.h>

/* ENGG1003 Programming Assignment 1
*  Name: Alwin Wilson
*  Student number: 3305199
*  Date: 29/4/19
*  Description: Encrypts and decrypts a message using the substitution cipher (Caesar cipher) method.*/

int main()
{

//Declare variables
int i, option, key; // i = counter, option = 1 to encrypt or 2 to decrypt or 3 to exit the program, key = amount by which the alphabet is shifted.
char message[100]; //string to store message.


//Display menu of options.
printf("*****Welcome to the Caesar Cipher program****");
printf("\nPlease choose the following options:\n");
printf("To encrypt the message enter 1.\n");
printf("To decrypt the message enter 2.\n");
printf("To exit the program enter 3.\n");
scanf("%d", &option); //store option as an integer in the variable option.



//Selection of options.
switch(option)

{
    //Executes if user has entered 1, signifying encryption
    case 1:
    {
        printf("Please enter the message to encrypt:\n"); //Prompts user to enter message to encrypt.
        scanf(" %[^\n]s", message); // store message as a string in the variable message.
        
        printf("Please enter the key:\n"); //Prompts user to enter the key, which dictates the roation amount
        scanf("%d", &key); //Store the rotation amount as an integer in the variable key.
    
        //Checks if the key is a valid value. If not, terminates program with error message.
        if (key <= 0 || key >= 26) {
		printf("Error, please make sure the key is between 0 and 26");
		return 0;
	    }

      for (i = 0; (i < 100 && message[i] != '\0'); i++)
        {
          message[i] = message[i] + key; //encrypts the message by adding the particular key to the ASCII value.
          if (message[i] > 'z')
              message[i] = message[i] - 26;
        }
      printf("The encrypted message is: %s", message); //Display encrypted message.
      break;
    } 
     
      
    //Executes if the user has entered 2, signifying decryption.
    case 2:
    {
        printf("Please enter the message to decrypt:\n"); //Prompts user to enter message to decrypt.
        scanf(" %[^\n]s", message); // store message as a string in the variable message.
        
        printf("Please enter the key:\n"); //Prompts user to enter the key, which dictates the rotation amount.
        scanf("%d", &key); //Store the rotation amount as an integer in the variable key.
        
        //Checks if the key is a valid value. If not, terminates program with an error message.
        if (key <= 0 || key >= 26)
        {
		printf("Error, please make sure the key is between 0 and 26");
		return 0;
        }
        
      for (i = 0; (i < 100 && message[i] != '\0'); i++)
        {
          message[i] = message[i] - key; //encrypts the message by adding the particular key to the ASCII value.
          if (message[i] > 'z')
              message[i] = message[i] + 26;
        }
        
        printf("The decrypted message is: %s\n", message); // Display encrypted message.
        break;
    }
        
        //Executes if the user has entered 3, signifying desire to exit the program.
        case 3:
    {
        return(0);
        break;
    }
        
        // Executes if none of the possible options are entered. 
        default:
    {
        printf("Please choose a valid option\n"); //Displays if the user has not entered 1 or 2
    }
    
}  
 return 0;
}















