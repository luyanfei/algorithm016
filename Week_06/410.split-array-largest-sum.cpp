/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode-cn.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (53.00%)
 * Total Accepted:    25.2K
 * Total Submissions: 47.4K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
 * 
 * 注意:
 * 数组长度 n 满足以下条件:
 * 
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * 
 * 
 * 示例: 
 * 
 * 
 * 输入:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * 输出:
 * 18
 * 
 * 解释:
 * 一共有四种方法将nums分割为2个子数组。
 * 其中最好的方式是将其分为[7,2,5] 和 [10,8]，
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 * 
 * 
 */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, numeric_limits<int>::max()));
        dp[0][0] = 0;
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int submin = numeric_limits<int>::max();
                for (int k = 0; k < i; k++) {
                    int submax = max(dp[k][j - 1], (sub[i] - sub[k]));
                    submin = min(submin, submax);
                }
                dp[i][j] = submin;
            }
        }
        return dp[n][m];
    }
};
