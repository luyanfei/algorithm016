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
    解题的过程很顺利，根本没有多往心里去。但过两天后，再用Python来实现同样的思路，提交果却被一组数据卡住。该数据如下：
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

