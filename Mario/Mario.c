#include <stdio.h>
#include <cs50.h>

int main (void){
    {
    do
    {
        int j = get_int("Height: ");        //We keep geting the desired height value from user
    }
    while(j<1 || j>8);                      //till the desired value is within the specified range
     {
        for(int tmp_row = 1;tmp_row<=j;tmp_row++)
        {
            for(int i=j-tmp_row;(i!=0);i--){        //to print spaces for pyramid shape
                printf(" ");
            }
            for(int i=tmp_row;i>0;i--){             //to print hashes for left side of the pyramid
                printf("#");
            }
            printf("  ");                           //to print 2 spaces for desired shape
            for(int i=tmp_row;i>0;i--){
                printf("#");                        //to print hashes for right side of the pyramid
            }
            printf("\n");
        }

     }
    }
}