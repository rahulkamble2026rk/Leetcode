class Solution {
public:
    int findTargetSumWays(vector<int>& num, int target) {  
        int n = num.size(); 
        int sum = accumulate(num.begin(), num.end(), 0); 
        
        // Check if partitioning is possible
        if ((sum - target) < 0 || (sum - target) % 2 != 0) {
            return 0;
        }
        
        int k = (sum - target) / 2;  // Corrected target calculation
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        
        return count(n - 1, k, num, dp);
    }
    
    int count(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) { 
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;  // Two ways if first element is zero
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTaken = count(ind - 1, target, arr, dp);
        int taken = 0;
        if (arr[ind] <= target) {
            taken = count(ind - 1, target - arr[ind], arr, dp);
        }
        
        return dp[ind][target] = notTaken + taken;
    }
};
