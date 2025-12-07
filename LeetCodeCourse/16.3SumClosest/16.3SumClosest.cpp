#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest_brute(vector<int>& nums, int target) {
        int n = nums.size(); // 获取数组长度
        // 初始化最接近的和为前三个数的和（初始候选值）
        int closestSum = nums[0] + nums[1] + nums[2];
        // 初始化最小差值为初始和与目标值的绝对差
        int minDiff = abs(closestSum - target);

        // 三层循环枚举所有i<j<k的三元组（暴力枚举所有组合）
        for (int i = 0; i < n - 2; i++) {          // 第一个数的索引i
            for (int j = i + 1; j < n - 1; j++) {  // 第二个数的索引j（j > i）
                for (int k = j + 1; k < n; k++) {  // 第三个数的索引k（k > j）
                    int currentSum = nums[i] + nums[j] + nums[k]; // 当前三元组的和
                    int currentDiff = abs(currentSum - target);   // 当前和与目标值的差值

                    // 如果当前差值更小，更新最接近的和与最小差值
                    if (currentDiff < minDiff) {
                        minDiff = currentDiff;
                        closestSum = currentSum;
                    }

                    // 如果差值为0（完全匹配目标值），直接返回（不可能更接近）
                    if (currentDiff == 0) {
                        return currentSum;
                    }
                }
            }
        }

        return closestSum; // 返回最终找到的最接近和
    }

    /**
     * 优化解法：排序+双指针，降低时间复杂度
     * @param nums 输入的整数数组
     * @param target 目标值
     * @return 最接近目标值的三数之和
     */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 先对数组排序，为双指针操作铺垫
        int n = nums.size();            // 获取数组长度
        int closestSum = nums[0] + nums[1] + nums[2]; // 初始化最接近的和

        // 遍历第一个数的索引i（三元组的第一个元素）
        for (int i = 0; i < n - 2; i++) {
            // 跳过重复的i（优化：避免重复计算相同的三元组）
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;  // 左指针：指向i的下一个元素（三元组第二个元素）
            int right = n - 1; // 右指针：指向数组末尾（三元组第三个元素）

            // 双指针遍历，寻找最优的后两个元素
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right]; // 当前三元组的和

                // 如果当前和等于目标值，直接返回（完全匹配，最接近）
                if (currentSum == target) {
                    return currentSum;
                }

                // 如果当前和更接近目标值，更新最接近的和
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // 根据当前和与目标值的大小关系，移动指针调整和的大小
                if (currentSum < target) {
                    left++; // 和偏小，左指针右移增大和
                }
                else {
                    right--; // 和偏大，右指针左移减小和
                }
            }
        }

        return closestSum; // 返回最终找到的最接近和
    }
};

// 测试代码
int main() {
    Solution solution;

    // 测试用例1
    vector<int> nums1 = { -1, 2, 1, -4 };
    int target1 = 1;
    cout << "数组: [-1, 2, 1, -4], 目标值: " << target1 << endl;
    cout << "最接近的三数之和: " << solution.threeSumClosest_brute(nums1, target1) << endl;
    cout << "最接近的三数之和: " << solution.threeSumClosest(nums1, target1) << endl;

    // 测试用例2
    vector<int> nums2 = { 0, 0, 0 };
    int target2 = 1;
    cout << "\n数组: [0, 0, 0], 目标值: " << target2 << endl;
    cout << "最接近的三数之和: " << solution.threeSumClosest_brute(nums2, target2) << endl;
    cout << "最接近的三数之和: " << solution.threeSumClosest(nums2, target2) << endl;

    return 0;
}