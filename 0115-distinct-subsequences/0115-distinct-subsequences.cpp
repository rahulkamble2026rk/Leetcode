// class Solution {
// public:
//     int numDistinct(string s, string t)  
//     {  
//         int size1=s.size(); 
//         int size2=t.size();
//         return countDistinct(size1-1,size2-1,s,t);
//     } 
//     int countDistinct(int i,int j,string s,string t)
//     {
//         if(j<0)   //if the after whole small string mathces
//         {
//             return 1;   
//         } 

//         if(i<0)     // if the 1st string over befroe second string
//         {
//             return 0;
//         } 
    
//     //case1:Matching
//         if(s[i]==t[j])
//         {
//             int match_take=countDistinct(i-1,j-1,s,t); //regular as matching the both characrters then i-1,j-1
//             int match_notake=countDistinct(i-1,j,s,t); //if match but still I want to find in the another mathcing 
//             return match_take+match_notake;
//         }  

//     // case2:not matching
//         else 
//         { 
//             int no_match_notake=countDistinct(i-1,j,s,t);  //no matching in the with string then go back  
//             return no_match_notake;
//         } 
        
//     }
// }; 


// class Solution {
// public:
//     int numDistinct(string s, string t)  
//     {  
//         int size1=s.size(); 
//         int size2=t.size(); 
//         vector<vector<int>>dp(size1+1,vector<int>(size2+1,-1));
//         return countDistinct(size1-1,size2-1,s,t,dp);
//     } 
//     int countDistinct(int i,int j,string s,string t,vector<vector<int>>&dp)
//     {
//         if(j<0)   
//         {
//             return 1;   
//         } 

//          if(i<0)     
//         {
//             return 0;
//         }  

//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
       
    
//     //case1:Matching
//         if(s[i]==t[j])
//         {
//             int match_take=countDistinct(i-1,j-1,s,t,dp); 
//             int match_notake=countDistinct(i-1,j,s,t,dp); 
//             return dp[i][j]=match_take+match_notake;
//         }  

//     // case2:not matching
//         else 
//         { 
//             int no_match_notake=countDistinct(i-1,j,s,t,dp);  
//             return dp[i][j]=no_match_notake;
//         } 
        
//     }
// }; 


class Solution {
public:
    int numDistinct(string s, string t)  
    {  
        int size1=s.size(); 
        int size2=t.size(); 
        vector<vector<long long >>dp(size1+1,vector<long long >(size2+1,0));  
           const int MOD = 1000000007; 
        for(int i=0;i<=size1;i++)
        {
            dp[i][0]=1; 
        } 
        
        for(int j=1;j<=size2;j++)
        {
            dp[0][j]=0;  //An empty t is always a subsequence of an empty s
        } 

        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
                } 
                else
                {
                    dp[i][j]=dp[i-1][j]%MOD;
                }
            }
        }
        return dp[size1][size2];
    } 
};