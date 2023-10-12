#include <stdio.h> //standard input output
#include <math.h>
#include <stdlib.h> //亂數函示庫
#include <time.h> //時間函示庫

void main(){
    int bw = 0;
    int chess[8][8], i=3 , j=3 , ninex=1, x , y; //ninex是九宮格號碼,.x,y是可能下子的位置

    for(int c=0 ; c < 8 ; c++)
        for(int d = 0 ; d < 8 ; d++)
            chess[c][d] = 0;

    //先擺好中間四個子
    chess[3][3]= 1; 
    chess[3][4]= 2;
    chess[4][3]= 2;
    chess[4][4]= 1;

    //給定一個棋子位置(四選一)
    srand( time(NULL) ); //設定亂數種子

    //產生亂數
    int tr = rand();
    int r = tr % 4;
    printf("random is %d\n", r);

    switch (r) {
        case 0:
            i = 3;
            j = 3;
            break;
        case 1:
            i = 3;
            j = 4;
            break;
        case 2:
            i = 4;
            j = 3;
            break;
        case 3:
            i = 4;
            j = 4;
            break;
        default:
            break;
    }
    printf("The current chess piece position is (%d , %d)\n", i, j);
    

    //檢查白子黑子
    bw = chess[i][j];
    if(bw == 1)
        printf("The current chess piece is black.\n");
    else
        printf("The current chess piece is white.\n");

    
    
    printf("The position where you can play chess is\n");
    
    //檢查九宮格(指定為黑棋→找白棋)
    if(bw == 1)
    {
        ninex=1;
        for(int h = i-1 ; h < i+2 ; h++)
        {
            for(int k = i-1 ; k < i+2 ; k++)
            {
                if(chess[h][k] == 2) //檢查8格中行列h,k是否為白子
                {
                    switch (ninex) {
                        case 1:
                            x = h-1;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 2:
                            x = h-1;
                            y = k;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 3:
                            x = h-1;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 4:
                            x = h;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 5:     //是自己，但永遠不會進來
                            break;
                        case 6:
                            x = h;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 7:
                            x = h+1;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 8:
                            x = h+1;
                            y = k;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 9:
                            x = h+1;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        default:
                            break;
                    }
                }
            ninex++;
            }
        }
    }else if(bw == 2){
        ninex=1;
        for(int h = i-1 ; h < i+2 ; h++)
        {
            for(int k = j-1 ; k < j+2 ; k++)
            {
                if(chess[h][k] == 1) //檢查8格中行列h,k是否為黑子
                {
                    switch (ninex) {
                        case 1:
                            x = h-1;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 2:
                            x = h-1;
                            y = k;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 3:
                            x = h-1;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 4:
                            x = h;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 5:     //是自己，但永遠不會進來
                            break;
                        case 6:
                            x = h;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 7:
                            x = h+1;
                            y = k-1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 8:
                            x = h+1;
                            y = k;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        case 9:
                            x = h+1;
                            y = k+1;
                            printf("coordinate is (%d , %d)\n", x , y);
                            break;
                        default:
                            break;
                    }
                }
            ninex++;
            }
        }


        
    }


    


}
