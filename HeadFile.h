#ifndef VARIABLE
#define VARIABLE

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
} 


//Function for Decrypting rotational cipher
/*The function DecK perfroms a rotation cipher decryption on an inputted char string of characters
The char input is a string of inputted characters that has been encrypted using a rotation cipher
The int input is the key and is the amount of spaces that the encrypted letters have rotated from their original values (Eg. if A goes to B then key = 1)
It returns a void value as this function prints the decrypted message string.
This function takes an encrypted message and the rotation key used for encryption and decrypts the message by moving the letter back to their original places
This means that if the enecryption key used was 1 then the letter B decrypted would be A
This function does not have any data type restrictions but string length is limited to how much the computer/website can take without crashing
 */
void DecK(char message[], int key) 
{
    printf("Inputted message was: %s\n", message);
    if(key>26) //used if key is too large which will create ASCII charaters that are not letters
    //Example if key = 100 and message[index] = 65 (equation below), 65 - 65 = 0, 0 - 100 + 26 = -74, -74 % 26 = -22, -22 + 65 = 43 which is not an upper case ASCII charater 
    {
        key = key % 26; //key by %26 makes sure the value of key is changed to the remainder of key/26 which is between 0 to 25.
    }
    int index; //declares a pointer to be used later
    for(index = 0; message[index] != 0; index++) //sets up a for loop to run through every character in the array
    {
        if(message[index] >= 97 && message[index] <= 122) //if statement determines if letters are lower case
        {
            message[index] = message[index] - 32; // if letters are lower case -32 changes them to upper case
        }
    }
    for(index = 0; message[index] !=0; index++) //for loop 
    {
        if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
        {
            //do nothing to any punctuation  
        }
        else //if the characters are upper case letters this occurs
        {
            message[index] = ((message[index] - 65) - key + 26) % 26 + 65; //turning the ASCII character to a number between 0 and 25 through -65 and then taking away the key to move the letter back to where it was before it was encrypted
//+26 was done to ensure that when key is taken away from the value it still produces a value that is postive and can be used by the function
//modulus 26 makes produces the remainder of the created value divided by 26 and 65 is added to produce a the decrypted ASCII value
        }
         
    }
    printf("This message decrypted is: %s\n", message); //prints the decrypted message
}


/*The function EncS encrypts a message using a substitution cipher
The char input message is the inputted message for encryption
The char input key is the new 'alphabet' that the encryption uses such that each letter of alphabet is changed to the corresponding letter in the key
This means that if the first letter of the key is Z, every A will be encrypted into a Z
This function has a return value of void as it prints the encrypted message instead of returning it
This function will not encrypt symbols or numbers and only encrypts lower and upper case letters, and will also only produce upper case letter outputs
 */
void EncS(char message[], char key[])
{  
    printf("message was: %s\n", message); //prints original message for review
    int index; //intialised interger to be used as pointer through message array
    for(index = 0; message[index] != 0; index++) //for loop that cycles through each character until message[index] == 0 then stops
    {
        if(message[index] >= 97 && message[index] <= 122) //if loop that only works on lower case letter, which are within these two inequalities
        {
            message[index] = message[index] - 32; // -32 sets lower case letters into upper case letters
        }
    }
    for(index = 0; message[index] != 0; index++) //for loop to cycle through message again now that it is all upper case letters
    {   
        switch (message[index]) //switch case to change the letters to the alphabet of the key, 
        {   
            case 65: //A=65, this case occurs if the message[index] is A and turns this A into the first letter in the new key alphabet
            message[index] = key[0]; //assigns the letter A to the first character in the key
            break; //breaks out of the switch and loops back through the for loop to the next character
            case 66: //B=66, this case occurs if message[index] is B and turns the B into the second character in the new key
            message[index] = key[1];
            break;
            case 67: 
            message[index] = key[2];
            break;
            case 68:
            message[index] = key[3];
            break;
            case 69: 
            message[index] = key[4];
            break;
            case 70:
            message[index] = key[5];
            break;
            case 71: 
            message[index] = key[6];
            break;
            case 72:
            message[index] = key[7];
            break;
            case 73: 
            message[index] = key[8];
            break;
            case 74:
            message[index] = key[9];
            break;
            case 75:
            message[index] = key[10];
            break;
            case 76:
            message[index] = key[11];
            break;
            case 77: 
            message[index] = key[12];
            break;
            case 78:
            message[index] = key[13];
            break;
            case 79: 
            message[index] = key[14];
            break;
            case 80:
            message[index] = key[15];
            break;
            case 81: 
            message[index] = key[16];
            break;
            case 82:
            message[index] = key[17];
            break;
            case 83: 
            message[index] = key[18];
            break;
            case 84:
            message[index] = key[19];
            break;
            case 85:
            message[index] = key[20];
            break;
            case 86: 
            message[index] = key[21];
            break;
            case 87:
            message[index] = key[22];
            break;
            case 88: 
            message[index] = key[23];
            break;
            case 89:
            message[index] = key[24];
            break;
            case 90:
            message[index] = key[25];
            break;    
        }
   
    }         
    printf("Your Encrypted message is: %s\n", message); //prints the new encrypted message
}


/*The DecS function decrypts a given message that has been encrypted using a substitution cipher, using the given message and substition key
The char message[] input is the encrypted message that is to be decrypted by the fucntion
The char key[] input is the substitution alphabet that was used to encrypt the original message, eg if the first letter in the key is B then every A will turn to a B
The return value is void as it does not return a value but rather prints the decrypted message
String length is limited only by the computer and websites processing power and only letters are decrypted 
*/
void DecS(char message[], char key[]) //function definition
{
    int index; //initalises a pointer to be used to cycle through message array
    char let[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //initalises an alphabet array used to decrypt the message back to its original value
    printf("This was the message: %s\n", message); //prints original message for review
    for(index = 0; message[index] != 0; index++) //sets up a for loop that cycles through the message until the end character
    {
        if(message[index] >= 97 && message[index] <= 122) //if loop that occurs if the charaters are lower case
        {
            message[index] = message[index] - 32; // -32 changes from upper to lower case
        }
    }
    for(index = 0; message[index] != 0; index++) //cycles through new fully upper case message until the end
    {
        if(message[index]==key[0]) //if statement that occurs if the message[index] equals the first letter of the key string
        {
            message[index] = let[0]; //if the message[index] equals the first letter of the key string it is set to the first letter of the alphabet to revert it back to it's orignal value
            goto LOOPEND; //goes to the end of the for loop so that the for loop repeats
            //a break here could not be used as it only breaks out of the if statement which will ruin the decryption as it may occur in another if statment
            // for example if N is the first key character it will be set to A, this may repeat if breaks are used as A may be a condition for another if statment below this one which will decrypt it twice and ruin the decryption 
        }
        if(message[index]==key[1]) //occurs if the message[index] is equal to the second letter of the key
        {
            message[index] = let[1]; //sets the message[index] to B
            goto LOOPEND; //goes to the end to repeat the for loop
        }
        if(message[index]==key[2])
        {
            message[index] = let[2];
            goto LOOPEND;
        }
        if(message[index]==key[3])
        {
            message[index] = let[3];
            goto LOOPEND;
        }
        if(message[index]==key[4])
        {
            message[index] = let[4];
            goto LOOPEND;
        }
        if(message[index]==key[5])
        {
            message[index] = let[5];
            goto LOOPEND;
        }
        if(message[index]==key[6])
        {
            message[index] = let[6];
            goto LOOPEND;
        }
        if(message[index]==key[7])
        {
            message[index] = let[7];
            goto LOOPEND;
        }
        if(message[index]==key[8])
        {
            message[index] = let[8];
            goto LOOPEND;
        }
        if(message[index]==key[9])
        {
            message[index] = let[9];
            goto LOOPEND;
        }
        if(message[index]==key[10])
        {
            message[index] = let[10];
            goto LOOPEND;
        }
        if(message[index]==key[11])
        {
            message[index] = let[11];
            goto LOOPEND;
        }
        if(message[index]==key[12])
        {
            message[index] = let[12];
            goto LOOPEND;
        }
        if(message[index]==key[13])
        {
            message[index] = let[13];
            goto LOOPEND;
        }
        if(message[index]==key[14])
        {
            message[index] = let[14];
            goto LOOPEND;
        }
        if(message[index]==key[15])
        {
            message[index] = let[15];
            goto LOOPEND;
        }
        if(message[index]==key[16])
        {
            message[index] = let[16];
            goto LOOPEND;
        }
        if(message[index]==key[17])
        {
            message[index] = let[17];
            goto LOOPEND;
        }
        if(message[index]==key[18])
        {
            message[index] = let[18];
            goto LOOPEND;
        }
        if(message[index]==key[19])
        {
            message[index] = let[19];
            goto LOOPEND;
        }
        if(message[index]==key[20])
        {
            message[index] = let[20];
            goto LOOPEND;
        }
        if(message[index]==key[21])
        {
            message[index] = let[21];
            goto LOOPEND;
        }
        if(message[index]==key[22])
        {
            message[index] = let[22];
            goto LOOPEND;
        }
        if(message[index]==key[23])
        {
            message[index] = let[23];
            goto LOOPEND;
        }
        if(message[index]==key[24])
        {
            message[index] = let[24];
            goto LOOPEND;
        }
        if(message[index]==key[25])
        {
            message[index] = let[25];
            goto LOOPEND;
        }       
        LOOPEND: //end of the loop where the goto statments are sent to, this is done to repeat the loop without further decrypting already decrypted letters
        {
            //repeats loop
        }
    }
    printf("The Decrypted Message is:  %s\n", message); //prints the decrypted message
}

void DecMinusK(char message[])
{
    char message2[1028]; //message2 used if original decryption is incorrect. It saves the original encrypted message so it can be decrypted a second time
    int key; //interger used to determine the key of the rotation
    int index; //pointer
    int Newindex; //index that is used to determine the character two spaces ahead of the index
    int Keyindex; //index that is used to determine the character one space ahead of the index
    for(index = 0; message[index] != 0; index++) //starts a for loop that declares index as 0 and if message[index] does not equal 0 it will continue to loop
    //When it reaches the end of the loop it repeats and increases the index. This will stop once the index reaches the end of the array.
    {
        if(message[index] >= 97 && message[index] <= 122) //checks to see if any characters used are lower case letters.
        {
            message[index] = message[index] - 32; //if they are lower case letters -32 turns them into upper case (as seen on ASCII table)
        }
    }
    for(index = 0; message[index] !=0; index++)//sets up loop that runs through every element of the array
    {
        message2[index] = message[index]; //sets every element of message2 to the same as message inputted
    }
    for(index = 0; message[index] != 0; index++) //loops through message
    {
        if(message[index] == 32) //if message[index] is a space character(ASCII value for *space* is 32)
        {
            Newindex = index + 2; //an index that is two places ahead of the present index
            Keyindex = index + 1; //index one place ahead of present index   
            if(message[Newindex] == 32) //if the element 2 spaces ahead of the present index is also a space this means it is a one letter word (either A or I)
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol the key is not determined from this 
                {
                    //do nothing for symbols
                }
                else //if the lone character is a letter
                {
                    key = message[Keyindex] - 65; //uses this one letter word minus 65 to determine the places that the letter has been rotated from A (if this letter is found to be I it is corrected later)
                    goto decrypt; //jumps to the decrypt statement and thus exits loop 
                }
            }
        }
    }
    decrypt: //placeholder that the goto statment jumps to
    {
        for(index = 0; message[index] !=0; index++) //for loop that rotates through the message
        {
            if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
            {
                //do nothing to any punctuation  
            }
            else //if the characters are upper case letters this occurs
            {
                message[index] = ((message[index] - 65) - key + 26) % 26 + 65;  //decrypts all letters for the new key and turns them back into their original letters (only if first single letter word detected was A) 
            }
        }
        
        for(index = 0; message[index] != 0; index++) //this is another for loop cycling through the message to detect if decryption has happened correctly, if it decrypted correctly every single letter word will be either A or I
        {
            Newindex = index + 2; 
            Keyindex = index + 1;
            if(message[index] == 32 && message[Newindex] == 32) //if the present index and the index 2 ahead are spaces then it is a one letter word
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol it is not further decrypted 
                {
                    //do nothing
                }
                
                else if(message[Keyindex] == 65 || message[Keyindex] == 73) //if the one letter word is either A(65) or I(73) than it does not need to be corrected as decryption was sucessful
                {
                    // do nothing
                }
                else //if the one letter word was not A or I then the fist detected one letter word was not A but I and the message will be decrypted again correctly instead
                {
                    goto ReDecrypt; //goes to the statement that will redecrypt using I to find the key instead of A
                }
            }

        } //end of for loop
    } //end of decrypt section
    goto PrintForA; //if the message was correctly decrypted, this occurs. This moves to a position such that the code below this does not occur to redecrypt for I and rather it prints the decrypted message
    ReDecrypt: //redecrypt that occurs if decryption using A failed
    {
        for(index = 0; message2[index] != 0; index++) //loops through message
        {
            if(message2[index] == 32) //if message[index] is a space character(ASCII value for *space* is 32)
            {
                Newindex = index + 2; //an index that is two places ahead of the present index
                Keyindex = index + 1; //index one place ahead of present index   
                if(message2[Newindex] == 32) //if the element 2 spaces ahead of the present index is also a space this means it is a one letter word (either A or I)
                {
                    if((message2[Keyindex] < 65) || (message2[Keyindex] > 90 && message2[Keyindex] < 97) || (message2[Keyindex] > 122)) //if the one letter is not a letter but a symbol the key is not determined from this 
                    {
                        //do nothing for symbols
                    }
                    else //if the lone character is a letter
                    {
                        key = message2[Keyindex] - 73; //uses this one letter word minus 73 to determine the places that the letter has been rotated from I and not A
                        goto decrypt2; //jumps to the decrypt2 statement and thus exits loop 
                    }
                }
            }
        }
    } //end of redecrypt 
    decrypt2: //placeholder used to jump out of for and if loops and decrypt for I
    {
        for(index = 0; message2[index] !=0; index++) //for loop cycles through message2 (which is the original message)
        {
            if(( message2[index] < 65) || (message2[index] > 90 && message2[index] < 97) || (message2[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
            {
                //do nothing to any punctuation  
            }
            else //if the characters are upper case letters this occurs
            {
                message2[index] = ((message2[index] - 65) - key + 26) % 26 + 65; //decrypts using the determined key and changes every letter back to its original value 
            }
        }
        printf("Decrypted using I: %s\n", message2); //occurs if redecrypted for I. Message2 gets printed
    }
    goto final; //skips over the PrintForA statement as it was incorrect decryption. Jumps over it to the end so that it does not occur
    PrintForA: //occurs if decryption for A was correct and prints the decrypted message
    {
        printf("Decrypted using A: %s\n", message); //prints decrypted message
    }
    final: //used to skip over PrintForA if decryption using A was incorrect. Does nothing
    {
        //nothing    
    }
}
#endif