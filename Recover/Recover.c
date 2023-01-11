#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    int counter=0;
    char filename[8]={0};
    if(argc!=2){
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(file==NULL){
        printf("Unable to open file\n");
        return 2;
    }
    BYTE buffer[512];
    FILE *out;
    while(fread(buffer, sizeof(BYTE)*512, 1, file)){
        if(buffer[0]==0xFF&&buffer[1]==0xD8&&buffer[2]==0xFF&&(buffer[3]&0xF0)==0xE0){
            if(out != NULL){
                fclose(out);
            }
            sprintf(filename,"%03d.jpg",counter++);
            out=fopen(filename,"w");
        }
        if(out != NULL){
            fwrite(buffer, sizeof(BYTE)*512 ,1 ,out);
        }
    }
    fclose(out);
    fclose(file);
    return 0;
}