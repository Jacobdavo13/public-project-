#include <stdio.h>
char EncK(char message[], int key); 
int main()
{
    char message[] = "aAbBcC";
    int key =  100;
    EncK(message, key);
}
 
char EncK(char message[], int key)
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
     printf("Your encrypted message is: %s\n", message);
     return 0;
}
