#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates_brute(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;
        // 使用while循环，因为数组长度在动态变化[citation:4]
        while (i < nums.size() - 1) {
            if (nums[i] == nums[i + 1]) {
                // 发现重复，将i+1之后的元素整体前移
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                nums.pop_back(); // 移除末尾多余元素
                // 注意：i不递增，因为需要再次检查当前位置的新元素
            }
            else {
                i++; // 没有重复，检查下一个元素
            }
        }
        return nums.size();
    }
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0; // 处理空数组[citation:7]

        int slow = 0; // 慢指针，指向已处理区的末尾[citation:1]
        // 快指针fast从1开始遍历[citation:1]
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) { // 发现新元素
                slow++; // 慢指针先移动到下一个位置
                nums[slow] = nums[fast]; // 将新元素赋值过来[citation:1][citation:5]
            }
            // 如果相等，fast继续前进，slow不动
        }
        return slow + 1; // 新长度为慢指针下标+1[citation:8]
    }
};

int main() {
    Solution solution;
    // 示例 1
    std::vector<int> nums1 = { 1, 1, 2 };
    //int len1 = solution.removeDuplicates_brute(nums1);
    int len1 = solution.removeDuplicates(nums1);
    std::cout << "新长度: " << len1 << std::endl;
    std::cout << "修改后数组: ";
    for (int i = 0; i < len1; i++) std::cout << nums1[i] << " ";
    std::cout << std::endl;

    // 示例 2
    std::vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    //int len2 = solution.removeDuplicates_brute(nums2);
    int len2 = solution.removeDuplicates(nums2);
    std::cout << "新长度: " << len2 << std::endl;
    std::cout << "修改后数组: ";
    for (int i = 0; i < len2; i++) std::cout << nums2[i] << " ";
    std::cout << std::endl;

    return 0;
}