class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int canBuy=1; 
        int n=prices.size();  
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return maxprofit(prices,k,0,canBuy,dp); 

    } 
    int maxprofit(vector<int>&prices,int cap,int ind,int canBuy,vector<vector<vector<int>>>&dp)
    {
        if(ind==prices.size())
        {
            return 0;
        } 
        if(cap==0)
        {
            return 0;
        }  
        if (dp[ind][canBuy][cap] != -1) return dp[ind][canBuy][cap];
        int profit=0; 
        if(canBuy)
        {
            int buy=-prices[ind]+maxprofit(prices,cap,ind+1,0,dp); 
            int skip=0+maxprofit(prices,cap,ind+1,1,dp); 
            profit=max(buy,skip);
        } 
        else  //selling happen is here
        {
            int sell=prices[ind]+maxprofit(prices,cap-1,ind+1,1,dp); 
            int skip=0+maxprofit(prices,cap,ind+1,0,dp); 
            profit=max(sell,skip);
        } 
        return dp[ind][canBuy][cap]=profit;
    }
};