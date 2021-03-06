/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] Valid Parentheses
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (42.97%)
 * Total Accepted:    403.1K
 * Total Submissions: 938K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
func isValid(s string) bool {
    stack := []byte{}
    for i := 0; i < len(s); i++ {
        switch s[i] {
        case '(':
            stack = append(stack, ')')
        case '[':
            stack = append(stack, ']')
        case '{':
            stack = append(stack, '}')
        default:
            if len(stack) == 0 || s[i] != stack[len(stack) - 1] {
                return false
            }
            stack = stack[0:len(stack) - 1]
        }
    }
    return len(stack) == 0
}
