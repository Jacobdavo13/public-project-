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
    printf("Choose what Function you want to perfrom: \n ENTER 1: ENCRYPTION BY ROTATION \n ENTER 2: DECRYPTION FROM ROTATION \n ENTER 3: ENCRYPTION BY SUBSTITUTION \n ENTER 4: DECRYPTION FROM SUBSTITUTION \n");
    scanf("%d\n", &ChoiceNumber);
    switch(ChoiceNumber)
    {
        case 1:
        printf("Enter in a message to be encrypted:");
        scanf("%s\n", &InputMessage);
        printf("Now enter a Key for Rotation");
        scanf("%d\n", &RotKey);
        EncK(InputMessage, RotKey);
        break;
        case 2:
        //DecK
        break;
        case 3:
        //EncS
        break;
        case 4:
        //DecS
        break;
    }
}



