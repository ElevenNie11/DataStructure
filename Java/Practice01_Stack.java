//括号匹配问题
package Java;
//Java直接用Deque当栈用
import java.util.Deque;
import java.util.ArrayDeque;

public class Practice01_Stack {
    //如果在main函数里不创建对象而直接调用函数的话，必须得是static
    static boolean isValid(String str){
        Deque<Character> stack = new ArrayDeque<>();  //这行代码在创建一个能当栈用的容器
        for(char c : str.toCharArray()){
            //左括号：压栈
            if(c == '(' || c == '{' || c == '['){
                stack.push(c);
            }else{ //右括号：弹栈比对
                if(stack.isEmpty()){
                    return false;
                }
                char top = stack.pop();
                if(!isMatch(top, c)){
                    return false;
                }
            }
        }
        return stack.isEmpty();  //遍历完，栈必须为空:栈里没有元素时返回 true,还有元素时返回 false
    }
    static boolean isMatch(char left, char right){
        if((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')){
            return true;
        }else{
            return false;
        }
    }
    public static void main(String[] args){
        String test1 = "({[]})"; 
        String test2 = "([)]";
        String test3 = "(()";

        System.out.println(isValid(test1) ? "合法" : "不合法");
        System.out.println(isValid(test2) ? "合法" : "不合法");
        System.out.println(isValid(test3) ? "合法" : "不合法");
    }
}
