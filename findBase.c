#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main(){

    char base;
    int x,quot,rem,tran; //x,商,餘數,轉換成10進位
    char str[] = "a123";
    char trf[100]={'\0'};
    x = str[3];
    //printf("x is:%d",x);
    //sacnf("%d",val);

//取最大值
    char max = str[0];
    for(int i=0 ; i<strlen(str) ; i++)
    {
        if(str[i] >= max)
            max = str[i];
    }
    base = max+1;

//困擾是val中A以上數換成10進位整除base or val轉換成base數值後被整除?(只要個位數整除即可)

    char plus = 100-strlen(str);
    for(int i=strlen(str)-1 ; i>=0 ; i--)   //0賦值給trf
        trf[i+plus] = 0;  
    
    for(int i=strlen(str)-1 ; i>=0 ; i--)   //轉換成10進位
    {
        if(isdigit(str[i]))     //是數字
            trf[i+plus] += str[i];
        else
        {
            if(isupper(str[i]))
                tran = str[i] - 55;  //A~Z:65~90(-55)A~Z:10~35
            if(islower(str[i]))
                tran = str[i] - 61;  //a~z:97~122(-55)a~z:36~61

            quot = tran / 10;    //商=進位
            rem = tran % 10;     //餘=個位數

            trf[i+plus] += rem;     //餘=個位數
            trf[i+plus+1] = quot;   //商=進位
        }
    }
//字串轉長整數
    char *endptr;
    long int num;
    char num2;

    num = strtol(trf, &endptr, 10);  //str字串轉長整數
    num2 = (char)num;

//符合數字被 n-1 = base-1 整除(假設題意是轉換成10進位)

    for(int i=0 ; i<=62 ; i++)
    {
        base += i;
        if( (num2 % ((base)-1)) ==0 )
        {
            printf("%d",base);
            break;
        }
        else
            continue;
    }
}
