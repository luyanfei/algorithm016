/*
 * @lc app=leetcode.cn id=980 lang=java
 *
 * [980] 最短超级串
 *
 * https://leetcode-cn.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (71.55%)
 * Total Accepted:    8.4K
 * Total Submissions: 11.7K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * 在二维网格 grid 上，有 4 种类型的方格：
 * 
 * 
 * 1 表示起始方格。且只有一个起始方格。
 * 2 表示结束方格，且只有一个结束方格。
 * 0 表示我们可以走过的空方格。
 * -1 表示我们无法跨越的障碍。
 * 
 * 
 * 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
 * 
 * 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * 输出：2
 * 解释：我们有以下两条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 示例 2：
 * 
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * 输出：4
 * 解释：我们有以下四条路径： 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 示例 3：
 * 
 * 输入：[[0,1],[2,0]]
 * 输出：0
 * 解释：
 * 没有一条路能完全穿过每一个空的方格一次。
 * 请注意，起始和结束方格可以位于网格中的任意位置。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length * grid[0].length <= 20
 * 
 * 
 */
class Point {
    int x;
    int y;
    public Point() {}
    public Point(int x, int y) {this.x = x; this.y = y;}
}
class Solution {
    Point start = new Point();
    Point end = new Point();
    int count = 0;
    int result = 0;
    int visited = 0;
    int height = 0;
    int width = 0;

    private void dfs(Point p, int[][] grid) {
        if (p.x < 0 || p.x >= height || p.y < 0 || p.y >= width || grid[p.x][p.y] == -1) {
            return;
        }
        if (p.x == end.x && p.y == end.y) {
            if (visited == count + 1)
                result++;
            return;
        }
        visited++;
        int old = grid[p.x][p.y];
        grid[p.x][p.y] = -1;
        dfs(new Point(p.x + 1, p.y), grid);
        dfs(new Point(p.x - 1, p.y), grid);
        dfs(new Point(p.x, p.y + 1), grid);
        dfs(new Point(p.x, p.y - 1), grid);
        grid[p.x][p.y] = old;
        visited--;
    }
    public int uniquePathsIII(int[][] grid) {
        height = grid.length;
        if (height == 0) return 0;
        width = grid[0].length;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    start.x = i; start.y = j;
                } else if (grid[i][j] == 2) {
                    end.x = i; end.y = j;
                } else if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        dfs(start, grid);
        return result;
    }
}
