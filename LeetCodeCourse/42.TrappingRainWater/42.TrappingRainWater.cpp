// 包含输入输出流头文件，用于cout输出结果
#include <iostream>
// 包含vector容器头文件，用于存储柱子高度的动态数组
#include <vector>
// 包含算法库头文件，用于max/min等常用算法函数
#include <algorithm>

// 使用std命名空间，避免重复书写std::前缀
using namespace std;

// 解决方案类：封装接雨水问题的三种解法
class Solution {
public:
    /**
     * 暴力解法：逐个位置计算能接的雨水量
     * 核心思路：
     * 对于每个位置i，能接的雨水量 = min(左边最大高度, 右边最大高度) - 当前高度
     * 缺点：时间复杂度O(n²)，每个位置都要遍历左右找最大高度，效率低
     * @param height 存储柱子高度的数组
     * @return 总共能接的雨水量
     */
    int trap_brute(vector<int>& height) {
        // 获取柱子数量
        int n = height.size();
        // 边界条件：无柱子时接水量为0
        if (n == 0) return 0;

        // 存储总接水量
        int ans = 0;

        // 遍历每个柱子位置，计算该位置能接的水量
        for (int i = 0; i < n; i++) {
            // 初始化当前位置左边的最大高度
            int left_max = 0;
            // 初始化当前位置右边的最大高度
            int right_max = 0;

            // 向左遍历，找到位置i左侧（包含i）的最大柱子高度
            for (int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }

            // 向右遍历，找到位置i右侧（包含i）的最大柱子高度
            for (int j = i; j < n; j++) {
                right_max = max(right_max, height[j]);
            }

            // 当前位置能接的水量 = 左右最大高度的较小值 - 当前柱子高度
            ans += min(left_max, right_max) - height[i];
        }

        // 返回总接水量
        return ans;
    }

    /**
     * 动态规划优化解法：预处理左右最大高度数组，避免重复计算
     * 核心思路：
     * 1. 预先用left_max数组存储每个位置i左侧的最大高度
     * 2. 预先用right_max数组存储每个位置i右侧的最大高度
     * 3. 遍历每个位置，用预处理的数组计算接水量
     * 时间复杂度O(n)，空间复杂度O(n)
     * @param height 存储柱子高度的数组
     * @return 总共能接的雨水量
     */
    int trap_dp(vector<int>& height) {
        // 获取柱子数量
        int n = height.size();
        // 边界条件：无柱子时接水量为0
        if (n == 0) return 0;

        // left_max[i]：位置i及左侧的最大柱子高度
        vector<int> left_max(n);
        // right_max[i]：位置i及右侧的最大柱子高度
        vector<int> right_max(n);

        // 初始化left_max数组：第一个位置的左侧最大高度就是自身
        left_max[0] = height[0];
        // 从左到右遍历，计算每个位置的left_max
        for (int i = 1; i < n; i++) {
            // 当前left_max = 前一个位置的left_max 和 当前高度的较大值
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 初始化right_max数组：最后一个位置的右侧最大高度就是自身
        right_max[n - 1] = height[n - 1];
        // 从右到左遍历，计算每个位置的right_max
        for (int i = n - 2; i >= 0; i--) {
            // 当前right_max = 后一个位置的right_max 和 当前高度的较大值
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // 存储总接水量
        int ans = 0;
        // 遍历每个位置，计算总接水量
        for (int i = 0; i < n; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        // 返回总接水量
        return ans;
    }

    /**
     * 双指针最优解法：空间复杂度优化至O(1)
     * 核心思路：
     * 1. 用left和right指针分别指向数组两端，向中间移动
     * 2. 维护left_max（左指针左侧的最大高度）和right_max（右指针右侧的最大高度）
     * 3. 若height[left] < height[right]：左侧高度更小，接水量由left_max决定
     *    - 若当前height[left] >= left_max，更新left_max
     *    - 否则，计算当前位置能接的水量（left_max - height[left]）
     *    - 左指针右移
     * 4. 反之：右侧高度更小，接水量由right_max决定，逻辑同上，右指针左移
     * 时间复杂度O(n)，空间复杂度O(1)
     * @param height 存储柱子高度的数组
     * @return 总共能接的雨水量
     */
    int trap(vector<int>& height) {
        // 获取柱子数量
        int n = height.size();
        // 边界条件：无柱子时接水量为0
        if (n == 0) return 0;

        // 左指针：初始指向数组最左端
        int left = 0;
        // 右指针：初始指向数组最右端
        int right = n - 1;
        // 左指针左侧的最大高度
        int left_max = 0;
        // 右指针右侧的最大高度
        int right_max = 0;
        // 总接水量
        int ans = 0;

        // 左右指针未相遇时循环
        while (left < right) {
            // 左侧柱子高度 < 右侧柱子高度：处理左指针
            if (height[left] < height[right]) {
                // 当前左指针位置的高度 >= left_max：更新最大高度（无法接水）
                if (height[left] >= left_max) {
                    left_max = height[left];
                }
                // 当前高度 < left_max：可以接水，累加接水量
                else {
                    ans += left_max - height[left];
                }
                // 左指针右移
                left++;
            }
            // 右侧柱子高度 <= 左侧柱子高度：处理右指针
            else {
                // 当前右指针位置的高度 >= right_max：更新最大高度（无法接水）
                if (height[right] >= right_max) {
                    right_max = height[right];
                }
                // 当前高度 < right_max：可以接水，累加接水量
                else {
                    ans += right_max - height[right];
                }
                // 右指针左移
                right--;
            }
        }

        // 返回总接水量
        return ans;
    }
};

// 主函数：测试三种解法的正确性（当前测试的是dp解法，可注释切换）
int main() {
    // 创建Solution对象，用于调用接雨水的方法
    Solution solution;

    // 示例 1：经典测试用例
    vector<int> height1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
     //int result1 = solution.trap_brute(height1);  // 暴力解法
    //int result1 = solution.trap_dp(height1);       // 动态规划解法
     int result1 = solution.trap(height1);        // 双指针解法
    cout << "示例 1 结果: " << result1 << endl;    // 预期输出：6

    // 示例 2：右侧有更高柱子的测试用例
    vector<int> height2 = { 4,2,0,3,2,5 };
    // int result2 = solution.trap_brute(height2);
    int result2 = solution.trap_dp(height2);
    // int result2 = solution.trap(height2);
    cout << "示例 2 结果: " << result2 << endl;    // 预期输出：9

    // 示例 3：调整初始柱子高度的测试用例
    vector<int> height3 = { 0,2,0,3,1,0,1,3,2,1,2,1 };
    // int result3 = solution.trap_brute(height3);
    int result3 = solution.trap_dp(height3);
    // int result3 = solution.trap(height3);
    cout << "示例 3 结果: " << result3 << endl;    // 预期输出：10

    // 示例 4：对称柱子的测试用例
    vector<int> height4 = { 5,4,3,2,1,0,1,2,3,4,5 };
    // int result4 = solution.trap_brute(height4);
    int result4 = solution.trap_dp(height4);
    // int result4 = solution.trap(height4);
    cout << "示例 4 结果: " << result4 << endl;    // 预期输出：25

    return 0;
}