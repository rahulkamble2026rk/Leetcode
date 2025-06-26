class Solution {
public:
    static bool check(const string &a, const string &b) {
        return a.size() < b.size();  // Strictly increasing size
    }

    bool compare(const string &shorter, const string &longer) {
        if (longer.size() - shorter.size() != 1)
            return false;

        int i = 0, j = 0;
        while (j < longer.size()) {
            if (i < shorter.size() && shorter[i] == longer[j]) {
                i++;
            }
            j++;
        }

        return i == shorter.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), Solution::check);  // sort by length

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (compare(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
