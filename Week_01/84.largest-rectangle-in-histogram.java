/*
 * @lc app=leetcode.cn id=84 lang=java
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (41.65%)
 * Total Accepted:    86.8K
 * Total Submissions: 208.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int n = heights.length;
        int[] lefts = new int[n];
        int[] rights = new int[n];
        Arrays.fill(lefts, 0);
        Arrays.fill(rights, n);

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && heights[i] < heights[stack.peek()]) {
                int top = stack.pop();
                rights[top] = i;
            }
            lefts[i] = stack.empty() ? -1 : stack.peek();
            stack.push(i);
        }
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (rights[i] - lefts[i] - 1);
            if (area > maxarea) {
                maxarea = area;
            }
        }
        return maxarea;
    }
}
