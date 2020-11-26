/*
 * @lc app=leetcode.cn id=46 lang=java
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.95%)
 * Total Accepted:    198.8K
 * Total Submissions: 258.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> item = new ArrayList<>();
    public void doPermute(int[] nums, int start) {
        if (start == nums.length) {
            result.add(new ArrayList<>(item));
            return;
        }
        for (int i = start; i < nums.length; i++) {
            int t = nums[i];
            nums[i] = nums[start];
            nums[start] = t;
            item.add(nums[start]);
            doPermute(nums, start + 1);
            item.remove(item.size() - 1);
            t = nums[i];
            nums[i] = nums[start];
            nums[start] = t;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        doPermute(nums, 0);
        return result;
    }
}
