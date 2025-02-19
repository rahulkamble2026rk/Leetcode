// class Solution {
// public:
//     int change(int amount, vector<int>& coins) 
//     { 
//         int n=coins.size(); 
//         //here they are interested in the to know that what are the possibilities so take the count directly  
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         return count(amount,coins,n-1,dp);
//     } 
//     int count(int target,vector<int>&coins,int ind,vector<vector<int>>&dp)
//     {
//         if(target==0)
//         {
//             return 1;
//         }  
//         if(dp[ind][target]!=-1)
//         {
//             return dp[ind][target];
//         }
//         if(ind==0)
//         {
//             if(target%coins[ind]==0)
//             {
//                 return 1;
//             } 
//             else
//             {
//                 return 0;
//             }
//         } 

//         int nottake=count(target,coins,ind-1,dp); 
//         int take=0; 
//         if(target>=coins[ind])
//         {
//             take=count(target-coins[ind],coins,ind,dp);
//         } 
//         return dp[ind][target]=take+nottake;
//     }
// }; 

//Now by Tabulzation: 
class Solution {
public:
    unsigned long long change(int amount, vector<int>& coins) 
    { 
        int n = coins.size(); 
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        dp[0][0] = 1;
        for (int T = 1; T <= amount; T++) {
            dp[0][T] = (T % coins[0] == 0) ? 1 : 0;
        } 

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                unsigned long long nottake = dp[i - 1][j];  
                unsigned long long take = 0;  
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];  
                } 
                dp[i][j] = take + nottake;
            }
        }
        return dp[n - 1][amount];
    } 
};
