/*
 * @lc app=leetcode.cn id=49 lang=java
 *
 * [49] Group Anagrams
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.37%)
 * Total Accepted:    105.5K
 * Total Submissions: 166.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> table = new HashMap<>();
        int[] chars = new int[26];
        for (String s : strs) {
            Arrays.fill(chars, 0);
            for (char c : s.toCharArray()) {
                chars[c - 'a']++;
            }
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < chars.length; i++) {
                builder.append("#");
                builder.append(chars[i]);
            }
            String key = builder.toString();
            if (!table.containsKey(key)) {
                table.put(key, new ArrayList<String>());
            }
            table.get(key).add(s);
        }
        return new ArrayList(table.values());
    }
}
