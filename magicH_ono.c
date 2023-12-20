//仿照老師上課內容，做修改
#include <stdio.h>
#include <string.h>
#include "magic.h"

char mesh[10][10] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
char mark[10][10] = {0};
char mazzpath[][2] = {0};

//找四方向用餘數0(9宮格取2468)
axis_t findMove(stack_t *stackPtr, axis_t position , int *n){
    int count =1;
    int even;
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
                    if(mesh[space.x][space.y] ==0 && mark[space.x][space.y] != 2)
                    {
                        mark[space.x][space.y] = 2;
                        push(stackPtr , space);
                        mazzpath[*n][0] = space.x;
                        mazzpath[*n][1] = space.y;
                        *n += 1;    //不能寫*n++
                    }
                }
            }
            count++;
        }
    }
    return pop(stackPtr); //回傳堆疊最上面位置
}

int main(){
    int *n ;  //不能 int *n=0
    *n = 0;
    stack_t myStack;
    axis_t current_position;
    axis_t entry = {6,9};
    axis_t out   = {1,0};
    axis_t no_exit = {-1,-1};

    myStack.top = -1;
    current_position = entry;
    mark[current_position.x][current_position.y] = 2;

    while(!EQU(current_position , out)){ //如果當前座標不等於出口
        current_position = findMove(&myStack , current_position , n);
        if(EQU(current_position , no_exit)){
            printf("no Exit axis !\n");
            break;
        }
    }

    //印出迷宮
    printf("mark 2 is passable road\n");
    for(int h=0 ; h < 10 ; h++){
        for(int k=0 ; k < 10 ; k++){
            printf("  %d", mark[h][k]);
        }
        printf("\n");
    }

    //印出座標
    printf("The coordinates of the path are :\n");
    for(int h=0 ; h <= *n ; h++){
        printf("( %d , %d)\n", mazzpath[h][0], mazzpath[h][1]);
    }




}
