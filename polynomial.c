#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//i是第i位階數,j=0正數,n是係數
int printx(int i,int j, char n){

    char sign[]="+-";

    if(n == 0)
        return 0;
    else
    {
        if(i == 0)
            printf("%c %d",sign[j],n);
        if(i == 1)
            printf("%c %dx ",sign[j],n);
        if(i > 1)
            printf("%c %dx^%d ",sign[j],n,i);   
    }
return 0;
}
//i為係數的長度如123,i=3
int findCoef(char *coef ,int i){
    char *endptr;
    long int num;
    double minus,num2;
    char n;

    num = strtol(coef, &endptr, 10);  //字串轉長整數
    num2 = (double)num;

    //minus = (fmod( num2 , pow(10 , i) ) - fmod( num2 , pow(10 , i-1) )) / pow(10 , i-1);    //分開長整數的每個位階
    n = (char)num2;
return n;
}

void main(){

    char str[10]={'\0'};
    char coef[] = "5 -12 3 0 0 -8 8 0 1"; //假設以space作為分隔
    char coef_1[10]={'\0'};

    long int num;
    double minus,num2;
    char n;
    
        int i=8;
        while(i>=0)
        {
            memset(str, '\0', sizeof(str));
            scanf("%s",str);
            if(str[0] == '-')
            {
                for(int k=1 ; k<strlen(str) ; k++)
                    coef_1[k-1] = str[k];

                n = findCoef(coef_1, strlen(coef_1));
                printx(i,1,n);
            }else{
                n = findCoef(str, strlen(str));
                printx(i,0,n);
            }

        i--;
        }
}
