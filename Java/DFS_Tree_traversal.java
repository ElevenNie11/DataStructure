package Java;

public class DFS_Tree_traversal {
    //1. 深度优先遍历（DFS）：前序遍历(根→左→右)
    static void preorder(TreeNode root){
        if(root == null){  //base case
            return ;
        }
        System.out.print(root.data + " "); //访问根
        preorder(root.left);               //递归左子树
        preorder(root.right);              //递归右子树
    }

    //2. 深度优先遍历（DFS）：中序遍历(左→根→右)
    static void inorder(TreeNode root){
        if(root == null){
            return ;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    //3. 深度优先遍历（DFS）：后序遍历(左→右→根)
    static void postorder(TreeNode root){
        if(root == null){
            return ;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }
    public static void main(String[] args){
        //手动搭建这棵树:
        //          1
        //        /   \
        //       2     3
        //      / \     \
        //     4   5     6
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        //把节点连接起来
        node1.left = node2;
        node1.right = node3;
        node2.left = node4;
        node2.right = node5;
        node3.right = node6;
        //打印输出结果
        System.out.print("前序遍历: ");
        preorder(node1);
        System.out.println();

        System.out.print("中序遍历: ");
        inorder(node1);
        System.out.println();

        System.out.print("后序遍历: ");
        postorder(node1);
        System.out.println();
    }
}
