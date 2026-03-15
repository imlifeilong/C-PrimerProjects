#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome_brute(string s) {
        // 过滤字符串，只保留字母和数字，并转换为小写
        string filteredStr;
        for (char ch : s) {
            if (isalnum(ch)) {
                filteredStr += tolower(ch);
            }
        }

        // 创建反转字符串
        string reversedStr = filteredStr;
        reverse(reversedStr.begin(), reversedStr.end());

        // 比较原过滤字符串和反转后的字符串
        return filteredStr == reversedStr;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 移动左指针，直到找到字母或数字
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // 移动右指针，直到找到字母或数字
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 比较字符（忽略大小写）
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // 测试示例
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: " << (solution.isPalindrome_brute(test1) ? "true" : "false") << endl;
    cout << "Test 1: " << (solution.isPalindrome(test1) ? "true" : "false") << endl;

    string test2 = "race a car";
    cout << "Test 2: " << (solution.isPalindrome_brute(test2) ? "true" : "false") << endl;
    cout << "Test 2: " << (solution.isPalindrome(test2) ? "true" : "false") << endl;

    string test3 = " ";
    cout << "Test 3: " << (solution.isPalindrome_brute(test3) ? "true" : "false") << endl;
    cout << "Test 3: " << (solution.isPalindrome(test3) ? "true" : "false") << endl;

    return 0;
}