#include <iostream>
#include <vector>
#include <algorithm> // 用于min和max函数

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int width = right - left;
            int current_height = min(height[left], height[right]);
            int current_area = width * current_height;
            max_area = max(max_area, current_area);

            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return max_area;
    }
    // 使用暴力枚举法计算盛最多水的容器
    int maxArea_brute(std::vector<int>& height) {
        int n = height.size();
        int max_area = 0;

        // 遍历所有可能的左端点
        for (int i = 0; i < n; ++i) {
            // 遍历所有可能的右端点
            for (int j = i + 1; j < n; ++j) {
                int width = j - i;
                int current_height = std::min(height[i], height[j]);
                int area = width * current_height;
                // 更新最大容量
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
};

// 测试代码
int main() {
    // 示例输入：[1,8,6,2,5,4,8,3,7]，预期输出49
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    Solution solution;
    int result = solution.maxArea(height);
    cout << "双指针最大容器面积为：" << result << endl; // 输出结果、
    int result1 = solution.maxArea_brute(height);
    cout << "暴力枚举最大容器面积为：" << result1 << endl; // 输出结果
    // 暂停控制台，方便查看输出（按任意键继续）
    system("pause");
    return 0;
}