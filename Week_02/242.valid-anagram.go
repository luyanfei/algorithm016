/*
 * @lc app=leetcode.cn id=242 lang=golang
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
func isAnagram(s string, t string) bool {
    m := make(map[byte]int)
    for i := 0; i < len(s); i++ {
        if val, ok := m[s[i]]; ok {
            m[s[i]] = val + 1
        } else {
            m[s[i]] = 1
        }
    }
    for i := 0; i < len(t); i++ {
        if val, ok := m[t[i]]; ok {
            m[t[i]] = val - 1
        } else {
            return false
        }
    }
    for _, count := range m {
        if count != 0 {
            return false
        }
    }
    return true
}
