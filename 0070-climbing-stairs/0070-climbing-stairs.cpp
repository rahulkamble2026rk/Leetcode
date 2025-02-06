// class Solution {
// public:
//     int climbStairs(int n) 
//     {
//         //hete we have ask the number fo the ways then their will be use of the DP 
//         //here we an perform either 1 step or 2 step climb so 
//         return count(n);
//     } 
//     int count(int n)
//     {
//          if(n==0)
//         {
//             return 1;
//         } 
         
//          if(n==1)
//          {
//             return 1;
//          }
//         int left=count(n-1);  //climbling the 1 step 
//         int right=count(n-2);  //climbling the 2 step 
//         return left+right;    //as we want the total ways
//     }
// }; 

class Solution {
public:
    int climbStairs(int n) 
    {
        //memoization 
        //step1: declate the vector 
        vector<int>dp(n+1,-1); 
        dp[0]=1; 
        dp[1]=1;
         count(n,dp); 
         return dp[n];
    } 
    int count(int n,vector<int>&dp)
    {
         if(n==0)
        {
            return 1;
        } 
         
         if(n==1)
         {
            return 1;
         } 

         if(dp[n]!=-1)
         {
            return dp[n];
         }
        int left=count(n-1,dp);  //climbling the 1 step 
        int right=count(n-2,dp);  //climbling the 2 step 
        return dp[n]=left+right;    //as we want the total ways step2 :storing the subproblems
    }
};