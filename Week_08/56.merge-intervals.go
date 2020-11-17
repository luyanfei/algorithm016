/*
 * @lc app=leetcode.cn id=56 lang=golang
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.16%)
 * Total Accepted:    162.2K
 * Total Submissions: 374.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */
type intervalSlice [][]int
func (x intervalSlice) Len() int {
    return len(x)
}
func (x intervalSlice) Less(i, j int) bool {
    return x[i][0] < x[j][0]
}
func (x intervalSlice) Swap(i, j int) {
    x[i], x[j] = x[j], x[i]
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func merge(intervals [][]int) [][]int {
    if len(intervals) == 0 {
        return [][]int{}
    }
    sort.Sort(intervalSlice(intervals))
    result := [][]int{intervals[0]}
    for i := 1; i < len(intervals); i++ {
        cur := intervals[i]
        tail := result[len(result) - 1]
        if cur[0] <= tail[1] {
            tail[1] = max(cur[1], tail[1])
        } else {
            result = append(result, cur)
        }
    }
    return result

}
