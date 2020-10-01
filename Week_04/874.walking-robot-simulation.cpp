/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 比较含退格的字符串
 *
 * https://leetcode-cn.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (38.60%)
 * Total Accepted:    12K
 * Total Submissions: 30.9K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
 * 
 * 
 * -2：向左转 90 度
 * -1：向右转 90 度
 * 1 <= x <= 9：向前移动 x 个单位长度
 * 
 * 
 * 在网格上有一些格子被视为障碍物。
 * 
 * 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
 * 
 * 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
 * 
 * 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: commands = [4,-1,3], obstacles = []
 * 输出: 25
 * 解释: 机器人将会到达 (3, 4)
 * 
 * 
 * 示例 2：
 * 
 * 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * 输出: 65
 * 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * 答案保证小于 2 ^ 31
 * 
 * 
 */
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> oset;
        for (const auto& obstacle : obstacles) {
            oset.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        vector<pair<int, int>> deltas {
            make_pair(0, 1), make_pair(1, 0), 
            make_pair(0, -1), make_pair(-1, 0)
        };
        int distance = 0, idx = 0, x = 0, y = 0;
        for (const auto& command : commands) {
            if (command == -1) {
                idx = (idx + 1) % 4;
            } else if (command == -2) {
                idx = (idx + 3) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nx = x + deltas[idx].first;
                    int ny = y + deltas[idx].second;
                    string key = to_string(nx) + "," + to_string(ny);
                    if (oset.find(key) == oset.end()) {
                        x = nx;
                        y = ny;
                        distance = max(distance, x * x + y * y);
                    }
                }
            }
        }
        return distance;
    }
};
