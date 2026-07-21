package Java;

class ArrayStack{
    private int[] data;
    private int top;   //指向栈顶元素的下标

    ArrayStack(int capacity){ //capacity：容积
        data = new int[capacity];
        top = -1;   // -1表示空栈
    }

    void push(int value){
        data[++top] = value;
    }

    int pop(){
        return data[top--];
    }

    int peek(){
        return data[top];
    }

    boolean isEmpty(){
        return top == -1;
    }
}
