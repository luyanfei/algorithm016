/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.50%)
 * Total Accepted:    180.1K
 * Total Submissions: 324.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
//package main
//import "fmt"
func letterCombinations(digits string) []string {
    result := []string{}
    if len(digits) == 0 {
        return result
    }
    table := map[byte]string {'2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"}
    item := []byte{}
    var backtrack func(first int)
    backtrack = func(first int) {
        if first == len(digits) {
            result = append(result, string(item))
            return
        }
        if chars, ok := table[digits[first]]; ok {
            for i := 0; i < len(chars); i++ {
                item = append(item, chars[i])
                backtrack(first + 1)
                item = item[:len(item) - 1]
            }
        }
    }
    backtrack(0)
    return result
}
//
//func main() {
    //letterCombinations("23")
//}
