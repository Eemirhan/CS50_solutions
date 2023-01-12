#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            float a=image[i][j].rgbtRed;
            float b=image[i][j].rgbtGreen;
            float c=image[i][j].rgbtBlue;
            int d= round((a+b+c)/3);
            image[i][j].rgbtRed=d;
            image[i][j].rgbtGreen=d;
            image[i][j].rgbtBlue=d;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int symmetry=width/2;
    for(int i=0;i<height;i++){
        for(int j=0;j<symmetry;j++){
            temp[i][j]=image[i][j];
            image[i][j]=image[i][width-j];
            image[i][width-j]=temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            tmp[i][j]=image[i][j];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    int curx= j+y;
                    int cury= i+x;
                    if(curx >=0 && curx < width && cury>=0 && cury<height){
                        image[i][j].rgbtRed=(tmp[i-1][j-1].rgbtRed+tmp[i-1][j].rgbtRed+tmp[i-1][j+1].rgbtRed+tmp[i][j-1].rgbtRed+tmp[i][j].rgbtRed+tmp[i][j+1].rgbtRed+tmp[i+1][j-1].rgbtRed+tmp[i+1][j].rgbtRed+tmp[i+1][j+1].rgbtRed)/9;
                        image[i][j].rgbtGreen=(tmp[i-1][j-1].rgbtGreen+tmp[i-1][j].rgbtGreen+tmp[i-1][j+1].rgbtGreen+tmp[i][j-1].rgbtGreen+tmp[i][j].rgbtGreen+tmp[i][j+1].rgbtGreen+tmp[i+1][j-1].rgbtGreen+tmp[i+1][j].rgbtGreen+tmp[i+1][j+1].rgbtGreen)/9;
                        image[i][j].rgbtBlue=(tmp[i-1][j-1].rgbtBlue+tmp[i-1][j].rgbtBlue+tmp[i-1][j+1].rgbtBlue+tmp[i][j-1].rgbtBlue+tmp[i][j].rgbtBlue+tmp[i][j+1].rgbtBlue+tmp[i+1][j-1].rgbtBlue+tmp[i+1][j].rgbtBlue+tmp[i+1][j+1].rgbtBlue)/9;
                    }
                }
            }
        }
    }

     return;
}



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            tmp[i][j]=image[i][j];
        }
    }
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                 int curx= j+y;
                 int cury= i+x;
                 if(curx >=0 && curx < width && cury>=0 && cury<height){
                    int gXred=(((tmp[i-1][j-1].rgbtRed)*-1)+tmp[i+1][j+1].rgbtRed+((tmp[i][j-1].rgbtRed)*-2)+((tmp[i][j+1].rgbtRed)*2)+((tmp[i+1][j-1].rgbtRed)*-1)+((tmp[i+1][j+1].rgbtRed)*1));
                    int gXblue=(((tmp[i-1][j-1].rgbtBlue)*-1)+tmp[i+1][j+1].rgbtBlue+((tmp[i][j-1].rgbtBlue)*-2)+((tmp[i][j+1].rgbtBlue)*2)+((tmp[i+1][j-1].rgbtBlue)*-1)+((tmp[i+1][j+1].rgbtBlue)*1));
                    int gXgreen=(((tmp[i-1][j-1].rgbtGreen)*-1)+tmp[i+1][j+1].rgbtGreen+((tmp[i][j-1].rgbtGreen)*-2)+((tmp[i][j+1].rgbtGreen)*2)+((tmp[i+1][j-1].rgbtGreen)*-1)+((tmp[i+1][j+1].rgbtGreen)*1));

                    int gYred=(((tmp[i-1][j-1].rgbtRed)*-1)+tmp[i+1][j+1].rgbtRed+((tmp[i-1][j].rgbtRed)*-2)+((tmp[i+1][j].rgbtRed)*2)+((tmp[i+1][j-1].rgbtRed)*-1)+((tmp[i+1][j+1].rgbtRed)*1));
                    int gYblue=(((tmp[i-1][j-1].rgbtBlue)*-1)+tmp[i+1][j+1].rgbtBlue+((tmp[i-1][j].rgbtBlue)*-2)+((tmp[i+1][j].rgbtBlue)*2)+((tmp[i+1][j-1].rgbtBlue)*-1)+((tmp[i+1][j+1].rgbtBlue)*1));
                    int gYgreen=(((tmp[i-1][j-1].rgbtGreen)*-1)+tmp[i+1][j+1].rgbtGreen+((tmp[i-1][j].rgbtGreen)*-2)+((tmp[i+1][j].rgbtGreen)*2)+((tmp[i+1][j-1].rgbtGreen)*-1)+((tmp[i+1][j+1].rgbtGreen)*1));

                    image[i][j].rgbtRed=round(sqrt((gXred*gXred)+(gYred*gYred)));
                    image[i][j].rgbtBlue=round(sqrt((gXblue*gXblue)+(gYblue*gYblue)));
                    image[i][j].rgbtGreen=round(sqrt((gXgreen*gXgreen)+(gYgreen*gYgreen)));
                    }
                }
            }
        }
    }
    return;
}
