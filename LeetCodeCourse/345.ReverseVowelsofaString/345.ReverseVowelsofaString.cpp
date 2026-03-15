// 包含输入输出流库，用于控制台输入输出操作
#include <iostream>
// 包含字符串处理库，用于 string 类型的定义和操作
#include <string>
// 包含无序集合库，用于快速查找元音字母（平均查找时间复杂度 O(1)）
#include <unordered_set>
// 使用 std 命名空间，避免重复书写 std:: 前缀
using namespace std;

// 对应 LeetCode 345. 反转字符串中的元音字母 的解题类
class Solution {
public:
    /**
     * @brief 反转字符串中的所有元音字母，保持非元音字母的位置不变
     * @param s 输入的原始字符串（按值传递，函数内修改的是副本，最终返回修改后的字符串）
     * @return string 反转元音后的字符串
     */
    string reverseVowels(string s) {
        // 创建无序集合存储所有元音字母（包含大小写），用于快速判断字符是否为元音
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U' };

        // 左指针：初始指向字符串头部（索引 0），用于从左向右寻找元音字母
        int left = 0;
        // 右指针：初始指向字符串尾部（索引 s.length()-1），用于从右向左寻找元音字母
        int right = s.length() - 1;

        // 循环条件：左指针在右指针左侧时，继续寻找并交换元音（避免重复交换或越界）
        while (left < right) {
            // 移动左指针：直到找到元音字母 或 左指针超过右指针
            // vowels.find(s[left]) == vowels.end() 表示当前字符不是元音
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++; // 左指针右移，寻找下一个字符
            }

            // 移动右指针：直到找到元音字母 或 右指针被左指针追上
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--; // 右指针左移，寻找前一个字符
            }

            // 此时左右指针均找到元音字母，且左指针在右指针左侧，执行交换
            if (left < right) {
                swap(s[left], s[right]); // 交换两个元音字母的位置
                left++; // 左指针右移，准备寻找下一个元音
                right--; // 右指针左移，准备寻找下一个元音
            }
        }

        // 返回反转元音后的字符串
        return s;
    }
};

// 程序入口函数
int main() {
    // 创建 Solution 类的实例，用于调用反转元音的方法
    Solution solution;

    // 测试示例 1：普通字符串
    string test1 = "hello";
    cout << "Input: " << test1 << endl; // 输出原始输入
    cout << "Output: " << solution.reverseVowels(test1) << endl; // 输出反转后的结果

    // 测试示例 2：包含多个元音的字符串
    string test2 = "leetcode";
    cout << "\nInput: " << test2 << endl;
    cout << "Output: " << solution.reverseVowels(test2) << endl;

    // 测试示例 3：仅包含大小写元音的字符串
    string test3 = "aA";
    cout << "\nInput: " << test3 << endl;
    cout << "Output: " << solution.reverseVowels(test3) << endl;

    // 测试示例 4：混合大小写和非元音的字符串
    string test4 = "IceCreAm";
    cout << "\nInput: " << test4 << endl;
    cout << "Output: " << solution.reverseVowels(test4) << endl;

    return 0; // 程序正常结束
}