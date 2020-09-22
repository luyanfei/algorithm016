/*
 * @lc app=leetcode.cn id=11 lang=javascript
 *
 * [11] Container With Most Water
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (64.12%)
 * Total Accepted:    281.5K
 * Total Submissions: 438.8K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 
 */
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var result = 0
    for (let i = 0, j = height.length - 1; i < j;) {
        let minheight = height[i] < height[j] ? height[i] : height[j]
        let area = minheight * (j - i)
        if (area > result) {
            result = area
        }
        if (height[i] < height[j]) {
            i++
        } else {
            j--
        }
    }
    return result
};

//height = [1,8,6,2,5,4,8,3,7];
//console.log(maxArea(height))