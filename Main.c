#include <stdio.h>
int main()
{
 char b[] = "kbtpo jsfebmf  kbdpc ebwjtpo";
 int k = 1;
 
 int index;
 int minus;
 int placeHolder;
 
 for(index = 0; b[index] !=0; index++){
     if(( b[index] < 65) || (b[index] > 90 && b[index] < 97) || (b[index] > 122))  
     //b[index] > 90) || (b[index] < 97 && b[index] > 122)) //fix this right away as some symbols change to letter
     {
     }
     else if (b[index] > 90)
     {
      b[index] = b[index] - 32;   
if((b[index]-k) < 65) 
{
   
   placeHolder =  b[index] - k; //figures out the value for the ascii number minus the k value
   minus = 65 - placeHolder; //this is the orgi
   b[index] = 91 - minus; 
}
 else{
   b[index] = b[index] - k;   
 }
    
}
else{
 if((b[index]-k) < 65) 
{
   
   placeHolder =  b[index] - k; //figures out the value for the ascii number minus the k value
   minus = 65 - placeHolder; //this is the o
   b[index] = 91 - minus; 
}
 else{
   b[index] = b[index] - k;     
}
// captial things need to go here

}
}
 
 printf("encrypted message is %s\n", b);
}

//to perform a rotation cipher the assigned ASCII number for each character using c = c-32//
//thhis will mean that each letter will have an assigned number from A=0 to Z=25//
//from this use a if loop shown if(number<25) then number++, and if(number=25) then number=0//
