#include <iostream>     // 引入输入输出流库，用于cout打印结果
#include <vector>       // 引入向量容器库，用于存储数组和返回结果
using namespace std;    // 简化命名空间，避免重复书写std::前缀

// 解题类：包含两数之和的两种解法（暴力枚举法 + 双指针优化法）
class Solution {
public:
    /**
     * 两数之和暴力枚举解法
     * 功能：在非递减数组中找到两个数，使其和等于target，返回它们的下标（从1开始）
     * 参数：numbers - 非递减排序的输入整数数组；target - 两数之和的目标值
     * 返回：vector<int> - 存储两个符合条件的下标（按从小到大顺序）
     */
    vector<int> twoSum_brute(vector<int>& numbers, int target) {
        vector<int> result(2);  // 初始化结果数组，长度为2，用于存储两个下标
        int n = numbers.size(); // 获取输入数组的长度

        // 第一层循环：枚举第一个数的索引i，范围[0, n-2]（确保j有合法取值）
        for (int i = 0; i < n - 1; i++) {
            // 第二层循环：枚举第二个数的索引j，范围[i+1, n-1]（避免重复枚举同一对元素）
            for (int j = i + 1; j < n; j++) {
                // 核心判断：两数之和是否等于目标值
                if (numbers[i] + numbers[j] == target) {
                    result[0] = i + 1;  // 题目要求下标从1开始，因此索引+1
                    result[1] = j + 1;
                    return result;      // 找到结果后直接返回，无需继续循环
                }
            }
        }

        return result;  // 题目保证必有唯一解，此语句实际不会执行
    }

    /**
     * 两数之和双指针优化解法（利用数组非递减特性）
     * 功能：在非递减数组中找到两个数，使其和等于target，返回它们的下标（从1开始）
     * 优势：时间复杂度从O(n²)降至O(n)，空间复杂度O(1)
     * 参数：numbers - 非递减排序的输入整数数组；target - 两数之和的目标值
     * 返回：vector<int> - 存储两个符合条件的下标（按从小到大顺序）
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;                          // 左指针：初始指向数组开头（最小元素）
        int right = numbers.size() - 1;        // 右指针：初始指向数组末尾（最大元素）

        // 双指针循环：left < right 保证指针不重叠，避免重复枚举
        while (left < right) {
            int sum = numbers[left] + numbers[right];  // 计算当前左右指针指向元素的和

            if (sum == target) {
                // 找到符合条件的两个数，返回下标（+1适配题目要求）
                return { left + 1, right + 1 };
            }
            else if (sum < target) {
                // 和小于目标值：需要增大和，左指针右移（数组非递减，右移后元素更大）
                left++;
            }
            else {
                // 和大于目标值：需要减小和，右指针左移（数组非递减，左移后元素更小）
                right--;
            }
        }

        // 题目保证必有唯一解，此语句实际不会执行
        return {};
    }
};

// 主函数：测试两种两数之和解法的正确性
int main() {
    Solution solution;  // 创建解题类实例

    // 测试用例1：常规正整数场景，目标和为9
    vector<int> numbers1 = { 2, 7, 11, 15 };
    int target1 = 9;
    vector<int> result1 = solution.twoSum_brute(numbers1, target1);  // 调用暴力解法
    //vector<int> result1 = solution.twoSum(numbers1, target1);      // 切换为双指针解法
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;  // 预期输出[1,2]

    // 测试用例2：三个元素场景，目标和为6
    vector<int> numbers2 = { 2, 3, 4 };
    int target2 = 6;
    vector<int> result2 = solution.twoSum_brute(numbers2, target2);  // 调用暴力解法
    //vector<int> result2 = solution.twoSum(numbers2, target2);      // 切换为双指针解法
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;  // 预期输出[1,3]

    // 测试用例3：包含负数和0的场景，目标和为-1
    vector<int> numbers3 = { -1, 0 };
    int target3 = -1;
    vector<int> result3 = solution.twoSum_brute(numbers3, target3);  // 调用暴力解法
    //vector<int> result3 = solution.twoSum(numbers3, target3);      // 切换为双指针解法
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;  // 预期输出[1,2]

    return 0;  // 程序正常结束
}