//仿照老師上課內容
#include "magic.h"

void stackInit(stack1_t *stackPtr , int size){
    stackPtr->elements = (axis_t *) malloc(size*sizeof(axis_t));
}

void push(stack_t *stackPtr, axis_t element){
    stackPtr->top++;
    stackPtr->elements[stackPtr->top] = element;
    //memcpy(&stack.elements[stack.stack_pointer], &element, sizeof(element));
}

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

}
