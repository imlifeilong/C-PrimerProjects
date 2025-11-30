#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // 排序数组
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // 跳过重复的第一个数
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 提前剪枝：如果当前最小和已经大于目标值，结束循环
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            // 提前剪枝：如果当前最大和仍然小于目标值，跳过当前循环
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // 跳过重复的第二个数
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 提前剪枝
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });

                        // 跳过重复元素
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
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