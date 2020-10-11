/*
 * @lc app=leetcode.cn id=264 lang=java
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (53.97%)
 * Total Accepted:    35.2K
 * Total Submissions: 65.2K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */
class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        Set<Long> set = new HashSet<>();
        pq.offer(1L);
        set.add(1L);
        int count = 0;
        long result = 0;
        int[] muls = new int[]{2, 3, 5};
        while (true) {
            long top = pq.peek();
            for (int t : muls) {
                long a = t * top;
                if (!set.contains(a)) {
                    set.add(a);
                    pq.offer(a);
                }
            }
            result = pq.poll();
            count++;
            if (count == n) {
                break;
            }
        }
        return (int)result;
    }
}
