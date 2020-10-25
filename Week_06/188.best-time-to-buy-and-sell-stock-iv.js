/*
 * @lc app=leetcode.cn id=188 lang=javascript
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (30.51%)
 * Total Accepted:    33.5K
 * Total Submissions: 109.7K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [2,4,1], k = 2
 * 输出: 2
 * 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,6,5,0,3], k = 2
 * 输出: 7
 * 解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4
 * 。
 * 随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 * 
 * 
 */
/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    let n = prices.length
    if (k >= n / 2) {
        let total = 0
        for (let i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                total += prices[i] - prices[i - 1]
            }
        }
        return total
    }
    let dp0 = new Array(k + 1), dp1 = new Array(k + 1)
    dp0.fill(0)
    dp1.fill(-prices[0])
    for (let i = 1; i < n; i++) {
        for (let j = 1; j <= k; j++) {
            dp1[j - 1] = Math.max(dp1[j - 1], dp0[j - 1] - prices[i])
            dp0[j] = Math.max(dp0[j], dp1[j - 1] + prices[i])
        }
    }
    return dp0[k]
};
