#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100
//实现两个栈

/*------------------------------------------------*/
//栈1
int stackIn[MaxSize];
int topIn = -1;
//压栈
void stackIn_push(int value){
    stackIn[++topIn] = value;
}
//弹栈
int stackIn_pop(){
   return stackIn[topIn--]; 
}
//判断是否为空
bool stackIn_isEmpty(){
    if(topIn == -1){
        return true;
    }
    return false;
}

/*------------------------------------------------*/
//栈2
int stackOut[MaxSize];
int topOut = -1;
void stackOut_push(int value){
    stackOut[++topOut] = value;
}
int stackOut_pop(){
    return stackOut[topOut--];
}
bool stackOut_isEmpty(){
    if(topOut == -1){
        return true;
    }
    return false;
}

/*------------------------------------------------*/
//栈1和栈2实现队列

//1. 入队：直接push进stackIn
void enqueue(int value){
    stackIn_push(value);
}

//2. 出队：核心逻辑
int dequeue(){
    //只有stackOut为空时,才把stackIn倒腾过去
    if(stackOut_isEmpty()){
        while(!stackIn_isEmpty()){
            stackOut_push(stackIn_pop()); 
        }
    }
    return stackOut_pop();
}

//3. 判断队列(即两个栈合起来)是否为空
bool isEmpty(){
    //必须是stackIn为空并且stackOut也为空，才是 [队列] 为空！！！
    if(stackIn_isEmpty() && stackOut_isEmpty()){
        return true;
    }
    return false;
}
/*------------------------------------------------*/
//主函数
int main(){
    int n;
    printf("请输入要入队的数字个数：");
    scanf("%d", &n);
    printf("请输入您的数字：");
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        //入队
        enqueue(num);
    }
    //出队
    printf("现在开始依次出队：\n");
    while(!isEmpty()){
        printf("%d\n", dequeue());
    }
    return 0;
}