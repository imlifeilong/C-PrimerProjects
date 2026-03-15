#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// 定义一个解决方案类
class Solution {
public:
    /**
     * @brief 方法一：暴力解法
     *
     * 思路：先计算数组中每个元素的平方，然后对整个数组进行排序。
     * 这种方法简单直观，但效率不是最优的。
     *
     * 时间复杂度: O(N log N)，其中 N 是数组 nums 的长度。
     * - 遍历计算平方需要 O(N) 的时间。
     * - sort 函数的平均时间复杂度为 O(N log N)。
     * 总体复杂度由排序步骤决定。
     *
     * 空间复杂度: O(log N) 或 O(N)，取决于 sort 函数的具体实现。
     *
     * @param nums 输入的有序整数数组。
     * @return vector<int> 每个数字的平方组成的新的有序数组。
     */
    vector<int> sortedSquares_brute(vector<int>& nums) {
        // 1. 遍历数组，计算每个元素的平方并原地替换
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }

        // 2. 使用标准库的 sort 函数对平方后的数组进行升序排序
        sort(nums.begin(), nums.end());

        // 3. 返回排序后的结果
        return nums;
    }

    /**
     * @brief 方法二：双指针解法 (更优解)
     *
     * 思路：利用原数组的有序性，平方后的最大值一定出现在原数组的两端。
     * 因此，可以用两个指针分别指向数组的开头和结尾，比较它们的平方值，
     * 将较大的平方值从结果数组的末尾开始向前填充。
     *
     * 时间复杂度: O(N)，其中 N 是数组 nums 的长度。
     * - 只需要遍历数组一次。
     *
     * 空间复杂度: O(N)，用于存储结果数组。
     *
     * @param nums 输入的有序整数数组。
     * @return vector<int> 每个数字的平方组成的新的有序数组。
     */
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        // 创建一个与输入数组等长的结果数组，并将所有元素初始化为0
        vector<int> result(n, 0);

        // 初始化左右指针，分别指向数组的首尾
        int left = 0, right = n - 1;
        // 初始化结果数组的填充位置指针，从末尾开始
        int pos = n - 1;

        // 当左指针在右指针左侧或重合时，继续循环
        while (left <= right) {
            // 计算左右指针所指元素的平方
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            // 比较两个平方值的大小
            if (leftSquare > rightSquare) {
                // 如果左指针的平方更大，则将其放入结果数组的当前位置
                result[pos] = leftSquare;
                left++;  // 左指针向右移动，寻找下一个可能的最大值
            }
            else {
                // 如果右指针的平方更大或相等，则将其放入结果数组的当前位置
                result[pos] = rightSquare;
                right--; // 右指针向左移动，寻找下一个可能的最大值
            }
            pos--; // 结果数组的填充位置向前移动一位
        }

        // 返回构建好的结果数组
        return result;
    }
};


/**
 * @brief 主函数，用于测试 Solution 类中的方法
 */
int main() {
    // 准备两个测试用例
    vector<int> nums1 = { -4, -1, 0, 3, 10 };
    vector<int> nums2 = { -7, -3, 2, 3, 11 };

    // 创建 Solution 类的实例
    Solution solution;

    // --- 测试暴力解法 ---
    // 注意：暴力解法会修改原始数组，因此最好传递一个副本以避免影响后续代码
    vector<int> result1_brute = solution.sortedSquares_brute(nums1);
    cout << "示例1 (暴力解法) 结果: ";
    for (int num : result1_brute) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2_brute = solution.sortedSquares_brute(nums2);
    cout << "示例2 (暴力解法) 结果: ";
    for (int num : result2_brute) {
        cout << num << " ";
    }
    cout << endl << "------------------------" << endl;


    // --- 测试双指针解法 ---
    vector<int> result1 = solution.sortedSquares(nums1);
    cout << "示例1 (双指针) 结果: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2 = solution.sortedSquares(nums2);
    cout << "示例2 (双指针) 结果: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}