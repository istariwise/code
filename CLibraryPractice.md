#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void main(){

    distancexy();

}
