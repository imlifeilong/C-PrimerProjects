#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // 存储最终符合条件的三元组结果
        int n = nums.size();        // 获取数组长度，用于控制循环边界

        // 对数组进行排序：1.便于双指针按大小方向移动调整总和；2.方便跳过重复元素去重
        sort(nums.begin(), nums.end());

        // 外层循环：固定三元组的第一个元素nums[i]，i的范围到n-2（需预留两个位置给left和right指针）
        for (int i = 0; i < n - 2; i++) {
            // 跳过重复的第一个元素：若当前i不是起始位置且与前一个元素值相同，直接跳过
            // 避免因nums[i]重复导致结果中出现重复的三元组
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 初始化双指针：left指向i的下一个元素（三元组第二个元素），right指向数组末尾（三元组第三个元素）
            int left = i + 1;
            int right = n - 1;

            // 双指针遍历：在left < right的条件下寻找和为0的组合
            while (left < right) {
                // 计算当前三元组的总和
                int total = nums[i] + nums[left] + nums[right];

                if (total == 0) {
                    // 找到和为0的三元组，将其加入结果集
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 跳过left指针的重复元素：避免因nums[left]重复导致重复三元组
                    // 需保证left < right防止数组越界
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // 跳过right指针的重复元素：同理避免nums[right]重复导致的重复三元组
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // 双指针同时移动：寻找下一组可能的组合（此时重复元素已跳过）
                    left++;
                    right--;
                }
                else if (total < 0) {
                    // 总和小于0，说明需要增大数值，左指针右移（数组已排序，右侧元素更大）
                    left++;
                }
                else {
                    // 总和大于0，说明需要减小数值，右指针左移（数组已排序，左侧元素更小）
                    right--;
                }
            }
        }

        // 返回所有符合条件的不重复三元组
        return result;
    }


    vector<vector<int>> threeSum_brute(vector<int>& nums) {
        vector<vector<int>> res; // 存储最终符合条件的三元组结果
        sort(nums.begin(), nums.end()); // 对数组排序，便于后续去重（相同元素相邻）
        int n = nums.size(); // 获取数组长度，用于控制循环边界

        // 第一层循环：遍历三元组的第一个元素，范围到n-2（需预留两个位置给j和k）
        for (int i = 0; i < n - 2; i++) {
            // 去重：若当前i不是第一个元素且与前一个元素值相同，跳过（避免重复三元组）
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 第二层循环：遍历三元组的第二个元素，起始于i+1（保证j > i），范围到n-1（预留一个位置给k）
            for (int j = i + 1; j < n - 1; j++) {
                // 去重：若当前j不是i+1的第一个元素且与前一个元素值相同，跳过
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 第三层循环：遍历三元组的第三个元素，起始于j+1（保证k > j），范围到数组末尾
                for (int k = j + 1; k < n; k++) {
                    // 去重：若当前k不是j+1的第一个元素且与前一个元素值相同，跳过
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    // 判断当前三元组的和是否为0，若是则将该三元组加入结果集
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }

        return res; // 返回所有符合条件的三元组
    }

};

// 测试函数
int main() {
    Solution solution;
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    cout << "输入: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    //vector<vector<int>> result = solution.threeSum(nums);
    
    vector<vector<int>> result = solution.threeSum_brute(nums);

    cout << "输出: ";
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}