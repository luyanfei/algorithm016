/*
 * @lc app=leetcode.cn id=50 lang=golang
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (36.67%)
 * Total Accepted:    128.5K
 * Total Submissions: 350.4K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */
func calc(x float64, n int) float64 {
    if n == 0 {
        return 1.0
    }
    mid := n / 2
    y := calc(x, mid)
    if n % 2 == 0 {
        return y * y
    } else {
        return y * y * x
    }
}

func myPow(x float64, n int) float64 {
    if n < 0 {
        return 1.0 / calc(x, -n)
    } else {
        return calc(x, n)
    }
}
