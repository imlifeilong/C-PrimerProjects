#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence_brute(string s, string t) {
        // 记录在t中当前查找的起始位置
        int start = 0;

        // 遍历s中的每个字符
        for (char c : s) {
            bool found = false;

            // 在t中从start位置开始查找当前字符
            for (int i = start; i < t.length(); i++) {
                if (t[i] == c) {
                    found = true;
                    start = i + 1;  // 更新下次查找的起始位置
                    break;  // 找到后就跳出内层循环
                }
            }

            // 如果在t中没找到当前字符，返回false
            if (!found) {
                return false;
            }
        }

        // s中所有字符都找到了
        return true;
    }
    bool isSubsequence(string s, string t) {
        int i = 0;  // s的指针
        int j = 0;  // t的指针

        // 同时遍历两个字符串
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                // 找到匹配，两个指针都向后移动
                i++;
            }
            // 无论是否匹配，t的指针都要向后移动
            j++;
        }

        // 如果s的所有字符都匹配到了，i会等于s的长度
        return i == s.length();
    }
};

int main() {
    Solution solution;

    // 测试示例1
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << "Example 1:" << endl;
    cout << "s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    //cout << "Result: " << (solution.isSubsequence_brute(s1, t1) ? "true" : "false") << endl;
    cout << "Result: " << (solution.isSubsequence(s1, t1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // 测试示例2
    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << "Example 2:" << endl;
    cout << "s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    //cout << "Result: " << (solution.isSubsequence_brute(s2, t2) ? "true" : "false") << endl;
    cout << "Result: " << (solution.isSubsequence(s2, t2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;

    return 0;
}