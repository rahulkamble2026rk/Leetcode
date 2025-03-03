// class Solution {
// public:
//     int minInsertions(string s) 
//     {
//         string temp=s;
//         reverse(temp.begin(),temp.end()); 
//         if(s==temp)
//         {
//             return 0;
//         }  
//         map<char,int>stdmap; 
//         for(int i=0;i<s.size();i++)
//         {
//             stdmap[s[i]]++;
//         }  

//         int oddcount=0; 
//         int evencount=0;  
//         for(const auto &i:stdmap)
//         {
//             if(i.second%2==1)
//             {
//                 oddcount++;
//             }  
//             else
//             {
//                 evencount++;
//             }
//         }  
//         if(oddcount==0) 
//         {
//             return evencount;
//         }
//         return oddcount-1;
//     }
// }; 

class Solution {
public:
    int minInsertions(string s) 
    {
        string temp = s;
        reverse(temp.begin(), temp.end());

        if (s == temp)  
        {
            return 0;
        }  
        
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Compute Longest Palindromic Subsequence (LPS) using LCS of s and reverse(s)
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == temp[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int lps = dp[n][n];
        return n - lps;  // Minimum insertions needed
    }
};
