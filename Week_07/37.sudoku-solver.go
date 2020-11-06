/*
 * @lc app=leetcode.cn id=37 lang=golang
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (66.66%)
 * Total Accepted:    59.9K
 * Total Submissions: 89.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * 提示：
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */
type Node struct {
    x int
    y int
}
func buildSet() map[int]bool {
    set := make(map[int]bool)
    for i := 1; i <= 9; i++ {
        set[i] = true
    }
    return set
}
func buildSlice() []map[int]bool {
    arr := make([]map[int]bool, 0, 9)
    for i := 0; i < 9; i++ {
        arr = append(arr, buildSet())
    }
    return arr
}
func solveSudoku(board [][]byte)  {
    rows := buildSlice()
    cols := buildSlice()
    boxes := buildSlice()
    blanks := make([]Node, 0, 81)
    for i := 0; i < 9; i++ {
        for j := 0; j < 9; j++ {
            if board[i][j] == '.' {
                blanks = append(blanks, Node{x: i, y: j})
            } else {
                val := int(board[i][j] - '0')
                delete(rows[i], val)
                delete(cols[j], val)
                delete(boxes[(i / 3) * 3 + j / 3], val)
            }
        }
    }

    var dfs func(start int) bool
    dfs = func(start int) bool {
        if start == len(blanks) {
            return true
        }
        node := blanks[start]
        bidx := (node.x / 3) * 3 + node.y / 3
        rset, cset, bset := rows[node.x], cols[node.y], boxes[bidx]
        innerset := make(map[int]bool)
        for val, _ := range rset {
            if _, ok := cset[val]; !ok {
                continue
            }
            if _, ok := bset[val]; !ok {
                continue
            }
            innerset[val] = true
        }
        for val, _ := range innerset {
            board[node.x][node.y] = byte(val) + '0'
            delete(rset, val)
            delete(cset, val)
            delete(bset, val)
            if dfs(start + 1) {
                return true
            }
            rset[val] = true
            cset[val] = true
            bset[val] = true
            board[node.x][node.y] = '.'
        }
        return false
    }
    dfs(0)
}
