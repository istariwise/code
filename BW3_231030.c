#include <stdio.h> //standard input output
#define ON_BOUND(h,k) (h>0 && h<8 && k>0 && k<8)


int trackDirect(int h, int k ,int dy ,int dx , int another_color);
void findposition(int another_color);
void PrintChess();
void FindOppositeColor(int n);
void FindEmpty();

//全部變數宣告
    int i=2 , j=4;  //指定想檢查的棋子
    int BW=1 , WB = 2; //規定反方向顏色
    int checknull=0, ninex=1; 
    int chess[8][8] = {
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 2, 0, 0, 0},
                        {0, 0, 0, 2, 2, 0, 0, 0},
                        {0, 0, 1, 2, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    //紀錄 第一格 是翻轉棋子數，第二三格是方位 recordCountDirect[7][0] = {2 , 1,-1} 就是方向七可以走2格，方位是 (1,-1)
    int recordCount[10][3] = {          
                                    {0,  0,  0}, //沒有使用
                                    {0, -1, -1}, //方位1 (h,k) = (-1,-1)
                                    {0, -1,  0},
                                    {0, -1,  1},
                                    {0,  0, -1},
                                    {0,  0,  0}, //方位中心點 (i,j)
                                    {0,  0,  1},
                                    {0,  1, -1},
                                    {0,  1,  0},
                                    {0,  1,  1}}; 
    



//持續找相反色，直到遇到執子色，若OK位置→紀錄於recordCountDirect 
    
    int trackDirect(int h, int k ,int dy ,int dx , int another_color)
    {
            int y= h;
            int x= k;
            int count = 0;
            while(chess[y][x] == another_color)
            {
                y = y + dy;
                x = x + dx;
                count++;
            }
                if(!ON_BOUND(x,y))
                    return 0;
                else if(chess[y][x] == BW)      //如果最後一顆是執子色就OK
                {      
                    recordCount[ninex][0] = count;   //將步數記入 該方位的陣列裡
                    printf("(%d , %d).Chang %d piece. At Direct (%d , %d).\n", i, j, recordCount[ninex][0], dy, dx);
                    checknull++;
                    return 1;
                }
    
    }


    //檢查九宮格_九條路線處理 
    void findposition(int another_color)
    {
            int dx=0, dy=0;
            ninex=1;
            for(int h = i-1 ; h <= i+1 ; h++)
            {
                for(int k = j-1 ; k <= j+1 ; k++)
                {
                    if(!ON_BOUND(h,k)){
                        continue;
                    }else if(chess[h][k] == another_color) //檢查8格中行列h,k是否為白子
                    {
                        dy=h-i;
                        dx=k-j;
                        trackDirect(h, k, dy, dx, another_color); //確定方向，深追直到遇見執色的子
                    }
                ninex++;
                }
            }
    }


    void PrintChess()
    {
        //印出棋盤內容
        printf("The contents of chessboard is :\n");
        for(int c=0 ; c < 8 ; c++){
            for(int d = 0 ; d < 8 ; d++){
                printf("  %d", chess[c][d]);
            }
        printf("\n");
        }
    }

    //檢查九宮格(若白子→持續找黑子 else  若黑子→持續找白子)
    void FindOppositeColor(int n)
    {
        if(n == 1)
        {
            BW = 1;
            WB = 2;
            FindEmpty();
            
        }else if( n == 2){
            BW = 2;
            WB = 1;
            FindEmpty();
        }
    }
    


    //尋找是空白→則座標指定為h,k
    void FindEmpty()
    {
        for(int h = 0 ; h < 8 ; h++)
        {
            for(int k = 0 ; k < 8 ; k++)
            {
                if(chess[h][k] == 0){
                    i = h;
                    j = k;
                    findposition(WB);
                }else
                    continue;
            }
        }
    }



void main(){
    //黑子先
    PrintChess();
    printf("The Black piece goes frist.\n");
    BW = 1;
    printf("The position where you can play chess is\n");
    FindOppositeColor(BW);
    //檢查沒有棋子，則empty。 printf("checknull = %d .", checknull);
    if(checknull == 0)
        printf("empty.");

    //白子下
    printf("The white piece turn.\n");
    BW = 2;
    printf("The position where you can play chess is\n");
    FindOppositeColor(BW);
    //檢查沒有棋子，則empty。 printf("checknull = %d .", checknull);
    if(checknull == 0)
        printf("empty.");

}
