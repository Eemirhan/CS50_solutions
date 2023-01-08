#include <stdio.h>
#include <cs50.h>

int main (void){
    {
    int j;
    do
    {
        j = get_int("piramdin taban genişliğini giriniz: ");
    }
    while(j<1 || j>8);
     {
        for(int tmp_row = 1;tmp_row<=j;tmp_row++)
        {
            for(int i=j-tmp_row;(i!=0);i--){
                printf(" ");
            }
            for(int i=tmp_row;i>0;i--){
                printf("#");
            }
            printf("  ");
            for(int i=tmp_row;i>0;i--){
                printf("#");
            }
            printf("\n");
        }

     }
    }
}