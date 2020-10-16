/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (42.95%)
 * Total Accepted:    76K
 * Total Submissions: 176.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>> dp(height, vector<int>(width, 0));
        int maxlen = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                dp[i][j] = matrix[i][j] - '0';
                if (i > 0 && j > 0 && matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        return maxlen * maxlen;
    }
};
