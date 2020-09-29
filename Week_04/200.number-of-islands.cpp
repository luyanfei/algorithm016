/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (50.35%)
 * Total Accepted:    163.3K
 * Total Submissions: 324.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ['1','1','1','1','0'],
 * ['1','1','0','1','0'],
 * ['1','1','0','0','0'],
 * ['0','0','0','0','0']
 * ]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ['1','1','0','0','0'],
 * ['1','1','0','0','0'],
 * ['0','0','1','0','0'],
 * ['0','0','0','1','1']
 * ]
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        pair<int, int> neighbors[] {
            make_pair(-1, 0), make_pair(1, 0),
            make_pair(0, 1), make_pair(0, -1)
        };
        int count = 0;
        if (grid.size() == 0) {
            return count;
        }
        int width = grid[0].size();
        int height = grid.size();
        function<void(int,int)> bfs = [&] (int row, int col) {
            if (grid[row][col] != '1') {
                return;
            }
            vector<pair<int, int>> q{make_pair(row, col)};
            while (!q.empty()) {
                vector<pair<int, int>> newq;
                for (auto& p : q) {
                    if (grid[p.first][p.second] != '1') {
                        continue;
                    }
                    for (auto& nei : neighbors) {
                        pair<int, int> newp(p.first + nei.first, p.second + nei.second);
                        if (newp.first >= 0 && newp.first < height && newp.second >= 0 && newp.second < width) {
                            newq.emplace_back(newp);
                        }
                    }
                    grid[p.first][p.second] = '0';
                }
                q = newq;
            }
        };

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(i, j);
                }
            }
        }
        return count;
    }
};
