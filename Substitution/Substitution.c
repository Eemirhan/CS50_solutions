#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool not_repeating(string d);   //We will use this function to check our key for repeating characters
bool alphabetic(string d);      //We will use this function to check our key for non-alphabetic characters
int main(int argc, string argv[])
{
    int len= strlen(argv[1]);
    if(argc == 2 && len == 26 && alphabetic(argv[1])==true && not_repeating(argv[1])==true){        //We check the necessary conditions
        string P=get_string("Plain Text: ");
        int l2= strlen(P);
        for(int l = 0;l<l2;l++){
            if((P[l]<65 && 31<P[l] )||( 90<P[l] && P[l]<97) || (122<P[l] && P[l]<127)){     //If l. character is not an alphabetic character
                l++;                                                                        //we are going to skip it.
            }
            if(isupper(P[l])){          //If l. char is an upper case letter we will subtract 65 from it's ascii value
                int a=P[l]-65;                //This will give us how much to shift in key
                P[l]=(toupper(argv[1][a]));     //we will shift through the key that times and update plain text string.
            }
            if(islower(P[l])){
                int b=P[l]-97;                
                P[l]=(tolower(argv[1][b]));
                }
        }printf("Cipher Text: %s\n",P);
    }
    if(argc != 2){
        printf("Usage: ./substitution key\n");      //If there is more or less argument from our threshold  
        return 0;                                   // we will return 1 and finish the sequence
    }
    if(len != 26){
        printf("Key must contain 26 characters.\n");    //If the key is not 26 characters long we will return 1 and finish the sequence
        return 0;
    }
    if(alphabetic(argv[1])==false){
        printf("Key must only contain alphabetic characters.\n");          //We are controlling the key for non-alphabetic characters.
        return 0;
    }
    if(not_repeating(argv[1])==false){                                     //We are controlling the key for repeating characters.
        printf("Key must not contain repeated characters.\n");
        return 0;
    }
}
bool not_repeating(string d){                   
    for(int i=0;i<26;i++){                          //we are comparing every char with other chars 
        for(int j=i+1;j<26;j++){                    //to find any repeating characters.
            if(d[i] == d[j]){
               return false;
            }
        }
    }
    return true;
}
bool alphabetic(string j){
    for(int i = 0; j[i]; i++){                  //we are lower casing the key for more easyness.
        j[i] = tolower(j[i]);
    }
            for(int k=0;k<26;k++){              //we are looking every chars ascii value to validate it's an indeed alphabetic character
                if((j[k]<96 && j[k]!=32) || (123<j[k] && j[k]!=32)){
                   return false;
                }
            }
            return true;
}