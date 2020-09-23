## 递归中空间分配的问题
递归中使用全局变量和传递参数是个难点。
leetcode 22.括号生成问题。我开始写出的代码是下面这样的：
```
class Solution:
    def generate(self, n, s, left, right, result):
        if (left == n and right == n):
            result.append(s)
            return
        if (left < n):
            s += '('
            self.generate(n, s, left + 1, right, result)
        if (right < left):
            s += ')'
            self.generate(n, s, left, right + 1, result)

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        s = ""
        self.generate(n, s, 0, 0, result)
        return result
```
输入数据为3，程序的输出如下：
```
Actual
  ✔ runtime: 44 ms
  ✘ answer: ["((()))","((()())","((()()()","(()(())","(()(()()"]
  ✔ stdout: ''

Expected
  ✔ runtime: 0 ms
  ✔ answer: ["((()))","(()())","(())()","()(())","()()()"]
```
所谓“不要人肉递归”，就是避免一层层想下去，或是试图去画出来，然而，不这么想下去，递归的程序又该怎么调试呢？
仔细分析自己的代码，无法理解，为什么输出的结果中会出现5个左括号，明明保证了"left < n"，在n为3的情况下，不应该出现左括号加到5的情况。
