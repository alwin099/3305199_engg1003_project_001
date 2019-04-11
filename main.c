#include <stdio.h>

int main()
{

//Declare variables
int i, option, key; // i = counter, option = to encrypt or to decrypt, key = rotation amount.
char message[100]; //string to store message.


//Display menu of options.
printf("\nPlease choose the following options:\n");
printf("To encrypt the message enter 1.\n");
printf("To decrypt the message enter 2.\n");
scanf("%d", &option); //store option as an integer in the variable option.


//Selection of options.
switch(option)

{
    //Executes if user has entered 1, signifying encryption
    case 1:
    {
        printf("Please enter the message to encrypt:\n"); //Prompts user to enter message to encrypt.
        scanf("%s", &message); // store message as a string in the variable message.
        
        printf("Please enter the key\n"); //Prompts user to enter the key, which dictates the roation amount
        scanf("%d", &key); //Store the rotation amount as an integer in the variable key.
        
      for (i = 0; message[i] != '\0'; i++)
      {
          message[i] = message[i] + key;
          if (message[i] > 'z')
              message[i] = message[i] - 26;
      }
      printf("The encrypted message is: %s\n", message); //Display encrypted message.
      break;
      
    //Executes if the user has entered 2, signifying decryption.
    case 2:
    
        printf("Please enter the message to decrypt\n"); //Prompts user to enter message to decrypt.
        scanf("%d", &message); // store message as a string in the variable message.
        
        printf("Please enter the key\n"); //Prompts user to enter the key, which dictates the roation amount
        scanf("%d", &key); //Store the rotation amount as an integer in the variable key.
        
        for (i = 0; message[i] != '\0'; i++)
        {
            message [i] = message[i] - shift;
            if (message[i] > 'z')
               message[i] = message[i] - 26;
        }
        printf("the decrypted message is: %s\n" message); // Display encrypted message.
        break;
        
        
        // Executes if none of the possible options is entered. 
        default:
        printf("An error has occured\n"); //Displays "An error as occurred"
        
    
}   









    return 0;
}


