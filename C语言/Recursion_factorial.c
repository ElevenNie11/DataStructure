//递归经典问题：阶乘（递归就是函数自己调用自己）
// n! = n × (n-1) × (n-2) × ... × 1
#include <stdio.h>
int factorial(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return n * factorial(n - 1); //规模越来越小：n - 1
}

int main(){
    int num;
    printf("请输入一个数字：");
    scanf("%d", &num);
    printf("阶乘结果为：%d", factorial(num));
    return 0;
}