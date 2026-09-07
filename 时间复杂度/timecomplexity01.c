// 频度
#include <stdio.h>
int main(){
    int x = 91;
    int y = 100;
    if(x > 100){
        x -= 10;
        y--;
    }else{
        x++;
    }
    return 0;
}

// if语句执行了多少次？1100次
// x++执行了多少次？1000次
// y--执行了多少次？100次