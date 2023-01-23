#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// 1. define
string my_str;
string your_str = "hello world";    // 数组形式存储
// 2. visit
void show_str(){
    for (int i = 0; i < your_str.length(); ++i) {
        printf("%c\t", your_str[i]);
    }
}
// 2。2 迭代器
void show_ite_str(){
    string::iterator ite;
    for (ite=your_str.begin(); ite != your_str.end(); ite++) {
        printf("%c\t", *ite);       // ‼️ 需要使用 *ite 才能访问
    }
}
// 3. scanf printf
void scan_str(){
    cin>>my_str;
    cout<<my_str;
}


// 常用函数 实例
// operator ' += '   将两个string 拼接起来
void concat_str(){
    string str1 = "abc", str2 = "xyz", str3;
    str3 = str1 + str2;
    str1 += str2;
    cout<<str1<<endl;
    cout<<str3<<endl;
}
// compare operator == != < <= >= >; 字典序比较
void Compare_str()
{
    string str1 = "abc", str2 = "xyz";
    if (str1<str2) printf("str1<str2");
}

// length() -- 返回string 长度：字符数 / size() --
void require_len()
{
    string str = "alsdjalfsdlf";
    printf("%d %d \t", str.length(), str.size());
}
// insert -- insert(pos, string) / insert(it, it2, it3):it 为地址，it2与it3为区间串
void require_insert(){
    string str1 = "abc", str2 = "xyz";
    str1.insert(str1.begin()+1, str2.begin(), str2.end());
    cout<<str1<<endl;
}
//erase() -- erase(it) / erase(it1, it2)
void require_erase(){
    string str = "123456789";
    str.erase(str.begin() + 2);
    cout<<str<<endl;
    str.erase(str.begin(), str.end()-1);
    cout<<str<<endl;
}
//clear
// substr()
void require_substr(){
    string str = "Thank you for your smile.\n";
    cout<<str.substr(0, 3)<<endl;
}

// string::npos  --find函数匹配失败返回值， 最大值unsigned int
// find(str2) -- 当为子串时， 返回其第一次出现位置， 若不是子串，返回string::npos
// find(str2, pos) -- 后一变量意味： 从pos位置开始匹配

// Created by 陈至宇 on 2022/3/6.
//

#ifndef ALGORITHMNOTESBUILDING_3_STRING_H
#define ALGORITHMNOTESBUILDING_3_STRING_H

#endif //ALGORITHMNOTESBUILDING_3_STRING_H
