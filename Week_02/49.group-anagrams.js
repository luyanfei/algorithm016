/*
 * @lc app=leetcode.cn id=49 lang=javascript
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
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let table = new Map()
    for (let i = 0; i < strs.length; i++) {
        let arr = new Array(26)
        arr.fill(0)
        for (let j = 0; j < strs[i].length; j++) {
            let idx = strs[i].charCodeAt(j) - 'a'.charCodeAt(0)
            arr[idx]++
        }
        let key = arr.reduce((acc, val) => acc + val + '#', '')
        if (table.has(key)) {
            table.get(key).push(strs[i])
        } else {
            table.set(key, [strs[i]])
        }
    }
    return [...table.values()]
};
