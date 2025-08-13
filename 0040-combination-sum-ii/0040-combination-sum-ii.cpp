class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {   
        vector<int> vct; 
        set<vector<int>> ans; 
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> dp(candidates.size(), vector<int>(target+1, -1)); 

        take(0, target, candidates, vct, ans, dp); 
        
        vector<vector<int>> ans2(ans.begin(), ans.end());
        return ans2;
    } 

    void take(int ind, int target, vector<int>& candidates, vector<int>& vct, 
              set<vector<int>>& ans, vector<vector<int>>& dp)
    {
        if (target == 0) 
        {
            ans.insert(vct); 
            return;
        }
        if (ind >= candidates.size()) 
        {
            return;
        }

        // TAKE case
        if (candidates[ind] <= target) 
        { 
            vct.push_back(candidates[ind]);
            take(ind + 1, target - candidates[ind], candidates, vct, ans, dp); 
            vct.pop_back();
        } 

        // NOT TAKE case — skip duplicates here
        int nextInd = ind + 1;
        while (nextInd < candidates.size() && candidates[nextInd] == candidates[ind]) 
        { 

            nextInd++;
        }

        take(nextInd, target, candidates, vct, ans, dp); 

        dp[ind][target] = 0; // optional here
    }
};
