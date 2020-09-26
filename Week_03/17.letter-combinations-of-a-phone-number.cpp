/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.50%)
 * Total Accepted:    180.1K
 * Total Submissions: 324.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
//#include <iostream>
//#include <unordered_map>
//#include <functional>
//#include <string>
//#include <vector>
//using namespace std;
//
class Solution {
    unordered_map<char, string> um;
public:
    Solution() {
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }
        string item = "";
        function<void(int)> search = [&] (int first) {
            if (first == digits.length()) {
                result.push_back(item);
                return;
            }
            for (int i = 0; i < um[digits[first]].length(); ++i) {
                item.push_back(um[digits[first]][i]);
                search(first + 1);
                item.pop_back();
            }
        };
        search(0);
        return result;
    }
};

//int main(int argc, char *argv[])
//{
    //Solution s;
    //s.letterCombinations("23");
    //return 0;
//}
