/*
 * @lc app=leetcode.cn id=42 lang=java
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.55%)
 * Total Accepted:    146.4K
 * Total Submissions: 278.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
class Solution {
    public int trap(int[] height) {
        Stack<Integer> s = new Stack<>();
        int total = 0;
        for (int i = 0; i < height.length; i++) {
            while (!s.empty() && height[i] > height[s.peek()]) {
                int top = s.pop();
                if (!s.empty()) {
                    int minheight = Math.min(height[i], height[s.peek()]);
                    total += (minheight - height[top]) * (i - s.peek() - 1);
                }
            }
            s.push(i);
        }
        return total;
    }
}
