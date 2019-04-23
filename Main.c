#include <stdio.h>
void EncK(char message[], int key); //Function Prototype for the Function EncK (Encyption for K)
int main()
{
    char message[] = "aAbBcC"; //This is the inputted message that will be Encrypted
    int key =  100; 
    /* Int key is the key for the encryption.
    This key dictates the movement of every letter in the Rotation Cipher Encryption.
    For Example; if the key is 1 every letter moves 1 space.
    For one space any inputted A is outputted as a B and inputted B is outputted as a C and so on.
    */
    EncK(message, key);//Function taking the message and key and encrypting the message
    
}

/* The inputs for this functions are a char and an int.
The char (character) input is the message to be encrypted in English Letter that can be upper or lower case.
The int (interger) input is the key and is the amount of spaces each letter rotates.
The return value is void as this function does not return a value but rather prints the new encrypted message.
The function performs a rotation cipher on an inputted message.
A rotation cipher is a means for encrypting messages that rotates the alphabet used within the message.
This means that every letter moves a predetermined amount of spaces through the alphabet.
This means if the rotation key is 1 A=B, B=C, ....., Z=A.

– Are there limitations to the function? Must strings be less than a certain length? Are there data
type restrictions? etc
 */
void EncK(char message[], int key)
{
     printf("Inputted message was: %s\n", message);
     int index = 0;
     for(index = 0; message[index] != 0; index++)
     {
         if(message[index] >= 97 && message[index] <= 122)
         {
             message[index] = message[index] - 32;
         }
     }
     for(index = 0; message[index] !=0; index++)
     {
         if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122))
         {
       //do nothing to any punctuation  
         }
         else
         {
             message[index] = ((message[index] - 65) + key ) % 26 + 65;
         }
         
     }
     printf("The Encrypted message is: %s\n", message);
}
