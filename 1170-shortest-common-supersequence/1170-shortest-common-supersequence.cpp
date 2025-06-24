class Solution {
public:
    string shortestCommonSupersequence(string s, string p)  
    {
        int size1 = s.size(); 
        int size2 = p.size();

        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0)); 

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (s[i-1] == p[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Reconstruct SCS from DP table
        string result = "";
        int i = size1, j = size2;
        while (i > 0 && j > 0) {
            if (s[i-1] == p[j-1]) {
                result += s[i-1];
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                result += s[i-1];
                i--;
            } else {
                result += p[j-1];
                j--;
            }
        }

        // Add remaining characters
        while (i > 0) {
            result += s[i-1];
            i--;
        }
        while (j > 0) {
            result += p[j-1];
            j--;
        }

        // Since we built it backwards
        reverse(result.begin(), result.end());
        return result;
    }  
};
