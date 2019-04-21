#include <stdio.h>
char enc(char b[], int k);
int main()
{
    char message[] = "JACOB";
    int key =  1;
enc(message, key);
return 0;
}
 
 char enc(char b[], int k)
 {
 int index;
 for(index = 0; b[index] !=0; index++){
     if(( b[index] < 65) || (b[index] > 90 && b[index] < 97) || (b[index] > 122)) {
       //do nothing to any punctuation  
     }
     else{
         b[index] = ((b[index] - 65) + k ) % 26 + 65;
     }
         
 }
 printf("encrypted message is %s\n", b);
 return 0;
}
