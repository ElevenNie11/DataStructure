#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
//1. 深度优先遍历（DFS）：前序遍历(根→左→右)
void preorder(TreeNode* root){
    if(root == NULL){    // base case
        return ;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

//2. 深度优先遍历（DFS）：中序遍历(左→根→右)
void inorder(TreeNode* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//3. 深度优先遍历（DFS）：后序遍历(左→右→根)
void postorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
//创建一个二叉树的节点
TreeNode* createNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main(){
    TreeNode* node1 = createNode(1);
    TreeNode* node2 = createNode(2);
    TreeNode* node3 = createNode(3);
    TreeNode* node4 = createNode(4);
    TreeNode* node5 = createNode(5);
    TreeNode* node6 = createNode(6);
    //连接
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    //打印输出
    printf("前序遍历: ");
    preorder(node1);
    printf("\n");

    printf("中序遍历: ");
    inorder(node1);
    printf("\n");

    printf("后序遍历: ");
    postorder(node1);

    return 0;
}