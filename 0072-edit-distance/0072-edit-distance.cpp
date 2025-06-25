class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        // Base cases
        for (int i = 0; i <= size1; i++) dp[i][0] = i;  // Delete all
        for (int j = 0; j <= size2; j++) dp[0][j] = j;  // Insert all

        // Fill the table
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }

        return dp[size1][size2];
    }
};
