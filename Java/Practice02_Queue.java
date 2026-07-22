//用两个栈实现一个队列
//真正的队列应该长这样：别人只需要调用 enqueue(x) 和 dequeue(),不用管内部是怎么用两个栈折腾的
package Java;
import java.util.Deque;
import java.util.Scanner;
import java.util.ArrayDeque;

public class Practice02_Queue {
    static Deque<Integer> stackIn = new ArrayDeque<>();   //创建一个能当[栈]使用的容器
    static Deque<Integer> stackOut = new ArrayDeque<>();  //关键字static可以使得main函数调用它们时无需new一个对象

    //1. 入队：push进stackIn
    //因为main函数诗static的 所以这些函数也要有static关键字
    static void enqueue(int value){
        stackIn.push(value);
    }

    //2. 出队：核心逻辑
    static int dequeue(){
        //只有当stackOut为空，才需要把stackIn装进去
        if(stackOut.isEmpty()){
            while(!stackIn.isEmpty()){
                stackOut.push(stackIn.pop());
            }
        }
        return stackOut.pop();
    }

    //3. 辅助函数
    static boolean isEmpty(){
        if(stackIn.isEmpty() && stackOut.isEmpty()){
            return true;
        }
        return false;
    }

    //4. 主函数
    public static void main(String[] args){
        Scanner Input = new Scanner(System.in);
        System.out.print("请输入要入队的数字个数：");
        int count = Input.nextInt();
        System.out.print("请输入您的数字：");
        for(int i = 0; i < count; i++){
            int num = Input.nextInt();
            //入队
            enqueue(num);
        }

        System.out.println("现在开始依次出队：");
        while(!isEmpty()){
            //出队
            System.out.println(dequeue());
        }
        Input.close();
    }
}