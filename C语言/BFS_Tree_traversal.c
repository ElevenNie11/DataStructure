#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

//1. 定义一个二叉树节点
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//2. 创建一个二叉树的节点
TreeNode* createNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//3. BFS（广度优先遍历）方法
void BFS_Method(TreeNode*root){
    if(root == NULL){
        return ;
    }
    //用数组模拟队列
    TreeNode* queue[MaxSize];
    int front = 0;     //队头指针(队头下标)：下一次dequeue会从这里取
    int rear = 0;      //队尾指针(队尾下标)：下一次enqueue会从这里删
    //根节点入队
    queue[rear++] = root;
    while(front < rear){
        //出队
        TreeNode* node = queue[front++];
        //访问该节点
        printf("%d ", node->data);
        //左孩子入队
        if(node->left != NULL){
            queue[rear++] = node->left;
        }
        //右孩子入队
        if(node->right != NULL){
            queue[rear++] = node->right;
        }
    }
}

//主函数
int main(){
    //创建树
    TreeNode* node1 = createNode(1);
    TreeNode* node2 = createNode(2);
    TreeNode* node3 = createNode(3);
    TreeNode* node4 = createNode(4);
    TreeNode* node5 = createNode(5);
    TreeNode* node6 = createNode(6);

    //构建树结构
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    //执行BFS遍历
    printf("BFS结果:\n");
    BFS_Method(node1);

    return 0;
}