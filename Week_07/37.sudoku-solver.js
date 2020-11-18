/*
 * @lc app=leetcode.cn id=37 lang=javascript
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
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var bidx = function(i, j) {
    return Math.floor(i / 3) * 3 + Math.floor(j / 3)
}
var buildSet = function() {
    let set = new Set()
    for (let i = 1; i <= 9; i++) {
        set.add(i)
    }
    return set
}
var build = function() {
    let arr = new Array(9)
    for (let i = 0; i < 9; i++) {
        arr[i] = buildSet()
    }
    return arr
}
var solveSudoku = function(board) {
    let rows = build()
    let cols = build()
    let boxes = build()
    
    let blanks = []
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] === '.') {
                blanks.push({x:i, y:j})
            } else {
                let val = Number.parseInt(board[i][j])
                rows[i].delete(val)
                cols[j].delete(val)
                boxes[bidx(i,j)].delete(val)
            }
        }
    }

    let dfs = function(start) {
        if (start === blanks.length) {
            return true
        }
        let {x, y} = blanks[start]
        let bi = bidx(x, y)
        let nset = new Set()
        for (let v of rows[x]) {
            if (!cols[y].has(v) || !boxes[bi].has(v)) {
                continue
            }
            nset.add(v)
        }
        for (let v of nset) {
            board[x][y] = '' + v
            rows[x].delete(v)
            cols[y].delete(v)
            boxes[bi].delete(v)
            if (dfs(start + 1)) {
                return true
            }
            rows[x].add(v)
            cols[y].add(v)
            boxes[bi].add(v)
            board[x][y] = '.'
        }
        return false
    }
    dfs(0)
};
