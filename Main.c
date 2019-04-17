#include <stdio.h>
int main()
{
 char b[] = "JACOB";
 int k = 1;
 
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
}

//to perform a rotation cipher the assigned ASCII number for each character using c = c-32//
//thhis will mean that each letter will have an assigned number from A=0 to Z=25 using the modulus//
