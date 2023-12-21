//仿照老師上課內容，做修改
//寫成遞迴了，自己想的遞迴很酷
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.h"

char mesh[10][10] = {
    { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char mark[10][10] = {0};


//找四方向用餘數0(9宮格取2468)
axis_t findMove(stack_t *stackPtr, axis_t position , axis_t out){
    int count =1;
    int even;
    int sum3=0;
    for(int dx = -1 ; dx <= 1 ; dx++){
        for(int dy = -1 ; dy <=1 ; dy++){
            even = count % 2;
            if(even == 0)
            {
                axis_t space;
                space.x = position.x + dx;
                space.y = position.y + dy;

                //check 陣列溢位
                if(!(space.x <0 || space.y < 0 ))
                {
                    if(mesh[space.x][space.y] ==0 && mark[space.x][space.y] != 2){
                        if(!(mark[space.x][space.y] == 9))
                            {
                                if(EQU(stackPtr->elements[stackPtr->top] , out)) //若堆疊最上面 = out ，就不再push，全部return
                                    return space;
                                sum3++;
                                mark[space.x][space.y] = 2;
                                push(stackPtr , space);
                                if(!EQU(space , out))
                                    findMove(stackPtr , space , out);
                            }}
                }
            }
            count++;
        }
    }
    if(sum3 == 0)  //除來時路，其他方向皆無，設為9，將無解座標pop出去
    {   
        mark[position.x][position.y] = 9;
        pop(stackPtr);
    }
    return stackPtr->elements[stackPtr->top]; //回傳堆疊最上面位置
}

int main(){

    stack_t myStack;
    axis_t current_position;
    axis_t entry = {6,9};
    mark[entry.x][entry.y] = 2;
    axis_t out   = {1,0};
    axis_t no_exit = {-1,-1};

    myStack.top = -1;
    current_position = entry;
    mark[current_position.x][current_position.y] = 2;

    while(!EQU(current_position , out)){ //如果當前座標不等於出口
        current_position = findMove(&myStack , current_position , out);
        if(EQU(current_position , no_exit)){
            printf("no Exit axis !\n");
            break;
        }
    }

    push(&myStack , out);

    //印出迷宮
    printf("mark 2 is passable road\n");
    for(int h=0 ; h < 10 ; h++){
        for(int k=0 ; k < 10 ; k++){
            printf("  %d", mark[h][k]);
        }
        printf("\n");
    }

    //印出堆疊裡的座標
    printf("The coordinates of the path are :\n");
    for(int h=0 ; h < myStack.top ; h++){
        printf("( %d , %d)\n", myStack.elements[h].x, myStack.elements[h].y);
    }




}
