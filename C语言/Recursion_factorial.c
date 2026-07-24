//递归经典问题：阶乘（递归就是函数自己调用自己）
// n! = n × (n-1) × (n-2) × ... × 1
#include <stdio.h>
//用递归写阶乘函数：
int factorial(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return n * factorial(n - 1); //规模越来越小：n - 1
}

//用循环写阶乘函数：
int factorial2(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result = result * i;
    }
    return result;
}

int main(){
    int num;
    printf("请输入一个数字：");
    scanf("%d", &num);
    printf("递归写的函数阶乘结果为：%d\n", factorial(num));
    printf("循环写的函数阶乘结果为：%d", factorial2(num));
    return 0;
}