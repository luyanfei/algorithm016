## JavaScript中的排序函数
不经意间用到JavaScript的排序函数，没想到是进了一个坑。原来JavaScript的排序是默认以字符串的形式来排的，要想把数组按数值的大小来排序，得提供自定义比较函数。比较简单的写法如下：
```
nums.sort((a, b) => a - b)
```
## 二叉树最近公共祖先
leetcode 236，二叉树最近公共祖先，最简洁的写法是这样的：
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
```
最后一行的返回值的逻辑比较复杂，读起来比较吃力。更糟糕的是，在这一行中藏了解决问题所需的一个非常重要的逻辑，初次写时一直没有注意，以后在回顾时，多次出错。

我把逻辑写成下面形式：
```
if (left == null) {
    if (right == null) {
        return root;
    } else {
        return right;
    }
} else {
    if (right == null) {
        return left;
    } else {
        return root;
    }
}
```
这种写法与第一种方法中的return语句，在逻辑上有着细微的差别，正是这点差别，决定了递归的正确与否。

若left与right均为null，不应返回root，而是应当返回null。非null的返回值，意味着访问到了p或者q。一旦写成下面的“对称的”的条件判断形式，那些不包含p或q的子树都会返回非null的结果，于是就无从判断最近公共祖先是哪一个了。

## 广度优先搜索用数组而非队列
广度优先搜索中使用队列是标准的做法，但在做题时，这种方法并不是最方便的。尤其是要处理层的序数时。这时免不了会将层数封装到某个新的数据类型，然后再放入队列，这么做其实挺繁琐的。

用数组来实现的广度优先，一次处理一层，处理完后生成新的层，只需用个简单的层数变量即可计下层数，实在是很适合做题。

用数组来做广度优先，对语言适应性也是最佳的。C++和Java提供了完整的Queue的支持，Python和Go则需要从列表或切片来模拟，至于JavaScript，虽说数组能当队列来用，但shift函数的代价其实是挺高的，并不合适。

广度优先，首选应是数组。

## 用二分查找来确定半有序数组中无序的地方
这个问题应该就是leetcode 153相同的问题，leetcode 153要求找出发生了旋转的点，也即是次序被打断的地方。我没有什么思路，基本是这题的题解的内容。关键点即是：
1. 所有变化点左侧元素 > 数组第一个元素
2. 所有变化点右侧元素 < 数组第一个元素
每次定位到无序的段，然后检查中间点与中间点左右之间的大小关系，从而确定该点的位置。

