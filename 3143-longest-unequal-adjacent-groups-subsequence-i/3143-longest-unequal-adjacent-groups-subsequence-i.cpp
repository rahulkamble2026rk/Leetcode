class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // memo[i][lastGroup+1] stores best path from index i with lastGroup
        vector<vector<vector<int>>> memo(words.size(), vector<vector<int>>(3));
        vector<int> path = dfs(0, -1, words, groups, memo);

        vector<string> result;
        for (int idx : path) result.push_back(words[idx]);
        return result;
    }

    vector<int> dfs(int i, int lastGroup,
                    vector<string>& words, vector<int>& groups,
                    vector<vector<vector<int>>>& memo) {
        if (i == words.size()) return {};

        if (!memo[i][lastGroup + 1].empty()) return memo[i][lastGroup + 1];

        // Don't take current word
        vector<int> notTake = dfs(i + 1, lastGroup, words, groups, memo);

        // Take current word if group differs
        vector<int> take;
        if (lastGroup == -1 || groups[i] != lastGroup) {
            take = dfs(i + 1, groups[i], words, groups, memo);
            take.insert(take.begin(), i);
        }

        return memo[i][lastGroup + 1] = (take.size() > notTake.size() ? take : notTake);
    }
};
