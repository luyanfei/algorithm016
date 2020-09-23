/*
 * @lc app=leetcode.cn id=49 lang=golang
 *
 * [49] Group Anagrams
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.37%)
 * Total Accepted:    105.5K
 * Total Submissions: 166.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
func groupAnagrams(strs []string) [][]string {
    result := make([][]string, 0, len(strs))
    table := make(map[string][]string)
    for i := 0; i < len(strs); i++ {
        var chars [26]byte;
        for j := 0; j < len(strs[i]); j++ {
            chars[strs[i][j] - 'a']++
        }
        key := string(chars[:])
        if _, ok := table[key]; ok {
            table[key] = append(table[key], strs[i])
        } else {
            table[key] = []string{strs[i]}
        }
    }
    for _, val := range table {
        result = append(result, val)
    }
    return result
}
