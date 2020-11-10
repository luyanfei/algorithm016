/*
 * @lc app=leetcode.cn id=77 lang=java
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (75.72%)
 * Total Accepted:    105.9K
 * Total Submissions: 139.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> item = new ArrayList<>();

    private void build(int start, int n, int k) {
        if (item.size() == k) {
            result.add(new ArrayList<>(item));
            return;
        }
        if (start > n) return;
        item.add(start);
        build(start + 1, n, k);
        item.remove(item.size() - 1);
        build(start + 1, n, k);
    }
    public List<List<Integer>> combine(int n, int k) {
        build(1, n, k);
        return result;
    }
}
