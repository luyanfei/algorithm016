## 本周总结
### 字母异位词分组
解题的主要想法是根据单词中字母的统计结果来生成key，放入HashMap。STL中对应的容器是unordered_map，代码实现如下：
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            array<char, 26> chars;
            fill(chars.begin(), chars.end(), 0);
            for (auto c : s) {
                chars[c - 'a']++;
            }
            string key;
            for (auto c : chars) {
                key += c;
            }
            m[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto p : m) {
            result.push_back(p.second);
        }
        return result;
    }
};
```
解题的过程很顺利，根本没有多往心里去。但过两天后，再用Python来实现同样的思路，提交时却被一组数据卡住。该数据如下：
```
[["bbbbbbbbbbc"],["bdddddddddd"]]
```
看到这组数据，我并不能看出问题出在什么地方，最后只能本地打印出key。经过一番折腾，才算搞清楚问题所在。
    
这组数据的前一单词中b出现10次，c出现1次。后一单词b出现1次d出现10次。按照原来的思路，两个单词拼接出来的字符串都会是：
```
010100000000000000000000000
```
真相算是看到了。完全无法预见这样的情形。不过令人纳闷的是C++语言中为什么依旧能够正确的通过这组数据？

把C++代码的key打印出来，终端上是看不到内容的。最后仔细一想，终于明白，还是数据类型的问题。C++中的char类型拼接到字符串上，是按字符来处理，于是数字"10"会是某个无法打印的字符，面对上面这组特殊数据时，C++中拼接出来的key还会是有区别的。相反Python中来拼接字符串，会把数字转换成十进制的字符，在面对这种特殊数据时就把两个不同的单词拼出相同的key来，后面的计算当然就出错了。Python的解决方案是以tuple作为key。

### 优先队列实现滑动窗口最大值问题
用优先队列实现滑动窗口最大值问题，覃超老师的视频中使用的Java语言，Java的PriorityQueue很特别，有API直接移除非顶部元素，滑动窗口问题用PriorityQueue来解决，其实是利用了这一点。换用C++来实现时，就会碰到大坑。首先STL中的priority_queue不支持对非顶部元素的操作，因此，可以考虑用multiset，而multiset的erase方法是重载过的，如果像Java一样来用，会把所有相同值的元素全部删除，必须先使用find，然后再erase。

## HashMap笔记
HashMap的代码实在繁杂，只能读个大概出来。

### initialCapacity和loadFactor
initialCapacity为初始Node数组的大小，默认为16，也可在构建时指定。loadFactor默认为0.75，若容量为128，则条目的数量达到96时，HashMap对象就会启动resize过程，扩充容量。

### Node bin与TreeNode bin
bin的原义是箱，用在这里表示hashcode相同的元素会被塞到同一个箱子里的情形。当箱子里的元素达到8个(TREEIFY_THRESHOLD)时，会将Node转换成TreeNode。TreeNode的容量差不多是Node的两倍，转换成TreeNode的目的就是为了应对极端的情形（如碰撞较多），一般情况下，使用者不用太操心这种情形。

### 数据存储的原理
真正用于存储数据的其实是一个Node数组：
```
transient Node<K,V>[] table;
```
往HashMap中添加元素时，作为key的hashcode与数组下标的对应关系是下面的式子：
```
(n - 1) & hash
```
其中n即为数组的长度，hash为key的hashcode。n只能取2的倍数，以2^8=256为例，n-1的值会是255，二进制角度下会是8个1（低位），与hashcode作位与运算，相当于取出低8位。也就是说hashcode的低16位取出来的整数即是该key所对应的数组中的下标位置，也是放数组的地方。

这种映射会带来rehash的高成本。当容量再扩大一倍，从hashcode中取出的数字多了一位，每个Node的位置都可能发生变化，这意味着扩容就意味着大家都得挪位置，resize的实现也比较复杂。

