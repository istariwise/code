//仿照老師上課內容 ， 做修改
#ifndef _MAGIC_H_
#define _MAGIC_H_
#define M_SIZE 10
#define EQU(p,q)  (p.x==q.x && p.y==q.y)


//座標結構  _t表結構
typedef struct axis {
    int x;
    int y;
} axis_t;

//堆疊結構
typedef struct stack {
    axis_t elements[M_SIZE*M_SIZE];  //10X10的矩陣，每一格都是座標結構
    int top;                         //top 堆疊陣列中指著的最後一個欄位的號碼or指標
}stack_t;

//將其他.c檔的副程式名稱放進來
void push(stack_t *stack, axis_t axis);
axis_t pop(stack_t *stack);
int isEmpty(stack_t *stack);

#endif

