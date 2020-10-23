-- 188. 买卖股票的最佳时机 IV
[题目链接](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

在第三次做这题时，我写出下面的代码，结果是错的。为什么会错？
```
    dp0, dp1 := make([]int, k + 1), make([]int, k + 1)
    for i := 0; i < k + 1; i++ {
        dp1[i] = - prices[0]
    }
    for i := 1; i < n; i++ {
        for j := 1; j < k + 1; j++ {
            dp0[j] = max(dp0[j], dp1[j - 1] + prices[i])
            dp1[j] = max(dp1[j], dp0[j - 1] - prices[i])
        }
    }
    return dp0[k]
```
正确的解法如下：
```
    vector<int> dp0(k + 1, 0);
    vector<int> dp1(k + 1, -prices[0]);
    for (int j = 1; j < n; j++) {
        for (int i = 1; i <= k; i++) {
            dp1[i-1] = max(dp1[i-1], dp0[i-1] - prices[j]);
            dp0[i] = max(dp0[i], dp1[i-1] + prices[j]);
        }
    }
    return dp0[k];
```
已完成j次交易且持有股票的状态，依赖于完成j次交易且不持有股票的状态。而不是依赖于完成j-1次交易且不持持胡股票的状态。每轮内循环要推导完成一次交易的状态。

-- 32.最长有效括号
[题目链接](https://leetcode-cn.com/problems/longest-valid-parentheses/)

推导状态转移方程分两部分，其中最近字符为"()"的情形比较容易理解。而另一种情形却令我困惑了好久。

s[i]=')'且s[i−1]=')'，也就是字符串形如 “))”时，如果s[i-dp[i-1]-1]='('时会有下面的状态转移方程：
```
dp[i] = dp[i - 1] + dp[i - dp[i - dp[i - 1] - 2] + 2
```
我的问题是，为什么不考虑s[i-dp[i-1]-1]=')'的情形？也就是在前一个有效子串之前，不也可以有另一个已经完成的有效括号子串？

事实上，这么考虑下去，发现就得一直往前推导到0为止。而题目运行的结果表明，上面的状态公式是正确的。

这个问题困惑了我好一会儿，后来终于想通，原来是逻辑的问题。

dp[i]的含义是以s[i]为结束的最长有效括号子串长度，其中“最长”两字的含义里就包括了s[i-dp[i-1]-1]=')'的情形，因此在程序中是不必判断这种情况的。

-- 123. 买卖股票的最佳时机 III
[题目链接](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
采用JavaScript来实现，先定义状态数组：
```
let dp0 = new Array(3), dp1 = new Array(3)
```
dp0表示手中没有股票的状态，下标为完成交易的次数(0, 1, 2)。

dp1表示手中有股票的状态，下标为完成交易的次数(0, 1, 2)。

接下来初始化状态：
```
dp0.fill(0)
dp1.fill(-prices[0])
```
没有股票时，初始化为0，有股票，则初始化为-prices[0]。仔细考虑，在现实中，dp1[2]的含义得理解为完成已经完成两次交易，而手中还有股票，这样的初始状态只能说前两次交易的获利0。

循环如下：
```
for (let i = 1; i < prices.length; i++) {
    dp0[1] = Math.max(dp0[1], dp1[0] + prices[i])
    dp1[1] = Math.max(dp1[1], dp0[1] - prices[i])
    dp0[2] = Math.max(dp0[2], dp1[1] + prices[i])
}
```
返回dp0[2]的值，结果通过了部分数据，但无法正确提交。具体的原因在比较了正确的处理方式后才搞清楚。

dp0[0]是在任何情况下都不需要去理会的，它就只能是0。但dp1[0]，即已经完成0次交易，而又手中有股票的状态，则是会随天数的变化而变化的。

dp0[1]（完成一次交易而手中没有股票的状态）需要由dp1[0]推导而出。由此得到正确的循环如下：
```
for (let i = 1; i < prices.length; i++) {
    dp1[0] = Math.max(dp1[0], dp0[0] - prices[i])
    dp0[1] = Math.max(dp0[1], dp1[0] + prices[i])
    dp1[1] = Math.max(dp1[1], dp0[1] - prices[i])
    dp0[2] = Math.max(dp0[2], dp1[1] + prices[i])
}
```

-- 518. 零钱兑换 II
[题目链接](https://leetcode-cn.com/problems/coin-change-2/)

正确和错误只有内外循环的次序。下面是我多次写出，而又是错误的方案：
```
def change(self, amount: int, coins: List[int]) -> int:
    dp = [0] * (amount + 1)
    dp[0] = 1
    for i in range(coin, amount + 1):
        for coin in coins:
            dp[i] += dp[i - coin]
    return dp[amount]
```
而正确的解决方案是：
```
def change(self, amount: int, coins: List[int]) -> int:
    dp = [0] * (amount + 1)
    dp[0] = 1
    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    return dp[amount]
```
看出区别了吗？

正确的解法是coins循环在外，amount循环在内。这样的做法才是算组合，错误的解法算出来的是排列。

