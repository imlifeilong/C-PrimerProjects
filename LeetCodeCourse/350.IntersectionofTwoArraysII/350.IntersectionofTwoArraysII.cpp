// 引入输入输出流库，用于控制台打印输出
#include <iostream>
// 引入向量容器库，用于存储动态数组（本题的输入输出数据结构）
#include <vector>
// 引入算法库，用于数组排序操作（双指针解法依赖排序）
#include <algorithm>
// 使用std命名空间，避免重复书写std::前缀
using namespace std;

// 解决方案类：用于实现两个数组交集 II 的两种解法（暴力解法 + 双指针解法）
class Solution {
public:
    /**
     * 暴力解法：遍历nums1每个元素，在nums2中查找未被使用的相同元素
     * @param nums1 第一个输入数组
     * @param nums2 第二个输入数组
     * @return 两个数组的交集（保留重复元素，顺序与nums1中匹配顺序一致）
     */
    vector<int> intersect_brute(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result; // 存储最终交集结果
        // 标记nums2中对应索引的元素是否已被使用（避免重复匹配），初始值全为false
        vector<bool> used(nums2.size(), false);

        // 外层循环：遍历nums1中的每一个元素
        for (int num1 : nums1) {
            // 内层循环：遍历nums2，查找与num1相等且未被使用的元素
            for (int i = 0; i < nums2.size(); i++) {
                // 找到匹配元素：未被使用且值相等
                if (!used[i] && nums2[i] == num1) {
                    result.push_back(num1); // 将匹配元素加入结果集
                    used[i] = true; // 标记该元素已被使用，防止重复匹配
                    break; // 找到当前num1的匹配项后，退出内层循环，继续处理nums1下一个元素
                }
            }
        }

        return result; // 返回交集结果
    }

    /**
     * 双指针解法：先排序再双指针遍历，高效匹配相同元素（官方推荐解法）
     * @param nums1 第一个输入数组
     * @param nums2 第二个输入数组
     * @return 两个数组的交集（保留重复元素，顺序为排序后的顺序）
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 第一步：对两个数组进行升序排序，为双指针匹配做准备
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result; // 存储最终交集结果
        int i = 0, j = 0; // 双指针初始化：i指向nums1起始位置，j指向nums2起始位置

        // 循环条件：两个指针均未超出对应数组的长度（任一指针越界则停止遍历）
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // 情况1：两个指针指向的元素相等，加入结果集
                result.push_back(nums1[i]);
                i++; // 移动nums1指针，继续查找下一个元素
                j++; // 移动nums2指针，继续查找下一个元素
            }
            else if (nums1[i] < nums2[j]) {
                // 情况2：nums1指针元素更小，移动nums1指针寻找更大的元素，尝试匹配nums2[j]
                i++;
            }
            else {
                // 情况3：nums2指针元素更小，移动nums2指针寻找更大的元素，尝试匹配nums1[i]
                j++;
            }
        }

        return result; // 返回交集结果
    }
};

// 主函数：程序入口，用于测试两种解法的功能
int main() {
    // 测试1：暴力解法
    Solution sol1; // 创建Solution类实例
    vector<int> nums1 = { 1, 2, 2, 1 }; // 测试用例1的第一个数组
    vector<int> nums2 = { 2, 2 }; // 测试用例1的第二个数组
    // 注意：原代码此处调用错误，修正为调用暴力解法方法intersect_brute
    vector<int> result1 = sol1.intersect_brute(nums1, nums2);

    // 打印暴力解法结果
    cout << "暴力解法结果: ";
    for (int num : result1) { // 遍历结果集，逐个打印元素
        cout << num << " ";
    }
    cout << endl; // 换行，优化输出格式

    // 测试2：双指针解法
    Solution sol2; // 创建Solution类实例（也可复用sol1，此处为清晰分开测试创建新实例）
    vector<int> nums3 = { 4, 9, 5 }; // 测试用例2的第一个数组
    vector<int> nums4 = { 9, 4, 9, 8, 4 }; // 测试用例2的第二个数组
    vector<int> result2 = sol2.intersect(nums3, nums4); // 调用双指针解法方法

    // 打印双指针解法结果
    cout << "双指针解法结果: ";
    for (int num : result2) { // 遍历结果集，逐个打印元素
        cout << num << " ";
    }
    cout << endl; // 换行，优化输出格式

    return 0; // 程序正常结束
}