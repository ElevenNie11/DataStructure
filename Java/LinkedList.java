package Java;
//实现一个节点:Java 用类实现
class Node{
    public int data;
    public Node next;
    Node(int data){
        this.data = data;
        this.next = null;
    }
}

//实现一个简单的单链表
class CreateLinkedList{
    private Node head;   //头节点：只需要记住头节点，就能顺着 next 找到所有节点
    //头插
    void addFirst(int data){
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
    //尾插
    void addLast(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            return ;
        }
        Node curr = head;
        while(curr.next != null){
            curr = curr.next;
        }
        curr.next = newNode;
    }
    //遍历打印
    void printList(){
        Node curr = head;
        while(curr != null){
            System.out.print(curr.data + " ");
            curr = curr.next;                 //更新 curr 指向下一个节点
        }
        System.out.println();
    }
}

public class LinkedList {
    public static void main(String[] args) {
        CreateLinkedList list = new CreateLinkedList();
        list.addFirst(1);
        list.addFirst(2);
        list.addLast(3);
        list.printList(); // 输出: 2 1 3
    }
}
