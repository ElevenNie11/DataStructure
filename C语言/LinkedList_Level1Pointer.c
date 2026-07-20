#include<stdio.h>
//实现一个节点：C语言用结构体来实现
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//创建新节点
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//头插
void addFirst(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//尾插
void addLast(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* tail = *head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
}

//按值删除节点
void deleteNode(Node** head, int data){
    if(*head == NULL){
        return;
    }
    //如果头节点就是要删除的节点
    if((*head)->data == data){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    //普通情况（先连接后继节点，再断开前驱节点）
    Node* curr = *head;
    //准备从头开始遍历
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data == data){         //此时curr为前驱节点了
            Node* del = curr->next;
            curr->next = del->next;
            free(del);
        }else{
            curr = curr->next;
        }
    }
}

//打印链表
void printList(Node* head){
    Node* curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
}

//释放整个链表,防止内存泄漏
void freeList(Node* head){
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main(){
   Node* head = NULL;
   addFirst(&head, 20);  //20
   addFirst(&head, 10);  //10 -> 20
   addLast(&head, 30);   //10 -> 20 -> 30
   addLast(&head, 40);   //10 -> 20 -> 30 -> 40
   printf("初始链表：");
   printList(head);

   freeList(head);
    return 0;
}