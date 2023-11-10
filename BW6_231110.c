#include <stdio.h> //standard input output
#include <stdlib.h>
#define ON_BOUND(h,k) (h>0 && h<8 && k>0 && k<8)

/*
int trackDirect(int h, int k ,int dy ,int dx , int another_color, int countEqual);
void findposition(int another_color, int findposition);
void PrintChess();
void FindOppositeColor(int n);
void FindEmpty();
void cleanChess();
void chooseChess();
void chooseCheck();
void changeChess(int chooseNumber);
void checkWon();
*/

//全部變數宣告
    int i=2 , j=4;  //指定想檢查的棋子
    int BW=1 , WB = 2; //規定反方向顏色
    int stepNum=1; 
    int chess[8][8] = {
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 2, 0, 0, 0},
                        {0, 0, 0, 2, 2, 0, 0, 0},
                        {0, 0, 1, 2, 1, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};
  
    //紀錄電腦人可選擇步數
    int robtRec[][6] = {{0,0,0,0,0,0}}; //落子座標i,j ; 翻轉棋數 count ; 方位 dy,dx ; 總共翻轉棋數 count

//清除下子紀錄
    void cleanChess()
    {
        while(stepNum > 0)
        {
            for(int n = 0 ; n < 6 ; n++ )
            {
            robtRec[stepNum][n] = 0;
            }
            stepNum--;
        }
    }

//印出棋盤內容
    void PrintChess()
    {
        printf("\nThe contents of chessboard is :\n");
        for(int c=0 ; c < 8 ; c++){
            for(int d = 0 ; d < 8 ; d++){
                printf("  %d", chess[c][d]);
            }
        printf("\n");
        }
    }

//改變棋子
    void changeChess(int chooseNumber)
    {
        int h,k,dy,dx,count;
        for(int n = 1 ; n < stepNum ; n++)
        {
            if(robtRec[n][5] == chooseNumber)
            {
                h = robtRec[n][0];
                k = robtRec[n][1];
                count = robtRec[n][2];
                dy = robtRec[n][3];
                dx = robtRec[n][4];
                chess[h][k] = BW;
                for(int m=0 ; m < count ; m++)
                {
                    h += dy;
                    k += dx;
                    chess[h][k] = BW;
                }}}
        PrintChess();
        cleanChess();
    }

//檢查誰贏了
    void checkWon()
    {
        if(robtRec[1][5] == 0)
        {
            int countB = 1 ,countW = 1;
        for(int h=0 ; h < 8 ; h++)
            for(int k=0 ; k < 8 ; k++)
            {
                if(robtRec[h][k] == 1)
                    countB++;
                else if(robtRec[h][k] == 2)
                    countW++;
            }
        if(countW > countB)
            printf("The robot won !");
        else
            printf("The human won !");
        exit(1);
        }
    }

//人 選擇下子
    void chooseCheck()
    {
        int chooseNumber = 0;
        int chooseChessPiece[stepNum]; //可用的號碼收集並印出號碼
        int m = 1 , p = 1;
        
        printf("You can choose the following number :\n");
        for(int n =1 ; n < stepNum ; n++) //可用的號碼收集並印出號碼
        {
            chooseChessPiece[n] = robtRec[n][5]; 
            printf("%d |", chooseChessPiece[n]);
        }
        printf("\n");
        do{
            scanf("%d", &chooseNumber);
            m = 1;
            while(m < stepNum)
            {
                if(chooseChessPiece[m] == chooseNumber) //如果所選擇號碼有在正確數字內 P=0
                    p=0;
            m++;
            }
            if(p != 0)
            {
                p=1;
                printf("Please choose the right number again:\n"); //p=1再選一次
            }
        }while(p);
        printf("Your choice is number :%d\n", chooseNumber);
        changeChess(chooseNumber);
    }

//持續找相反色，直到遇到執子色，若OK位置→紀錄於robtRec   
    int trackDirect(int h, int k ,int dy ,int dx ,int another_color, int countEqual)
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
                    //將步數記入 該方位的陣列裡
                    robtRec[stepNum][0] = i;
                    robtRec[stepNum][1] = j;
                    robtRec[stepNum][2] = count;
                    robtRec[stepNum][3] = dy;
                    robtRec[stepNum][4] = dx;
                    robtRec[stepNum][5] = countEqual;
                    //printf("(%d , %d).Chang %d piece. It's the %d chess piece. \n", robtRec[stepNum][0],robtRec[stepNum][1],robtRec[stepNum][2],robtRec[stepNum][5]);
                    stepNum++;
                    //checknull++;
                    return 1;
                }
    }

// 人或機器人 將可下的位置印出來
    void chooseChess()
    {
        int cEqual=1;
        int tempRec[stepNum][3];

        for(int n=1 ; n < stepNum ; n++)
        {
            cEqual = robtRec[n][2];
            while(robtRec[n][5] == robtRec[n+1][5] && n < stepNum)     //檢查i,j下點，若翻轉方向超過兩處，將count相加
            {      
                cEqual += robtRec[n+1][2];
                n++;
            }
            tempRec[n][0] = robtRec[n][0];
            tempRec[n][1] = robtRec[n][1];
            tempRec[n][2] = cEqual;
            printf("(%d , %d).Chang %d piece. It's the %d th chess piece. \n", tempRec[n][0],tempRec[n][1],tempRec[n][2],robtRec[n][5]);
        }
        if(BW == 1)
        {             //人
            checkWon();
            chooseCheck();
        }
        if(BW == 2)        //機器人
        {
            checkWon();
            int n = 1;
            int max = tempRec[n][2];
            int chooseNumber , nextTemp;

            while(n < stepNum){       //count誰大就選誰
                nextTemp = tempRec[n][2];
                if(max < nextTemp)
                    max = nextTemp;
            n++;
            }
            
            n=1;
            while(n < stepNum)
            {
                if(tempRec[n][2] == max)       //檢查是max，就呼叫換棋子
                {
                    chooseNumber = robtRec[n][5];
                    printf("Robot choice is number :%d\n", chooseNumber);
                    changeChess(chooseNumber);
                }
            n++;
            }
        }
    }

//檢查九宮格_九條路線處理 
    void findposition(int another_color, int countEqual)
    {
            int dx=0, dy=0;
            int ninex=1;
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
                        trackDirect(h, k, dy, dx, another_color, countEqual); //確定方向，深追直到遇見執色的子
                    }
                ninex++;
                }
            }
    }

//尋找是空白→則座標指定為h,k
    void FindEmpty()
    {
        stepNum = 1;
        int countEqual = 1;
        for(int h = 0 ; h < 8 ; h++)
        {
            for(int k = 0 ; k < 8 ; k++)
            {
                if(chess[h][k] == 0)
                {
                    i = h;
                    j = k;
                    findposition(WB, countEqual);
                }
                countEqual++;
            }
        }
        chooseChess();
    }

//執黑子BW==1 白子WB==2 反之顛倒
    void FindOppositeColor(int n)
    {
        if(n == 1)
        {
            BW = 1;
            WB = 2;

        }else if( n == 2){
            BW = 2;
            WB = 1;
        }
        FindEmpty();
    }

void main()
{
    //黑子先
    PrintChess();
    printf("The Black piece goes frist.\n");
    BW = 1;
    while(1)
    {
        FindOppositeColor(BW);
        BW = WB;
    }
    
}
