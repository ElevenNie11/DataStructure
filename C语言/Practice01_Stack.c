#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MaxSize 100

//C语言没有现成的栈,得自己用数组简单实现一个字符栈
char stack[MaxSize];
int top = -1;       //栈顶元素的下标

//1. 压栈操作
void push(char c){
    stack[++top] = c; //这里不！可！以！是top++
}

//2. 弹出栈顶元素并返回
char pop(){
    return stack[top--];
}

//3. 查看栈是否为空
bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

//4. 判断俩括号是否匹配
bool isMatch(char left, char right){
    if((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')){
            return true;
    }else{
            return false;
    }
}

//5. 判断字符串是否合法
bool isValid(char* str){
    top = -1;   //重置栈
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        char c = str[i];
        //左括号：压栈
        if(c == '(' || c == '{' || c == '['){
            push(c);
        }else{
            if(isEmpty()){
                return false;
            }
            char topChar = pop();
            if(!isMatch(topChar, c)){
                return false;
            }
        }
    }
    return isEmpty();  //遍历完,栈必须为空,否则说明有左括号没配对
}

int main(){
    char test1[] = "({[]})";
    char test2[] = "([)]";
    char test3[] = "())";

    printf("%s -> %s\n", test1,isValid(test1) ? "合法" : "不合法");
    printf("%s -> %s\n", test2,isValid(test2) ? "合法" : "不合法");
    printf("%s -> %s\n", test3,isValid(test3) ? "合法" : "不合法");

    return 0;
}

// string.h 标准库提供处理字符串的函数：C语言中的字符串其实就是字符数组char[]
//1. strlen(str);          字符串长度：返回的是字符串的长度
//2. strcmp(str1, str2);   字符串比较：在C语言中字符串不可以直接用> < = != 等来比较，必须要用strcmp()函数
//3. strcpy(str1, str2);   字符串拷贝：把str1改成str2

// stdbool1.h 标准库可以使用bool类型的函数以及返回布尔值true和false