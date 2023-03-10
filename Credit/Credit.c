#include <stdio.h>
#include <cs50.h>
#include <math.h>
int muchdig (long num);             //We will use it to find out how many digits the entered number has
int oddsum(long j);                 //We will use this function for adding every odd number and implement the steps.
int everyother_sum(long j);         //We will use this function for adding every other number.
int main (void)
{
int counter= 0;
long i = get_long("Number: ");
long i12=i;
    while(i12!=0){
        i12 = i12/10;               //We find how many digits the entered number has
        counter++;
    }
    if(counter == 13 || counter == 15 || counter == 16){
        int e1 = everyother_sum(i);
        int e2 = oddsum(i);         //If the entered number meets the necessary conditions
        int e3=e1+e2;               //the output is given to the user according to
            if(e3%10==0){
                if(counter==15){
                    printf("AMEX"); 
                    printf("\n");       //how many digits it has
                    return 0;
                }
                if(counter==13){
                    printf("VISA");    //how many digits it has
                    printf("\n");
                    return 0;
                }
                if(counter==16){
                    int i3=i/pow(10,15);
                    if(i3==4){
                        printf("VISA");     //which number it starts with
                        printf("\n");
                        return 0;
                    }
                    int i1=i/pow(10,14);
                    if(i1==51||i1==52 ||i1==53 ||i1==54|| i1==55){
                        printf("MASTERCARD");
                        printf("\n");       //which number it ends with
                        return 0;
                    }
                    else{
                        printf("INVALID");
                        printf("\n");
                        return 0;
                    }
                }
            }
            if(e3%10!=0){
                printf("INVALID");      //If entered number has got desired digits but not compliant with other condition
                printf("\n");           // we will print out invalid.
                return 0;
            }
    }
    else{
        printf("INVALID");              //If entered number hasn't got desired many digits we will print out invalid.
        printf("\n");
        return 0;
        }
    printf("\n");
}
int oddsum(long j){
int count2=(ceil(muchdig(j)/2));
int a2, b2, c2, d2, sum2=0;
        j/=10;
        while(count2!=0){
            a2=((j%10)*2);
            b2=a2%10;
            c2=a2/10;
            d2=c2+b2;
            j/=100;
            sum2=sum2+d2;
            count2--;
        }
        return sum2;
}
int everyother_sum(long j){
int count=(ceil(muchdig(j)/2));
int a, sum3=0;
        while(count!=0){
            a=j%10;
            j/=100;
            sum3=a+sum3;
            count--;
        }
    return sum3;
}
int muchdig (long num){
    int dig = 0;
    while(num!=0){
        num /=10;           //we will divide the number by 10 until it reaches zero
        dig++;              //and increment the digit counter by 1 with each division.
    }
    return dig;
}