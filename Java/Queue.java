package Java;
import java.util.Deque;
import java.util.ArrayDeque;

public class Queue {
    static void main(String[] args){
        Deque<Integer> queue = new ArrayDeque<>();
        //1. 从队尾插入：等价于addLast()
        queue.offer(10);
        queue.offer(20);
        queue.offer(30);

        //2.从队头取出并删除 
        System.out.println(queue.poll());  //10
        System.out.println(queue.poll());  //20

        queue.offer(40);
        queue.offer(50);

        while(!queue.isEmpty()){
            System.out.println(queue.poll()); //30 40 50
        }
        System.out.println(queue.isEmpty() ? "空队列" : "队列还没空");
    }
}
