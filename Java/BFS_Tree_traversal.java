package Java;
import java.util.Queue;
import java.util.LinkedList;

public class BFS_Tree_traversal {
        //          1
        //        /   \
        //       2     3
        //      / \     \
        //     4   5     6
    //定义二叉树节点
    //由于TreeNode类已经定义好了，所以我们可以直接使用它来创建二叉树节点
    //BFS（广度优先搜索）遍历二叉树的思路是：从根节点开始，先访问根节点，然后访问根节点的左子节点，再访问根节点的右子节点，然后再访问左子节点的左子节点，左子节点的右子节点，右子节点的左子节点，右子节点的右子节点，以此类推，直到所有节点都被访问过为止。
    public static void BFS_Method(TreeNode root){
        //检查根节点是否为空
        if(root == null){
            return;
        }
        //创建队列
        Queue<TreeNode> queue = new LinkedList<>();
        //1. 根节点入队
        queue.offer(root);
        //2. 队列不为空一直循环：直到为空
        while(!queue.isEmpty()){
            //3. 出队一个节点
            TreeNode node = queue.poll();
            //4. 访问该节点
            System.out.print(node.data + " ");
            //5. 左孩子入队
            if(node.left != null){
                queue.offer(node.left);
            }
            //6. 右孩子入队
            if(node.right != null){
                queue.offer(node.right);
            }
        }
    }
    //主函数
    public static void main(String[] args){
        //创建二叉树
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);

        //创建树结构：连接起来
        node1.left = node2;
        node1.right = node3;
        node2.left = node4;
        node2.right = node5;
        node3.right = node6;

        //调用BFS方法
        System.out.println("BFS遍历二叉树的结果：");
        BFS_Method(node1);
    }
}
