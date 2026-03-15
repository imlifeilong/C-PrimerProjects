#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        // 相向移动指针，交换字符
        while (left < right) {
            // 交换左右指针指向的字符
            swap(s[left], s[right]);
            // 左指针右移，右指针左移
            left++;
            right--;
        }
    }
};

int main() {
    Solution solution;

    // 测试示例
    vector<char> s1 = { 'h', 'e', 'l', 'l', 'o' };
    cout << "Before: ";
    for (char ch : s1) cout << ch;
    cout << endl;

    solution.reverseString(s1);

    cout << "After: ";
    for (char ch : s1) cout << ch;
    cout << endl;

    vector<char> s2 = { 'H', 'a', 'n', 'n', 'a', 'h' };
    cout << "Before: ";
    for (char ch : s2) cout << ch;
    cout << endl;

    solution.reverseString(s2);

    cout << "After: ";
    for (char ch : s2) cout << ch;
    cout << endl;

    return 0;
}