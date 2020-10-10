/*
 * @lc app=leetcode.cn id=47 lang=java
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (61.93%)
 * Total Accepted:    111.4K
 * Total Submissions: 179.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private boolean[] visited;
    private List<Integer> item = new ArrayList<>();

    private void permute(int[] nums, int first) {
        if (first == nums.length) {
            result.add(new ArrayList<Integer>(item));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && visited[i-1])) {
                continue;
            }
            visited[i] = true;
            item.add(nums[i]);
            permute(nums, first + 1);
            item.remove(item.size() - 1);
            visited[i] = false;
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        visited = new boolean[nums.length];
        Arrays.fill(visited, false);
        permute(nums, 0);
        return result;
    }
}
