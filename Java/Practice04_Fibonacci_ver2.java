package Java;
import java.util.HashMap;
import java.util.Scanner;

public class Practice04_Fibonacci_ver2 {
    static HashMap<Integer, Integer> memo = new HashMap<>();
    static int Fibonacci(int n){
        if(n == 0 || n == 1){
            return n;
        }
        if(memo.containsKey(n)){     //已经算过,直接查表返回
            return memo.get(n);
        }
        int result = Fibonacci(n - 1) + Fibonacci(n - 2);
        memo.put(n, result);         //存起来,以后不用重复算
        return result;
    }
    public static void main(String[] args){
        Scanner Input = new Scanner(System.in);
        System.out.print("请输入一个数字：");
        int n = Input.nextInt();
        System.out.printf("斐波那契数列函数Fibonacci(%d)的值：%d", n, Fibonacci(n));
        Input.close();
    }
}