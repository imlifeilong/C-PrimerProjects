#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> fourSum_brute(vector<int>& nums, int target) {
        vector<vector<int>> result; // 存储最终结果的二维向量
        int n = nums.size();        // 获取数组长度

        // 边界条件判断：数组元素个数小于4时，不可能存在四元组，直接返回空结果
        if (n < 4) return result;

        // 关键步骤1：排序
        // 作用：1. 便于后续去重（相同元素相邻）；2. 为双指针优化奠定基础（本题暂用四层循环，排序仍为去重必需）
        sort(nums.begin(), nums.end());

        // 关键步骤2：四层循环枚举所有可能的四元组组合（a < b < c < d）
        // 第一层循环：枚举第一个元素nums[a]，a的范围是[0, n-4]（保证后续有3个元素）
        for (int a = 0; a < n - 3; ++a) {
            // 去重逻辑1：跳过与前一个元素相同的nums[a]（避免重复四元组）
            // 条件a > 0：确保a-1不越界；nums[a] == nums[a-1]：当前元素与前一个元素相同
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            // 第二层循环：枚举第二个元素nums[b]，b的范围是[a+1, n-3]（保证后续有2个元素）
            for (int b = a + 1; b < n - 2; ++b) {
                // 去重逻辑2：跳过与前一个元素相同的nums[b]（注意b要大于a+1，避免跳过合法的第一个b值）
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;

                // 第三层循环：枚举第三个元素nums[c]，c的范围是[b+1, n-2]（保证后续有1个元素）
                for (int c = b + 1; c < n - 1; ++c) {
                    // 去重逻辑3：跳过与前一个元素相同的nums[c]（注意c要大于b+1）
                    if (c > b + 1 && nums[c] == nums[c - 1]) continue;

                    // 第四层循环：枚举第四个元素nums[d]，d的范围是[c+1, n-1]
                    for (int d = c + 1; d < n; ++d) {
                        // 去重逻辑4：跳过与前一个元素相同的nums[d]（注意d要大于c+1）
                        if (d > c + 1 && nums[d] == nums[d - 1]) continue;

                        // 核心判断：四数之和是否等于target
                        // 强制转换为long：避免int类型溢出（当nums元素较大时，四数之和可能超出int范围）
                        if ((long)nums[a] + nums[b] + nums[c] + nums[d] == target) {
                            // 符合条件的四元组加入结果集
                            result.push_back({ nums[a], nums[b], nums[c], nums[d] });
                        }
                    }
                }
            }
        }

        return result; // 返回所有不重复的四元组结果
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; // 存储最终结果的二维容器
        int n = nums.size();        // 获取数组长度

        // 边界条件：数组元素少于4个时，不可能存在四元组，直接返回空结果
        if (n < 4) return result;

        // 核心前置操作：排序数组
        // 作用：1. 便于后续去重（重复元素相邻）；2. 支持双指针移动；3. 实现提前剪枝
        sort(nums.begin(), nums.end());

        // 第一层循环：枚举第一个数的索引i，范围[0, n-4]（需预留3个位置给j、left、right）
        for (int i = 0; i < n - 3; i++) {
            // 去重逻辑1：跳过与前一个元素重复的nums[i]，避免生成重复四元组
            // i > 0 防止数组越界，nums[i] == nums[i-1] 表示当前元素与前一个重复
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 剪枝逻辑1：提前终止无效循环（优化性能）
            // 情况1：当前i开头的最小四数和 > target → 后续更大的数也无法满足，直接break整个i循环
            // 强制转换为long：避免int溢出（四数之和可能超过int最大值2^31-1）
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            // 情况2：当前i开头的最大四数和 < target → 当前i无满足可能，跳过该i进入下一轮
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            // 第二层循环：枚举第二个数的索引j，范围[i+1, n-2]（需预留2个位置给left、right）
            for (int j = i + 1; j < n - 2; j++) {
                // 去重逻辑2：跳过与前一个元素重复的nums[j]
                // j > i+1 避免跳过第一个合法的j（j=i+1时即使重复也是首次出现，需保留）
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 剪枝逻辑2：进一步缩小无效循环范围
                // 情况1：当前i、j开头的最小四数和 > target → break当前j循环
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // 情况2：当前i、j开头的最大四数和 < target → 跳过该j进入下一轮
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                // 双指针优化：用left/right替代原本的第三、四层嵌套循环，将时间复杂度从O(n^4)降至O(n^3)
                int left = j + 1;  // 左指针：指向j的下一个元素（第三个数）
                int right = n - 1; // 右指针：指向数组末尾（第四个数）

                // 双指针循环：left < right 保证指针不重叠，避免重复组合
                while (left < right) {
                    // 计算四数之和，强制转换为long防止int溢出
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    // 核心判断：根据和与target的关系调整指针
                    if (sum == target) {
                        // 找到符合条件的四元组，加入结果集
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });

                        // 去重逻辑3：跳过left指针指向的重复元素（避免重复四元组）
                        // left < right 防止指针越界，nums[left] == nums[left+1] 表示当前元素与下一个重复
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 去重逻辑4：跳过right指针指向的重复元素
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        // 指针同时移动：寻找下一组可能的合法组合
                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        // 四数和偏小，需要增大和 → 左指针右移（数组已排序，右移数值变大）
                        left++;
                    }
                    else {
                        // 四数和偏大，需要减小和 → 右指针左移（数组已排序，左移数值变小）
                        right--;
                    }
                }
            }
        }

        return result; // 返回所有不重复的四元组结果
    }
};

// 测试函数
int main() {
    Solution solution;

    // 测试用例1
    vector<int> nums1 = { 1, 0, -1, 0, -2, 2 };
    int target1 = 0;
    cout << "输入: nums = [1,0,-1,0,-2,2], target = 0" << endl;
    vector<vector<int>> result1 = solution.fourSum(nums1, target1);
    //vector<vector<int>> result1 = solution.fourSum_brute(nums1, target1);
    cout << "输出: ";
    for (const auto& quad : result1) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    // 测试用例2
    vector<int> nums2 = { 2, 2, 2, 2, 2 };
    int target2 = 8;
    cout << "输入: nums = [2,2,2,2,2], target = 8" << endl;
    vector<vector<int>> result2 = solution.fourSum(nums2, target2);
    //vector<vector<int>> result2 = solution.fourSum_brute(nums2, target2);
    cout << "输出: ";
    for (const auto& quad : result2) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}