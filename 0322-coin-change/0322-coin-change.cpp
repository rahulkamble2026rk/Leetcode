class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        int n=coins.size(); 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=count(coins,amount,n-1,dp);
        return (res>=1e9)?-1:res;
    } 
    int count(vector<int>coins,int amount,int ind,vector<vector<int>>&dp)
    {
         
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            {
                return (amount/coins[ind]);
            } 
            else
            {
                return 1e9;
            }
        }

        int nottake=0+count(coins,amount,ind-1,dp); 
        int take=1e9; 
        if(amount>=coins[ind])
        {
            take=1+count(coins,amount-coins[ind],ind,dp);  //as we are taking the element infinty so there is no need to take the ind-1 , beause we can take that element after word as well 
        } 
        return dp[ind][amount]=min(nottake,take);
    }
};