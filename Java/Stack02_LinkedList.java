package Java;
//定义节点
class Node{
    public int data;
    public Node next;
    Node(int data){
        this.data = data;
        this.next = null;
    }
}
//链表头部插入/删除是O(1),正好拿来当栈顶,不需要遍历
class LinkedStack{
    private Node top;

    void push(int value){
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;     //更新栈顶
    }

    int pop(){
        int value = top.data;
        top = top.next;
        return value;
    }
}