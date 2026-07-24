//递归经典问题：阶乘（递归就是函数自己调用自己）
// n! = n × (n-1) × (n-2) × ... × 1
package Java;
import java.util.Scanner;

public class Recursion_factorial{
    static int factorial(int num){
        if(num == 0 || num == 1){  //base case(基线条件/终止条件)
            return num;
        }
        return num*factorial(num - 1); //recursion case(递归条件)
    }
    public static void main(String[] args){
        Scanner Input = new Scanner(System.in);
        System.out.print("请输入数字：");
        int num = Input.nextInt();
        System.out.print("阶乘结果为：" + factorial(num));
        Input.close();
    }
}