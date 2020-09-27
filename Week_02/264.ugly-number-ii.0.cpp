/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (53.97%)
 * Total Accepted:    35.2K
 * Total Submissions: 65.2K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> p;
        set<long long> cset;
        const int nums[]{2, 3, 5};
        p.push(1);
        cset.insert(1);
        int k = n - 1;
        while (k--) {
            long long top = p.top();
            for (int x : nums) {
                long long t = top * x;
                if (cset.find(t) == cset.end()) {
                    p.push(t);
                    cset.insert(t);
                }
            }
            p.pop();
        }
        return p.top();
    }
};
