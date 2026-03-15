#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller_brute(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();

        // 三重循环枚举所有三元组
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] < target) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        // 关键步骤：排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    // 当前 left 对应的所有 right 都合法
                    count += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    // 示例1
    vector<int> nums1 = { -2, 0, 1, 3 };
    int target1 = 2;
    cout << "暴力解法示例1: " << solution.threeSumSmaller_brute(nums1, target1) << endl; // 输出: 2
    cout << "双指针解法示例1: " << solution.threeSumSmaller(nums1, target1) << endl; // 输出: 2

    // 示例2
    vector<int> nums2 = {1,3,0,-3,-2};
    int target2 = 0;
    cout << "暴力解法示例2: " << solution.threeSumSmaller_brute(nums2, target2) << endl; // 输出: 5
    cout << "双指针解法示例2: " << solution.threeSumSmaller(nums2, target2) << endl; // 输出: 5
    // 示例3
    vector<int> nums3 = { 0 };
    int target3 = 0;
    cout << "暴力解法示例3: " << solution.threeSumSmaller_brute(nums3, target3) << endl; // 输出: 0
    cout << "双指针解法示例3: " << solution.threeSumSmaller(nums3, target3) << endl; // 输出: 0
    return 0;
}