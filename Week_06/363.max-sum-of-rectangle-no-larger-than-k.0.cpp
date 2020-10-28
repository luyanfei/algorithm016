/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (39.33%)
 * Total Accepted:    5.8K
 * Total Submissions: 14.5K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。
 * 
 * 示例:
 * 
 * 输入: matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出: 2 
 * 解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 * 
 * 
 * 说明：
 * 
 * 
 * 矩阵内的矩形区域面积必须大于 0。
 * 如果行数远大于列数，你将如何解答呢？
 * 
 * 
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int height = matrix.size(), width = matrix[0].size();
        int result = INT_MIN;
        for (int i = 0; i < width; i++) {
            vector<int> subs(height, 0);
            for (int j = i; j < width; j++) {
                for (int r = 0; r < height; r++) {
                    subs[r] += matrix[r][j];
                }
                set<int> sumset;
                sumset.insert(0);
                int maxsum = INT_MIN, accsum = 0;
                for (int sub : subs) {
                    accsum += sub;
                    auto it = sumset.lower_bound(accsum - k);
                    if (it != sumset.end()) {
                        maxsum = max(maxsum, accsum - *it);
                    }
                    sumset.insert(accsum);
                }
                result = max(result, maxsum);
            }
        }
        return result;
    }
};
