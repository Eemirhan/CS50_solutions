#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
    string text = get_string("Text: ");
    int len=strlen(text);
    int sentence=0,space=0,letters=0;
    float index=0;
    for(int i=0;i<len;i++){
        if((64<text[i]&&text[i]<91)||(96<text[i]&&text[i]<123)){
            letters++;
        }
        if(text[i]==32){
            space++;
        }
        if(text[i]==33||text[i]==46||text[i]==63){
            sentence++;
        }
    }
    int words=space+1;
    float L=(letters*100)/words;
    float S=(sentence*100)/words;
    index=(round(0.0588 * L - 0.296 * S - 15.8));
    if(index<1){
        printf("Before Grade 1\n");
        return 0;
    }
    if(16<=index){
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n",(int) index);
}