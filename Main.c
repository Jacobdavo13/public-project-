#include <stdio.h>
int main()
{
    char c;
    printf("Enter Letter: ");

    
    scanf("%c", &c);  //scans letter//
    
 
    printf("ASCII value of %c = %d", c, (int)c);
    return 0;
}  

//to perform a rotation cipher the assigned ASCII number for each character using c = c-65//
//thhis will mean that each letter will have an assigned number from A=0 to Z=25//
//from this use a if loop shown if(number<25) then number++, and if(number=25) then number=0//
