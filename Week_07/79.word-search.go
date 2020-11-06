/*
 * @lc app=leetcode.cn id=79 lang=golang
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.63%)
 * Total Accepted:    116.5K
 * Total Submissions: 266.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
func exist(board [][]byte, word string) bool {
    if len(board) == 0 {
        return false
    }
    height, width := len(board), len(board[0])
    var dfs func(row, col, start int)
    hasFound := false
    dfs = func(row, col, start int) {
        if start == len(word) {
            hasFound = true
            return
        }
        if hasFound || row < 0 || row >= height || col < 0 || col >= width || board[row][col] == '.' || board[row][col] != word[start] {
            return
        }
        old := board[row][col]
        board[row][col] = '.'
        dfs(row + 1, col, start + 1)
        dfs(row - 1, col, start + 1)
        dfs(row, col + 1, start + 1)
        dfs(row, col - 1, start + 1)
        board[row][col] = old
    }
    for i := 0; i < height; i++ {
        for j := 0; j < width; j++ {
            dfs(i, j, 0)
            if hasFound {
                return hasFound
            }
        }
    }
    return false
}
