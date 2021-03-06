/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.02%)
 * Total Accepted:    74.4K
 * Total Submissions: 151.8K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> pq;
        for (int i = 0; i < nums.size(); ++i) {
            int start = i - k;
            if (start >= 0) {
                pq.erase(pq.find(nums[start]));
            }
            pq.insert(nums[i]);
            if (pq.size() == k) {
                result.push_back(*pq.rbegin());
            }
        }
        return result;
    }
};

 //int main() {
     //Solution s;
     //vector<int> nums {1,2,1,2,0,5};
     //s.maxSlidingWindow(nums, 3);
     //return 0;
 //}
