#include <stdio.h>
#include"HeadFile.h"

void EncK(char message[], int key); //Function Prototype for the Function EncK (Encyption for K Rotation)
void DecK(char message[], int key); //Function Prototype for the Function DecK (Decryption for K Rotation)
void EncS(char message[], char key[]); //Function Prototype for the Function EncS(Encryption for Substitution)
void DecS(char message[], char key[]); //Function Prototype for the Function DecS(Decryption for Substitution)
void DecMinusK(char message[]); //Function Prototype for the Function DecMinusK(Decryption for K Rotation without K)

int main()
{
    char InputMessage[1024];//char to be used as the message input
    char SubKey[100]; //char to be used as the key input for substitution cipher
    int RotKey; //int used as the roation key for rotation cipher
    int ChoiceNumber; //number used to determine what function will be performed
    int ChoiceNumber2; //number used to determine if function will repeat
    REPEAT: //placeholder that is used by goto statment to repeat the choice selection if users wants to
    {
        //Brings the function to the top again to repeat
    }
    
    printf("Choose what Function you want to perfrom: \n ENTER 1: ENCRYPTION BY ROTATION \n ENTER 2: DECRYPTION FROM ROTATION \n ENTER 3: ENCRYPTION BY SUBSTITUTION \n ENTER 4: DECRYPTION FROM SUBSTITUTION \n");
    scanf("%d", &ChoiceNumber); //scans in ChoiceNumber that is used in the switch to determine which function is perfromed
    switch(ChoiceNumber) 
    {
        case 1: //occurs if number 1 is chosen
        printf("Enter in a message to be encrypted: \n");
        scanf("%[^\n]s", &InputMessage); //scans in message to be encrypted
        printf("Now enter a key for rotation: \n"); 
        scanf("%d", &RotKey); //scans in key to be used to encrypt
        EncK(InputMessage, RotKey); //performs the function Enck using the message and key and prints the encrypted message
        goto ProgramEnd; //goes to the end of the program
        case 2:
        printf("Enter in a message to be decrypted:  \n");
        scanf("%[^\n]s", &InputMessage);
        printf("Now enter the key used in the rotation encryption  \n");
        scanf("%d", &RotKey);
        DecK(InputMessage, RotKey); //perfroms the function DecK
        goto ProgramEnd;
        case 3:
        printf("Enter in a message to be encrypted:  \n");
        scanf("%[^\n]s", &InputMessage);
        printf("Enter in a new substitution 'alphabet' to encrypt to (enter all 26 letters in any order without repeating):  \n");
        scanf("%[^\n]s", &SubKey);
        EncS(InputMessage, SubKey);
        goto ProgramEnd;
        case 4:
        printf("Enter in a message to be decrypted:  \n");
        scanf("%[^\n]s", &InputMessage);
        printf("Enter in the substitution key used for encryption:  \n");
        scanf("%[^\n]s", &SubKey);
        DecS(InputMessage, SubKey);
        goto ProgramEnd;
        case 5:
        printf("Enter in a message to be decrypted:");
        scanf("%[^\n]s", &InputMessage);
        DecMinusK(InputMessage);
        goto ProgramEnd;
        default:
        printf("Invalid Input  \n");
        goto REPEAT;
    }
    ProgramEnd:
    {
        printf("Do you want to repeat this program?  \n ENTER 1: REPEATS PROGRAM  \n ENTER ANY OTHER NUMBER: ENDS PROGRAM \n");
        scanf("%d", &ChoiceNumber2);
        if(ChoiceNumber2 == 1)
        {
            goto REPEAT;
        }
        else
        {
            //end programm
        }
        printf("Program Ended  :) \n");
        return 0;   
    }
}