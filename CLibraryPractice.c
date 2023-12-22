//老師好，之前在趕論文final，抱歉現在開始追。
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*math.h*/

// double sqrt(double x) / double pow(double x, double y)
void distancexy(){

    int x1, y1, x2, y2;
    printf("please enter first coordinater (x1 , y1).\n");
    scanf("%d , %d",&x1 ,&y1);
    printf("please enter sencend (x2 , y2).\n");
    scanf("%d , %d",&x2 ,&y2);

    int dis;
    dis = (int)sqrt(pow((x1 - x2),2)+pow((y1 - y2),2));
    printf("The distance is %d\n", dis);

}

// double fmod(double x, double y)
void evenOrOdd(){
    int x;
    int remainder;
    printf("please enter a number.\n");
    scanf("%d",&x);

    remainder = (int)fmod((double)x , 2);

    if(remainder == 0)
        printf("The number %d is even\n", (int)x);
    else
        printf("The number %d is odd.\n", (int)x);
}

//double ceil(double x) 無條件進位到整數第N位(進位到個位，N=1；十位,N=2；百位,N=3)
void roundUP(){
    int x;
    int n;
    double y;
    printf("please enter a number.\n");
    scanf("%d",&x);
    printf("Is rounding up to N position?\n");
    scanf("%d",&n);

    y = x/(pow(10 , (n - 1)));
    y = ceil(y);
    y = y * (pow(10 , (n - 1)));
    printf("Round up to %d position.\n", n);
    printf("%d is rounded up to %d", x, (int)y);
}

//double floor(double x) 無條件捨去到整數第N位(捨去到個位，N=1；十位,N=2；百位,N=3)
void roundDown(){
    int x,n;
    double y;
    printf("please enter a number.\n");
    scanf("%d",&x);
    printf("Is Rounding Down to N position?\n");
    scanf("%d",&n);

    y = x/(pow(10 , (n - 1)));
    y = floor(y);
    y = y * (pow(10 , (n - 1)));
    printf("Round down to %d position.\n", n);
    printf("%d is rounded down to %d", x, (int)y);
}

//double fabs(double x) 柯西不等式
void Cauchy(){
    int a,b,c,d;
    double y1,y2;
    printf("please enter four number to calculate Cauchy's inequality.\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    y1 = sqrt(pow(a,2) + pow(b,2)) * sqrt(pow(c,2) + pow(d,2));
    y2 = fabs(a * c + b * d);
    if(y1 >= y2)
        printf("As %f >= %f ,The result of Cauchy's inequality hold \n", y1,y2);
    else
        printf("As %f < %f ,The result of Cauchy's inequality don't hold \n", y1,y2);
}

/*------------assert.h--------------*/
void triangle(){
    int a,b,c;
    int t1,t2,t3;
   
    printf("Please enter three side lengths of the triangle.\n");
    scanf("%d,%d,%d", &a,&b,&c);
    t1=a+b;
    t2=a+c;
    t3=b+c;
    assert(t1 > c); //檢查任兩邊大於第三邊
    assert(t2 > b);
    assert(t3 > a);
    printf("Three side lengths of %d, %d, %d are correst.\n", a,b,c);
    
}



void main(){

    //distancexy();
    //evenOrOdd();
    //roundDown();
    //roundUP();
    //Cauchy();
    triangle();
}
