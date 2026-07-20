#include<stdio.h>
#include<stdlib.h>
//节点结构体
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//一级指针的情况：把新的head当作返回值返回出去,调用者自己接收
//创建一个新节点
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//头插：返回新的head，而不是通过参数直接修改
Node* addFirst(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

//尾插：head本身没变,不需要返回新head,但为了写法统一也可以返回
Node* addLast(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;    //来到最后一个节点
    }
    tail->next = newNode;
    return head;         //head没变,原样返回
}

//按值删除：因为头节点也有可能被删除，所以要返回新的头节点
Node* deleteNode(Node* head, int data){
    if(head == NULL){
        return NULL;
    }
    //如果需要删除的是头节点
    if(head->data == data){
        Node* del = head;
        head = head->next;
        free(del);
        return head;  //这个head返回的是新的头节点
    }
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data == data){
            Node* del = curr->next;
            curr->next = del->next;
            free(del);
        }else{
            curr = curr->next;
        }
    }
    return head;      //这个head也是原样返回
}

//打印链表
void printList(Node* head){
    Node* curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

//主函数 —— 程序入口
int main(){
    Node* head = NULL;
    head = addFirst(head, 20);   //关键:调用后必须用head接收返回值
    head = addFirst(head, 10);
    head = addLast(head, 30);
    head = addLast(head, 40);
    printf("初始链表: ");
    printList(head);

    head = deleteNode(head, 10);
    printf("删除10后: ");
    printList(head);

    head = deleteNode(head, 30);
    printf("删除30后: ");
    printList(head);

    return 0;
}