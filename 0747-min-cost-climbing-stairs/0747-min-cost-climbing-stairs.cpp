class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp(1001); 
        dp[0]=cost[0]; //directly go on teh 0th means first step
        dp[1]=cost[1]; //directly can go the 2nd step

        int n=cost.size(); 
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);    //we have to consider the cost of the curent stair and minimum of the previous either the one step before or two step before
        } 
        return min(dp[n-1],dp[n-2]);
    }
};