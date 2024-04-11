/*
 * @lc app=leetcode.cn id=2369 lang=rust
 * @lcpr version=30117
 *
 * [2369] 检查数组是否存在有效划分
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_partition(nums: Vec<i32>) -> bool {
        let len = nums.len();
        let mut f: Vec<bool> = vec![false; len + 1];
        f[0] = true;
        for i in 1..len {
            let flag1 = f[i - 1] && nums[i] == nums[i - 1];
            let flag2 = i > 1 && f[i - 2] && nums[i] == nums[i - 2] && nums[i] == nums[i - 1];
            let flag3 = i > 1 && f[i - 2] && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1;
            f[i + 1] = flag1 || flag2 || flag3;
        }
        f[len]

    }
}
// @lc code=end



/*
// @lcpr case=start
// [4,4,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2]\n
// @lcpr case=end

 */

