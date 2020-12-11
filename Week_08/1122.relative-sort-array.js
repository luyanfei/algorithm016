/*
 * @lc app=leetcode.cn id=1122 lang=javascript
 *
 * [1122] 最长重复子串
 *
 * https://leetcode-cn.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (66.83%)
 * Total Accepted:    26K
 * Total Submissions: 38.8K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * 给你两个数组，arr1 和 arr2，
 * 
 * 
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 * 
 * 
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1
 * 的末尾。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * 输出：[2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * arr2 中的元素 arr2[i] 各不相同
 * arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 * 
 * 
 */
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let arr = new Array(1001)
    arr.fill(0)
    arr1.forEach(v => arr[v]++)
    let j = 0
    for (let i = 0; i < arr2.length; i++) {
        while (arr[arr2[i]] > 0) {
            arr1[j++] = arr2[i]
            arr[arr2[i]]--
        }
    }
    for (let i = 0; i < arr.length; i++) {
        while (arr[i] > 0) {
            arr1[j++] = i
            arr[i]--
        }
    }
    return arr1
};
