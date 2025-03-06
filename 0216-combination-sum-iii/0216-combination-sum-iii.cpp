class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {  
        vector<int> vct;
        for (int i = 1; i <= 9; i++) 
        {
            vct.push_back(i);
        } 
        vector<vector<int>> ans; 
        vector<int> temp;  
        countcombination(ans, n, k, temp, 0, vct);
        return ans;
    } 

    void countcombination(vector<vector<int>>& ans, int target, int k, vector<int> temp, int ind, vector<int> vct)
    {
        if (target == 0)
        {
            if (temp.size() == k)
            {
                ans.push_back(temp); 
            } 
            return;
        }  

        if (ind == vct.size()) return;  // Fixing base condition

        temp.push_back(vct[ind]); 
        countcombination(ans, target - vct[ind], k, temp, ind + 1, vct);  // Move to next index  
        temp.pop_back();
        countcombination(ans, target, k, temp, ind + 1, vct);  // Skip current element  
    }
};
