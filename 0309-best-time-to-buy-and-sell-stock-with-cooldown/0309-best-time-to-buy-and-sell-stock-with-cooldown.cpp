class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {  
        int canBuy=1;   
        int n=prices.size()+1; 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findmaxprofit(canBuy,prices,0,dp);
    } 
    int findmaxprofit(int canBuy,vector<int>&prices,int ind, vector<vector<int>>&dp)
    {
        if(ind>=prices.size())
        {
            return 0;
        } 
        if(dp[ind][canBuy]!=-1)
        {
            return dp[ind][canBuy];
        }  
        int profit=0;
        if(canBuy)  //means it can do the buying so reduce the profit
        {
            int buy=-prices[ind]+findmaxprofit(0,prices,ind+1,dp); 
            int notbuy=0+findmaxprofit(1,prices,ind+1,dp); 
            profit=max(buy,notbuy); 
        } 
        else 
        {
            int sell=prices[ind]+findmaxprofit(1,prices,ind+2,dp);  //here completion of one trascation here 
            int notsell=0+findmaxprofit(0,prices,ind+1,dp); 
            profit=max(sell,notsell);
        } 
        return dp[ind][canBuy]=profit;
    }
};