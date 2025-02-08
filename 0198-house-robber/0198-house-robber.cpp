class Solution {
public:
    int robHelper(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) return 0;  // Base case
        if (dp[index] != -1) return dp[index];  // Return cached result

        // Either rob this house and jump 2 steps, or skip this house
        int robCurrent = nums[index] + robHelper(nums, index + 2, dp);
        int skipCurrent = robHelper(nums, index + 1, dp);

        return dp[index] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);  // Memoization
        return robHelper(nums, 0, dp);
    }
};
