#include <stdio.h>
#include"HeadFile.h"

void EncK(char message[], int key); //Function Prototype for the Function EncK (Encyption for K Rotation)
void DecK(char message[], int key); //Function Prototype for the Function DecK (Decryption for K Rotation)
void EncS(char message[], char key[]); //Function Prototype for the Function EncS(Encryption for Substitution)
void DecS(char message[], char key[]); //Function Prototype for the Function DecS(Decryption for Substitution)

int main()
{
    char InputMessage[1024];
    char SubKey[1024];
    int RotKey;
    int ChoiceNumber;
    int ChoiceNumber2;
    REPEAT:
    {
        //Brings the function to the top again to repeat
    }
    
    printf("Choose what Function you want to perfrom: \n ENTER 1: ENCRYPTION BY ROTATION \n ENTER 2: DECRYPTION FROM ROTATION \n ENTER 3: ENCRYPTION BY SUBSTITUTION \n ENTER 4: DECRYPTION FROM SUBSTITUTION \n");
    scanf("%d", &ChoiceNumber);
    switch(ChoiceNumber)
    {
        case 1:
        printf("Enter in a message to be encrypted: \n");
        scanf("%s", &InputMessage);
        printf("Now enter a key for rotation: \n");
        scanf("%d", &RotKey);
        EncK(InputMessage, RotKey);
        goto ProgramEnd;
        case 2:
        printf("Enter in a message to be decrypted:  \n");
        scanf("%s", &InputMessage);
        printf("Now enter the key used in the rotation encryption  \n");
        scanf("%d", &RotKey);
        DecK(InputMessage, RotKey);
        goto ProgramEnd;
        case 3:
        printf("Enter in a message to be encrypted:  \n");
        scanf("%s", &InputMessage);
        printf("Enter in a new substitution 'alphabet' to encrypt to (enter all 26 letters in any order without repeating):  \n");
        scanf("%s", &SubKey);
        EncS(InputMessage, SubKey);
        goto ProgramEnd;
        case 4:
        printf("Enter in a message to be decrypted:  \n");
        scanf("%s", &InputMessage);
        printf("Enter in the substitution key used for encryption:  \n");
        scanf("%s", &SubKey);
        DecS(InputMessage, SubKey);
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