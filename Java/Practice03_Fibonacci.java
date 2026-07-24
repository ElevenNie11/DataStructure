package Java;

import java.util.Scanner;

public class Practice03_Fibonacci{
    static int Fibonacci(int n){
        if(n == 0 || n == 1){
            return n;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
    public static void main(String[] args){
        Scanner Input = new Scanner(System.in);
        System.out.print("请输入一个数字：");
        int n = Input.nextInt();
        System.out.print("斐波那契数列函数Fibonacci(x)的值：" + Fibonacci(n));
        Input.close();
    }
}