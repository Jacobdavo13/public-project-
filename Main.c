#include <stdio.h>
#include"HeadFile.h" //includes the file that contains the functions listed below/their function definitions
/*This code scans in messages and keys through scanf.
Using the terminal enter "cd /projects/p" and then hit the tab button followed by enter.
Then in the terminal enter "ls" and hit enter
Then in the terminal enter "./a" and hit the tab button followed by enter
This will start the program and it can then be run on the terminal and values can be scanned in.
If you want to encrypt a message using a rotation cipher 1 must be entered.
This will prompt the user to enter the message to be encrypted followed by the key for rotation
This will then print the encrypted message to the screen
If you want to decrypt an encrypted message encrypted with a known rotation cipher 2 must be entered
This will prompt the user to enter the encrypted message followed by key used for encryption
This will then print the decryted/original message to the screen
If you want to encrypt a message using a substitiution cipher 3 must be entered.
This will prompt you to enter a message for encryption followed by a new 26 letter alphabet, you must ensure you enter 26 letters with no repeating letters
This will then transfrom every corresponding letter of the alphabet into the keys alphabet.
eg Alphabet =  ABCDEFGHIJKLMNOPQRSTUVWXYZ
               ||||||||||||||||||||||||||
   Key      =  QWERTYUIOPASDFGHJKLZXCVBNM
   So, A goes to Q, B goes to W....
This will then print the encrypted message to the screen
If you want to decrypt a message encrypted with a known substitution cipher 4 must be entered.
This will prompt you to enter the encrypted message followed by the 26 letter key.
This will then use the key to transform every letter back into its original letter before encryption
This will then print the decrypted message to the screen.
If you want to decrypt a message encrypted with an unknown rotation cipher 5 must be entered.
This will prompt you to enter the encrypted message. Using the assumption that every single letter word is an A or I it will decrypt the message
This will then print Decrypted for A and the decrypted message if A was used to find the key or print Decrypted for I and the decrypted message if I was used to find the key.
After a function is finished entering 1 will go back to the start so another message can be entered and processed.
Any other character or symbol here will end the program
This program will automatically convert any enter lower case letters into upper case letters and does not decrypt/encrypt symbols or punctuation
 */

void EncK(char* message, int key); //Function Prototype for the Function EncK (Encyption for K Rotation)
/*This function is used to encrypt a given message using a rotation cipher. This means that every letter rotates a certain defined amount of places
This function takes a message and a key for number of places rotated and ecnrypts a message.
For example, if the key was 1 and the message was "ABC", the encrypted message would come out as "BCD".
*/
void DecK(char* message, int key); //Function Prototype for the Function DecK (Decryption for K Rotation)
/*This function is used to decrypt a message that has been encrypted using a rotation cipher.
It takes the inputted message and the key used for encryption and moves the letters back to their original places and produces the original message
For example, if the key used was 1 and the message encrypted is "BCD" then the decrypted message comes out as "ABC" 
*/
void EncS(char* message, char* key); //Function Prototype for the Function EncS(Encryption for Substitution)
/*This function is used to encrypt a given message using a substitution cipher. Substitution means that every letter becomes another letter without doubling up.
This means if A goes to H then nothing else can go to H and every A in the message is turned into a H. This is done for every letter in the message.
 */
void DecS(char* message, char* key); //Function Prototype for the Function DecS(Decryption for Substitution)
/*This function is used to decryot an encrypted message that was encrypted using a substitiution cipher.
This function takes the key and uses the given alphabet to take every encrypted letter back to the original value
 */
void DecMinusK(char* message); //Function Prototype for the Function DecMinusK(Decryption for K Rotation without K)
/*This function takes a message encrypted using a roation cipher, without a given key, and decrypts it.
This function finds the first single letter word and assumes it is A and makes the encryption key from there. It uses this to decrypt the message.
This decrypted message is then error checked to ensure that every single letter word is either A or I as the first letter that the program came across may not have been A and thus other letters may be incorrect
If it detects that a single letter word is not A or I than it re-decrypts the original message using I as the first letter and prints this instead.
*/
int main()
{
    char InputMessage[4024];//char to be used as the message input
    char SubKey[100]; //char to be used as the key input for substitution cipher
    int RotKey; //int used as the roation key for rotation cipher
    int ChoiceNumber; //number used to determine what function will be performed
    int ChoiceNumber2; //number used to determine if function will repeat
    REPEAT: //placeholder that is used by goto statment to repeat the choice selection if users wants to
    {
        //Brings the function to the top again to repeat
    }
    
    printf("Choose what Function you want to perfrom: \n ENTER 1: ENCRYPTION BY ROTATION \n ENTER 2: DECRYPTION FROM ROTATION \n ENTER 3: ENCRYPTION BY SUBSTITUTION \n ENTER 4: DECRYPTION FROM SUBSTITUTION \n ENTER 5: DECRYPTION OF ROTATION WITHOUT KEY \n");
    scanf("%d", &ChoiceNumber); //scans in ChoiceNumber that is used in the switch to determine which function is perfromed
    switch(ChoiceNumber) 
    {
        case 1: //occurs if number 1 is chosen
        printf("Enter in a message to be encrypted: \n");
        scanf(" %[^\n]s", InputMessage); //scans in message to be encrypted
        printf("Now enter a key for rotation: \n"); 
        scanf("%d", &RotKey); //scans in key to be used to encrypt
        EncK(InputMessage, RotKey); //performs the function Enck using the message and key and prints the encrypted message
        goto ProgramEnd; //goes to the end of the program
        case 2:
        printf("Enter in a message to be decrypted:  \n");
        scanf(" %[^\n]s", InputMessage); //Scans a message in. The [^\n] is used so that scanf can scan in white space such as spaces
        printf("Now enter the key used in the rotation encryption  \n");
        scanf("%d", &RotKey);
        DecK(InputMessage, RotKey); //perfroms the function DecK
        goto ProgramEnd;
        case 3:
        printf("Enter in a message to be encrypted:  \n");
        scanf(" %[^\n]s", InputMessage);
        printf("Enter in a new substitution 'alphabet' to encrypt to (enter all 26 letters in any order without repeating):  \n"); 
        scanf(" %[^\n]s", SubKey);
        EncS(InputMessage, SubKey);
        goto ProgramEnd;
        case 4:
        printf("Enter in a message to be decrypted:  \n");
        scanf(" %[^\n]s", InputMessage);
        printf("Enter in the substitution key used for encryption:  \n");
        scanf(" %[^\n]s", SubKey);
        DecS(InputMessage, SubKey);
        goto ProgramEnd;
        case 5:
        printf("Enter in a message to be decrypted:\n");
        scanf(" %[^\n]s", InputMessage);
        DecMinusK(InputMessage);
        goto ProgramEnd;
        default: //this occurs if 1-5 are not scanned in. This repeats the program and tells the user that the input is invalid
        printf("Invalid Input  \n");
        goto REPEAT; //moves to the top of the switch case to repeat
    }
    ProgramEnd: //Label that is moved to once one of the switch cases has been entered
    {
        printf("Do you want to repeat this program?  \n ENTER 1: REPEATS PROGRAM  \n ENTER ANY OTHER NUMBER: ENDS PROGRAM \n");
        scanf("%d", &ChoiceNumber2); //scans another number in
        if(ChoiceNumber2 == 1) //only works if  ChoiceNumber2 is 1 and goes to the top of the switch case to repeat it again
        {
            goto REPEAT;
        }
        else //if ChoiceNumber2 isn't 1 then program ends
        {
            //end programm
        }
        printf("Program Ended  :) \n");
        return 0;   
    }
}