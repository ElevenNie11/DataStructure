//C语言没有现成的哈希表，而且n是连续的，就用[数组]来缓存即可
#include <stdio.h>
#define MaxSize 100
//全局数组
//C语言的全局数组，默认会被初始化为全0
int memo[MaxSize];      //缓存数组,用来存已经算过的结果
int computed[MaxSize];  //标记数组,记录某个位置是否已经算过(因为0本身也是合法的fib值,不能只靠"是不是0"来判断有没算过)

int Fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    if(computed[n]){   //已经算过，直接查表返回
        return memo[n];
    }
    int result = Fibonacci(n - 1) + Fibonacci(n - 2);
    memo[n] = result; //保存起来
    computed[n] = 1;  //标记为“已计算”

    return result;
}
int main(){
    int n;
    printf("请输入一个数字：");
    scanf("%d", &n);
    printf("斐波那契数列函数Fibonacci(%d)的值：%d", n, Fibonacci(n));
    return 0;
}