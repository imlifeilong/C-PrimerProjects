#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 1. 排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0; // 指向当前要满足的孩子
        int cookie = 0; // 指向当前尝试的饼干

        // 2. 双指针遍历
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // 当前饼干可以满足当前孩子，移动到下一个孩子
                child++;
            }
            // 无论是否满足，当前饼干都已被尝试（满足则用掉，不满足则舍弃），移动到下一个饼干
            cookie++;
        }
        return child; // child 指针移动的次数即为满足的孩子数
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> g1 = { 1, 2, 3 };
    vector<int> s1 = { 1, 1 };
    cout << "示例 1 输出 (双指针解法): " << solution.findContentChildren(g1, s1) << endl; // 预期输出: 1

    // 示例 2
    vector<int> g2 = { 1, 2 };
    vector<int> s2 = { 1, 2, 3 };
    cout << "示例 2 输出 (双指针解法): " << solution.findContentChildren(g2, s2) << endl; // 预期输出: 2

    return 0;
}