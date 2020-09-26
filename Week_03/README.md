## 递归中空间分配的问题
递归中使用全局变量和传递参数是个难点。这里除了考虑需要用到哪些变量以外，还需要特别留意是使用一份数据，还是使用多份数据。

leetcode 22.括号生成问题。我在第二遍时写出的代码是下面这样的：
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
仔细分析自己的代码，无法理解，为什么输出的结果中会出现5个左括号。明明保证了"left < n"，在n为3的情况下，不应该出现左括号加到5的情况。

所谓“不要人肉递归”，就是避免一层层想下去，或是试图去画出来，然而，不这么想下去，递归的程序中若是出现算法设计层面的错误，又该如何解决呢？这是一个难以解决的问题。

加到括号生成的问题。经过正确的代码的比较，原因还是容易找到的。正确的代码如下：
```
class Solution:
    def generate(self, n, s, left, right, result):
        if (left == n and right == n):
            result.append(s)
            return
        if (left < n):
            s1 = s + '('
            self.generate(n, s1, left + 1, right, result)
        if (right < left):
            s2 = s + ')'
            self.generate(n, s2, left, right + 1, result)

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.generate(n, "", 0, 0, result)
        return result
```
两者的差别就在于，正确的解决方案中每次递归的调用的字符串对象都是独立的，而在错误的解决方案中，全局共用了同一个字符串对象，这也就解决了为何长度的控制会失效，因为长度控制是以拼接的次数来定的。

这就要回到视频教程中提到的是否要恢复状态的问题。在错误方案中，如果能够在每次递归调用回来后把尾部多加上的括号再去掉，那么也可以得到正确的答案。

关于是否需要恢复状态，我的理解是按下面的规则来处理：
```
若是递归全局中修改同一个对象，那么，每次递归后需要恢复状态。若是每次进行复制，每次面对的都是不同的对象，那就无需去恢复状态。
```
从空间效率来说，使用同一个对象，会更高效一些。

## Python中生成器的妙用

leetcode 297. 二叉树的序列化与反序列化。C++实现的代码如下（主要参考国际站）：
```
class Codec {
    void doserialize(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "#" << " ";
        } else {
            out << root->val << " ";
            doserialize(root->left, out);
            doserialize(root->right, out);
        }
    }
    TreeNode* dodeserialize(istringstream& in) {
        string input;
        in >> input;
        if (input == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(input));
        node->left = dodeserialize(in);
        node->right = dodeserialize(in);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        doserialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return dodeserialize(in);
    }
};
```
反序列化的实现其实是利用了istringsteam在读取数据时的特点，可以将其想象成数据流，每次从头部取一个数据，直到流的结束。

用C++时，我其实并未特别注意到这一点，毕竟也输入输出也用了很久，一直如此。直到我第二遍用Python来实现，突然发现没法用list做出这样的效果。把list对象传入 函数，要把头部切掉，只能做下面的赋值：
```
lst = lst[1:]
```
由于传入函数的会是引用的副本，上面的赋值对外部的list没有任何影响。要想解决这个问题，我能想到的就是在list之外做一层封装，那又很烦琐，不想这么去写。

没有办法了，只能再去看高人的解答，最后在同一作者的帖子下，看到了Python的解决方案。一看之下，又被亮瞎了眼睛。反序列化的代码如下：
```
    def deserialize(self, data):
        def doit():
            val = next(vals)
            if val == '#':
                return None
            node = TreeNode(int(val))
            node.left = doit()
            node.right = doit()
            return node
        vals = iter(data.split())
        return doit()
```
这里的奥妙在于生成器的使用。

生成器，我并不陌生，甚至还挺熟悉的。Javascript中的生成器是解决异步编程的基石。用作迭代数据的生成，那也很自然。但把它用到普通的list，变出istirngstream的效果，那真是做梦也不曾想到过。
