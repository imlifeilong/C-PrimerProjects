#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement_brute(std::vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j]; // 将后续元素前移
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小减1
            }
        }
        return size;
    }
    int removeElement(std::vector<int>& nums, int val) {
        int slow = 0; // 慢指针：新数组的末尾
        for (int fast = 0; fast < nums.size(); ++fast) { // 快指针遍历数组
            if (nums[fast] != val) { // 找到有效元素
                nums[slow] = nums[fast]; // 赋值给慢指针位置
                ++slow; // 慢指针前进
            }
        }
        return slow; // 慢指针的位置即为新长度
    }
};

int main() {
    Solution solution;

    // 示例1
    std::vector<int> nums1 = { 3, 2, 2, 3 };
    int val1 = 3;
    //int len1 = solution.removeElement_brute(nums1, val1);
    int len1 = solution.removeElement(nums1, val1);
    std::cout << "示例1: nums = [3,2,2,3], val = 3" << std::endl;
    std::cout << "返回长度: " << len1 << std::endl;
    std::cout << "修改后的数组: ";
    for (int i = 0; i < len1; i++) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // 示例2
    std::vector<int> nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val2 = 2;
    //int len2 = solution.removeElement_brute(nums2, val2);
    int len2 = solution.removeElement(nums2, val2);
    std::cout << "示例2: nums = [0,1,2,2,3,0,4,2], val = 2" << std::endl;
    std::cout << "返回长度: " << len2 << std::endl;
    std::cout << "修改后的数组: ";
    for (int i = 0; i < len2; i++) {
        std::cout << nums2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}