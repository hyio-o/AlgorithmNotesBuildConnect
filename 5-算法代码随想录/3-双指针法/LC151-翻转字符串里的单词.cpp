#include "../1-数组定义.h"
/* 1. 首尾空格去除
 * 2. 多余空格去除
 * 3. 倒序单词顺序
 * */

// 0 使用辅助空间 空格前的单词使用重新排序
/*
class Sol{
public:
    vector<char>& str_new;
    string reverseWords(string s)
    {
        blankErase(s);
        int index_rear = s.size();
    }
private:
    string blankErase(string str_old)
    {
        int index_slow = 0, index_fast = 1;
        while(str_old[index_slow] == ' '){  // 去除头部空格
            index_slow++;
            str_old.resize(str_old.size()-1);
        }
        for (index_slow = 0; index_fast < str_old.size() ; ++index_fast) {
            if(str_old[index_slow] == ' '){
                while (str_old[index_fast] == ' ')  ++index_fast;
                str_old[index_slow+1] = str_old[index_fast];
                index_slow++;
            }
        }
        if(str_old[index_slow == ' '])  --index_slow;   // 结束尾部空格
        str_old.resize(index_slow);
    }
};

*/

// 1 不要使用辅助空间，空间复杂度要求为O(1)。
class Solution{
public:
    // 逆转整个字符串 #include "./反转字符串"
    void reverseStr(string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j) {
            mySwap(s[i], s[j]);
        }
    }
    // 去除所有空格，并在相邻单词间增加空格

    void removeExtraSpacesVOne(string& str)
    {
        int index_slow = 0, index_fast = 0; // index_
        // 1. 删掉开头的多余空格
        while (str.size() > 0 && index_fast < str.size() && str[index_fast] == ' '){
            index_fast++;
        }
        // 2. 删掉中间冗余空格 : 双指针  ;; index_fast 变成了真值下标的头， index_slow 现在还是0；

//        for ( ; index_fast < str.size(); index_fast++) {
//            if(index_fast -1 > 0
//                && str[index_fast - 1] == str[index_fast]
//                && str[index_fast] == ' '
//                ){
//                continue;
//            }
//            else{
//                str[index_slow] = str[index_fast];
//                index_slow++;
//            }
//        }

        // is_space 为 false，表示前一个字符不是空格。
        for (bool is_space = false ; index_fast < str.size(); index_fast++) {
            if (str[index_fast] == ' ') {
                if (!is_space) {
                    str[index_slow++] = ' ';
                    is_space = true;
                }
                else continue;  // is_space == true, 前面一个字符是空格， index_slow 不变位置， index_fast 持续向后； 直到 index_fast != ' ';
                // index_slow 是关键
            } else {
                str[index_slow++] = str[index_fast];
                is_space = false;
            }
        }

        // 3. 去掉末尾冗余空格
        if(index_slow - 1 > 0
            && str[index_slow - 1] == ' '){
            str.resize(index_slow-1);
        }else{
            str.resize(index_slow);
        }
    }
    void removeExtraSpacesVTwo(string& str)
    {
        int index_slow = 0;
        bool is_space = false;

        for (int index_fast = 0; index_fast < str.size(); index_fast++) {
            if (str[index_fast] == ' ') {
                if (!is_space) {
                    str[index_slow++] = ' ';
                    is_space = true;
                }
            } else {
                str[index_slow++] = str[index_fast];
                is_space = false;
            }
        }
        str.resize(index_slow);
    }
    void removeExtraSpacesVThree(string& str)
    {
        int index_slow = 0, index_fast = 0;
        for ( ;index_fast < str.size(); index_fast++) {
            if(str[index_fast] != ' ')  //如果当前字符不是空格，表示遇到了一个非空格字符，需要进行处理。 (如果是空格，则 continue）
            {
                if(index_slow != 0) str[index_slow++] = ' ';    // 1.如果 index_slow 不等于 0，说明不是第一个单词，
                // 2.需要在单词前添加一个空格。将空格写入 str[index_slow] 处，并递增 index_slow
                // 将非空格字符写入 str[index_slow] 处，并递增 index_slow 和 index_fast。 一直没有懂的是其中制造的落差 slow 和fast
                // 但是落差之下，直到fast再次遇到空格时候、或fast到头的时候，也就完成了slow本次的使命；
                while(index_fast < str.size() && str[index_fast] != ' ')    str[index_slow++] = str[index_fast++];
                // 那么这样的情况就是首尾和中间的空格都去除了，因为slow完成了 1.判断首个单词 、2.中间单空格 、 3.末尾不留空
            }
        }
        str.resize(index_slow);
    }
    string reverseWords(string str)
    {
        removeExtraSpacesVThree(str); // step one:
        reverseStr(str, 0, str.size()-1);
        int index_slow = 0;
        for (int index_fast = 0; index_fast <= str.size(); ++index_fast) {
            if(index_fast == str.size() || str[index_fast] == ' ')
            {
                reverseStr(str, index_slow, index_fast-1);
                index_slow = index_fast + 1;
            }
        }
        return str;
    }

private:
    void mySwap(char& x, char& y)
    {
        x = x^y;
        y = x^y;
        x = x^y;
    }
};

//
// Created by 陈至宇 on 2023/8/13.
//

/*给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

 Procreate笔刷
链接：https://pan.baidu.com/s/1xQJQmBnP0cjw-vp4QpLfpg
提取码：2222

控笔练习
链接：https://pan.baidu.com/s/15ssuFBb5TH7yxjtMElrIHQ
提取码：2222

色卡
链接：https://pan.baidu.com/s/1mj19Zp0PnagDxJ0tDLsvYA
提取码：2222
#*/