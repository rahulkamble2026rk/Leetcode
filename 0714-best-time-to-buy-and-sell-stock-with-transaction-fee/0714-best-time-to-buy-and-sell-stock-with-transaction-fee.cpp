// class Solution {
// public:
//     int maxProfit(vector<int>& prices,int fee) 
//     {  
//         int canBuy=1;   
//         int n=prices.size()+1;  
//         //In memoization from 0 to size 
//         //In tabulation from size to 0; 
        
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return findmaxprofit(canBuy,prices,0,dp,fee);
//     } 
//     int findmaxprofit(int canBuy,vector<int>&prices,int ind, vector<vector<int>>&dp,int fee)
//     {
//         if(ind>=prices.size())
//         {
//             return 0;
//         } 
//         if(dp[ind][canBuy]!=-1)
//         {
//             return dp[ind][canBuy];
//         }  
//         int profit=0;
//         if(canBuy)  //means it can do the buying so reduce the profit
//         {
//             int buy=-prices[ind]+findmaxprofit(0,prices,ind+1,dp,fee); 
//             int notbuy=0+findmaxprofit(1,prices,ind+1,dp,fee); 
//             profit=max(buy,notbuy); 
//         } 
//         else 
//         {
//             int sell=(prices[ind]-fee)+findmaxprofit(1,prices,ind+1,dp,fee);  //here completion of one trascation here 
//             int notsell=0+findmaxprofit(0,prices,ind+1,dp,fee); 
//             profit=max(sell,notsell);
//         } 
//         return dp[ind][canBuy]=profit;
//     }
// }; 
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) 
    {  
        int canBuy=1;   
        int n=prices.size()+1;  
        //In memoization from 0 to size 
        //In tabulation from size to 0; 
        
        vector<vector<int>>dp(n,vector<int>(2,0)); 
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                if(canBuy)  //buy
                {
                    dp[ind][1]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                } 
                else   //sell
                {
                    dp[ind][0]=max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
                }
            }
        } 
        return dp[0][1];
    } 
   
};