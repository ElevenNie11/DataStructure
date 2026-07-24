#include <stdio.h>
int Fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(){
    int n;
    printf("请输入一个数字：");
    scanf("%d", &n);
    printf("斐波那契数列函数Fibonacci(%d)的值：%d", n, Fibonacci(n));
    return 0;
}