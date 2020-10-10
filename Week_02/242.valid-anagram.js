/*
 * @lc app=leetcode.cn id=242 lang=javascript
 *
 * [242] Valid Anagram
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (61.31%)
 * Total Accepted:    136.6K
 * Total Submissions: 222.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    let arr = new Array(26)
    arr.fill(0)
    for (let i = 0; i < s.length; i++) {
        let cp = s.codePointAt(i) - 97
        arr[cp]++
    }
    for (let i = 0; i < t.length; i++) {
        let cp = t.codePointAt(i) - 97
        arr[cp]--
    }
    return arr.every(v => v == 0)
};
