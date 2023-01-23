#include "../head.h"

/*给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。返回 s 所有可能的分割方案。
示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
#*/
// 取得 len= 回文串.size()， 1. 分割子串  && 2. 保证为回文串
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backTracking(const string &s, int startIndex) {
        // s.size() < startIndex , 则找到了一组分割
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            // 判断回文
            if (isPalindrome(s, startIndex, i)) {
                // 获取[startIndex,i]在s中的子串
                string Str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(Str);
            } else
                continue;
            backTracking(s, i + 1);    // i+1 开始寻找子串
            path.pop_back();
        }

    }

    bool isPalindrome(const string &s, int startIndex, int endIndex) {   // 判断回文
        for (int i = startIndex, j = endIndex; i < endIndex, i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

};
//
// Created by 陈至宇 on 2022/9/23.
//

#ifndef ALGORITHMNOTESBUILDING_131_分割回文串_H
#define ALGORITHMNOTESBUILDING_131_分割回文串_H

#endif //ALGORITHMNOTESBUILDING_131_分割回文串_H
