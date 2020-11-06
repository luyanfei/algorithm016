/*
 * @lc app=leetcode.cn id=309 lang=javascript
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (57.19%)
 * Total Accepted:    59.9K
 * Total Submissions: 104.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (prices.length === 0) return 0
    let s0 = 0, s1 = 0, s2 = -prices[0]
    for (let i = 1; i < prices.length; i++) {
        let t0 = Math.max(s0, s1)
        let t1 = s2 + prices[i]
        let t2 = Math.max(s0 - prices[i], s2)
        s0 = t0, s1 = t1, s2 = t2
    }
    return Math.max(s0, s1)
};
