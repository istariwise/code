#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main(){

    char base;
    int quot,rem,tran; //x,商,餘數,轉換成10進位
    char str[10]={'\0'};
    char len = 30;
    char trf[len];
    char max;
    char plus;
    char k; //trf陣列長度
    char least;
    char j = 0;     //次方數
    int value;
    int cal;
   

    scanf("%s",str);

    memset(trf, '\0', sizeof(trf));

//取最大值
    max = str[0];
    for(int i=0 ; i<strlen(str) ; i++)
    {
        if(str[i] >= max)
        {
            max = str[i];
        }
    }
    if(isupper(max))
        base = max+1 - 55;  //A~Z:65~90(-55)A~Z:10~35
    if(islower(max))
        base = max+1 - 61;  //a~z:97~122(-55)a~z:36~61
    if(isdigit(max))
        base = max+1 - 48;  //是數字都是字符,要-48

//困擾是val中A以上數換成10進位整除base or val轉換成base數值後被整除?(只要個位數整除即可)
    plus = len - strlen(str);
    for(int i=strlen(str)-1 ; i>=0 ; i--)   //轉換成10進位
    {
        if(isdigit(str[i]))     //是數字都是字符,要-48
        {
            tran = str[i]-48;
            trf[i+plus] += tran;
        }
        else
        {
            if(isupper(str[i]))
                tran = str[i] - 55;  //A~Z:65~90(-55)A~Z:10~35
            if(islower(str[i]))
                tran = str[i] - 61;  //a~z:97~122(-55)a~z:36~61

            quot = tran / 10;    //商=進位
            rem = tran % 10;     //餘=個位數

            trf[i+plus] += rem;     //餘=個位數
            trf[i+plus-1] = quot;   //商=進位
        }
    }

    k = len-1; //trf陣列長度
    least = k-strlen(str);
    j = 0;     //次方數
      
    while(trf[k] != '\0' || k > least)   //用pow()轉換成10進位,for執行次數至少大於strlen(str)長度
    {
        value += trf[k] * pow(10,j);
        j++;
        k--;
    }

//符合數字被 n-1 = base-1 整除(假設題意是轉換成10進位)

    for(int i=0 ; i<=62 ; i++)
    {
        base += i;
        cal = (value % ((base)-1));
        if( cal ==0 )
        {
            printf("%d\n",base);
            break;
        }
        else
        {
            if(i = 62)
                printf("Can't find base.\n");
            else
                continue;
        }
    }

}
