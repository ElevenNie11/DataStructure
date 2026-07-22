#include <stdio.h>
#include <stdbool.h>
#define MaxSize 5

int queue[MaxSize];
int front = 0;     //队头指针(队头下标)：下一次dequeue会从这里取
int rear = 0;      //队尾指针(队尾下标)：下一次enqueue会从这里删
int count = 0;     //当前队列有几个元素：因为光靠 front == rear 是判断不出来队列是满还是空的

bool isEmpty(){
    if(count == 0){
        return true;
    }
    return false;
}

bool isFull(){
    if(count == MaxSize){
        return true;
    }
    return false;
}

//队尾插入
void enqueue(int value){
    if(isFull()){
        printf("队列已满\n");
        return ;
    }
    queue[rear] = value;
    rear = (rear + 1) % MaxSize;   //[关键]: 取模运算实现“绕回循环”！！！
    count++;
}

//队头删除
int dequeue(){
    if(isEmpty()){
        printf("队列已空\n");
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % MaxSize;  //[关键]: 取模运算实现“绕回循环”！！！
    count--;
    return value;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("出队：%d\n", dequeue());  //10
    printf("出队：%d\n", dequeue());  //20
    enqueue(40);
    enqueue(50);
    enqueue(60);   //60覆盖了下标0的10
    while(!isEmpty()){
        printf("出队：%d ", dequeue()); // 30 40 50 60
    }
    printf(isEmpty() ? "\n队列已空" : "\n队列未空");
    return 0;
}