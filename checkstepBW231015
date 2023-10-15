#include <stdio.h> //standard input output
#include <math.h>
#include <stdlib.h> //亂數函示庫
#include <time.h> //時間函示庫

//全部變數宣告
    int i=1 , j=5;  //指定想檢查的棋子
    int sixtyfour=0 , ninex=1 , checknull=0; //ninex是九宮格號碼
    int chess[8][8] = {
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {2, 1, 2, 1, 1, 2, 1, 0},
                        {2, 2, 1, 1, 1, 2, 1, 0},
                        {2, 1, 2, 2, 1, 2, 1, 0},
                        {2, 1, 2, 2, 2, 2, 1, 0},
                        {2, 2, 2, 2, 2, 2, 1, 0},
                        {2, 2, 2, 1, 1, 2, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0}
                      };


//持續找黑子或白子，直到遇到空白
    //1號位_九宮格 (h--,k--)
    void upperleft(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h--;
                k--;
            }
                if(h < 0 || k < 0 )
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //2號位_九宮格 (h--,k)
    void uppermiddle(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h--;   
            }
                if(h < 0)
                    printf("");
                else if(chess[h][k] == 0)
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //3號位_九宮格 (h--,k++)
    void upperright(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h--;
                k++;   
            }
                if(h < 0 || k > 8)
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //4號位_九宮格 (h , k--)
    void middleleft(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                k--;
            }
                if(k < 0)
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //6號位_九宮格 (h , k++)
    void middleright(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                k++;                
            }
                if(k > 8)
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //7號位_九宮格 (h++,k--)
    void lowerleft(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h++;
                k--;
            }
                if(h > 8 || k < 0)
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //8號位_九宮格 (h++,k)
    void lowermiddle(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h++;
            }
                if(h > 8)
                    printf("");
                else if(chess[h][k] == 0)      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }

    //9號位_九宮格 (h++,k++)
    void lowerright(int bw, int h, int k)
    {
            while(chess[h][k] == bw)
            {
                h++;
                k++;
            }
                if(h > 8 || k > 8)
                    printf("");
                else if(chess[h][k] == 0 )      
                {      
                    printf("coordinate is (%d , %d)\n", h, k);
                    checknull++;
                }
    
    }



    //檢查九宮格_九條路線處理 
    void findposition(int bw)
    {
        printf("The position where you can play chess is\n");
        ninex=1;
            for(int h = i-1 ; h < i+2 ; h++)
            {
                for(int k = j-1 ; k < j+2 ; k++)
                {
                                                                  // printf("h, k = (%d , %d)\n", h, k);
                    if(chess[h][k] == bw) //檢查8格中行列h,k是否為白子
                    {
                        switch (ninex) 
                        {
                            case 1:
                                upperleft(bw, h, k);
                                break;
                            case 2:
                                uppermiddle(bw, h, k);
                                break;
                            case 3:
                                upperright(bw, h, k);
                                break;
                            case 4:
                                middleleft(bw, h, k);
                                break;
                            case 5:     //是自己，但永遠不會進來
                                break;
                            case 6:
                                middleright(bw, h, k);
                                break;
                            case 7:
                                lowerleft(bw, h, k);
                                break;
                            case 8:
                                lowermiddle(bw, h, k);
                                break;
                            case 9:
                                lowerright(bw, h, k);
                                break;
                            default:
                                break;
                        }
                    }
                ninex++;
                }
            }
    }






void main(){

    //印出棋盤內容
    printf("The contents of chessboard is :\n");
    for(int c=0 ; c < 8 ; c++){
        for(int d = 0 ; d < 8 ; d++){
            printf("  %d", chess[c][d]);
            sixtyfour++;
        }
    printf("\n");
    }


    srand( time(NULL) ); //設定亂數種子
    /*產生亂數
    int tr = rand();
    int ts = rand();
    int r = tr % 8;
    int s = ts % 8;
    printf("random is %d\n", r);
    i = r;
    j = s;
    */
    printf("The current chess piece position is (%d , %d)\n", i, j);
    

    //檢查白子黑子
    
    if(chess[i][j] == 1)
        printf("The current chess piece is black.\n");
    else
        printf("The current chess piece is white.\n");


    //檢查九宮格(若白子→持續找黑子 else  若黑子→持續找白子)
    if(chess[i][j] == 1)
    {
        int n = 2;
        findposition(n);
        
    }else if(chess[i][j] == 2){
        int n = 1;
        findposition(n);
    }

    //檢查沒有棋子，則empty。 printf("checknull = %d .", checknull);
    if(checknull == 0)
        printf("empty.");

}
