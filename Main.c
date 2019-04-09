#include <stdio.h>
int main()
{
 char b[] = "dfg hjk";
 int k = 1;
 
 int index;
 
 for(index = 0; b[index] !=0; index++){
     if(b[index] == 32)
     {
     }
     else{
         

    b[index] = b[index] - k;  
}
 }
 
 printf("encrypted message is %s\n", b);
}

//to perform a rotation cipher the assigned ASCII number for each character using c = c-65//
//thhis will mean that each letter will have an assigned number from A=0 to Z=25//
//from this use a if loop shown if(number<25) then number++, and if(number=25) then number=0//
