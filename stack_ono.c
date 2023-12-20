//仿照老師上課內容, 做修改
//堆疊資料結構的方法
#include "magic.h"

//放進堆疊一個座標
void push(stack_t *stackPtr, axis_t element){
    stackPtr->top++;
    stackPtr->elements[stackPtr->top] = element;
    //memcpy(&stack.elements[stack.stack_pointer], &element, sizeof(element));
}

//取出堆疊一個座標
axis_t pop(stack_t *stackPtr){
    axis_t temp={-1,-1};
    if(isEmpty(stackPtr)) return temp;
    temp = stackPtr->elements[stackPtr->top];
    stackPtr->top--;
    return temp;
    //return stackPtr->elements[stackPtr->top--];
}

int isEmpty(stack_t *stackPtr){
    if(stackPtr->top==-1) return 1;
    return 0;
}

int isFull(stack_t *stackPtr){
     if(stackPtr->top>=100) return 1;
    return 0;
}

