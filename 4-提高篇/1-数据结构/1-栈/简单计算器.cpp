#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node_Cal {
    double num; //op num
    char op;    //op char
    bool flag;  //true: op num;; false: op char
};
string str, my_str;         // 原生输入序列
stack<node_Cal> s, Sequence_op;  //操作符栈
queue<node_Cal> q, Queue_list;  //后缀表达式序列
map<char, int> op;  //

// 中缀转后缀
/*若单词是操作数 -- 》 直接添加后缀表达式列表的末尾；；
 * 若～是操作符， 则压入栈顶：： 1。比较与栈顶操作符间优先级 2。若高弹出栈顶加入到输出列表末尾 3。直到栈顶操作符优先级低于它 */
void Change() {
    double num;
    node_Cal temp;
    for (int i = 0; i < str.length(); ++i) {    // 遍历整个输入表
        if (str[i] >= '0' && str[i] <= '9') {      //op num 数字
            temp.flag = true;   // 标记node_Cal 数字数
            temp.num = str[i] - '0';    //将此数值记录下来
            i++;
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        } else {                                  //op char 操作符
            temp.flag = false;  // 当操作符栈顶比这个操作符优先级高,就将操作符栈顶弹出到后缀表达式队列
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
        }
    }
}

void Changess(){
    double num;
    node_Cal temp;
    for (int i = 0; i < str.length();) {
        if(str[i] >= '0' && str[i] <= '9'){
            temp.flag = true;
            temp.num = str[i] - '0';
            i++;
            while (i < str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        }
        else{
            temp.flag = false;
            while (!s.empty() && op[str[i] <= op[s.top().op]]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

    }
}

void Convert_Cal() {
    double num;
    node_Cal temp;
    for (int i = 0; i < str.length();) {
        if (my_str[i] >= '0' && my_str[i] <= '9') {   //tag for num flag
            temp.flag = true;   //标记数字
            temp.num = str[i++] - '0';  // 记录操作数第一个数位
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
            }
        }
    }
}
/* 1。 队列方法 */
// string 中 erase 方法直接把表达式中空格去掉

//
// Created by 陈至宇 on 2022/3/6.
//

