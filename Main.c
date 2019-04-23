#include <stdio.h>
void EncK(char message[], int key); //Function Prototype for the Function EncK (Encyption for K)
int main()
{
    char message[] = "wWxXyY"; //This is the inputted message that will be Encrypted
    int key =  100; 
    /* key is the key for the encryption.
    This key dictates the movement of every letter in the Rotation Cipher Encryption.
    For Example; if the key is 1 every letter moves 1 space.
    This means that if key =  1 then A becomes B.
    */
    EncK(message, key);//Function taking the message and key and encrypting the message
    
}

/* The function EncK encrypts a message using a rotation cipher
The char (character) input is the message to be encrypted in English Letter that can be upper or lower case.
The int (interger) input is the key and is the amount of spaces each letter rotates.
The return value is void as this function does not return a value but rather prints the new encrypted message.
The function performs a rotation cipher on an inputted message.
A rotation cipher is a means for encrypting messages that rotates the alphabet used within the message.
This means that every letter moves a predetermined amount of spaces through the alphabet.
This means if the rotation key is 1 A=B, B=C, ....., Z=A.
Strings can be of any length to be used in this function as long as they are not too long for the computer to process.
The key inputted must be postivie otherwise the function will not produce the correct encrypted values.
Although positive encryption can be used to get the same encryption value as a negative key.
Eg. If key = -1 then B=A and if key = 25 B=A.
Punctiation and other symbols are not encrypted, only letters.
Lowercase letters are transformed into upper case letter.
 */
void EncK(char message[], int key) //Function definition
{
     printf("Inputted message was: %s\n", message); //This prints the original message so it can be reviewed
     int index; //declares a varibale index that will be used as the pointer for the message array to point at individual letters.
     for(index = 0; message[index] != 0; index++) //starts a for loop that declares index as 0 and if message[index] does not equal 0 it will continue to loop
     //When it reaches the end of the loop it repeats and increases the index. This will stop once the index reaches the end of the array.
     {
         if(message[index] >= 97 && message[index] <= 122) //checks to see if any characters used are lower case letters.
         {
             message[index] = message[index] - 32; //if they are lower case letters -32 turns them into upper case (as seen on ASCII table)
         }
     }
     for(index = 0; message[index] !=0; index++) //performs the same as the for loop above, cycles through the message until the end.
     {
         if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //this if statement determines if characters used are punctuation or symbols
         {
       //do nothing to punctuation or symbols 
         }
         else //perform this loop on letters
         {
             message[index] = ((message[index] - 65) + key ) % 26 + 65; 
 /*the message[index] - 65 is used to assign the letters of the alphabet a number between 0 and 25
 The key is then added to move this value up and then the modulus of this new value is taken (the remainder of the division of the number by 26) and 65 is added to produce the new ASCII value
 this modulus is used to ensure that no matter how high the key is, the produced value will not exceed 25 and the produce ASCII value does not exceed 90. The remainder of the division of a number by 26 can only be between 0 and 25.
 For example message[index] = 65 and key = 100, 65 - 65 = 0, 0 + 100 = 100, 100 % 26 = 22, 22 + 65 = 87, 87 = W.
 this equation sets every character in the array to a new encrypted character
 */
         }
         
     }
     printf("The Encrypted message is: %s\n", message); //new encrypted message is printed
} //no return value as function produces a void return value
