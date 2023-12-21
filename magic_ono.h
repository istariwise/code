//仿照老師上課內容, 做修改
#ifndef _MAGIC_H_
#define _MAGIC_H_

#define M_SIZE 10

#define EQU(p,q)  (p.x==q.x && p.y==q.y)

//#define x NULL

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

//static inline 放在很短的副程式前，用意讓compile決定太短可變成巨集非副程式方式，避免使用系統堆疊
//跟define一樣是巨集
//static 用途是將變數變成全域變數，且只有該區塊可以存取
static inline int equ(axis_t *a , axis_t *b){
    return (a->x == b->x && a->y == b->y);
}


#endif
