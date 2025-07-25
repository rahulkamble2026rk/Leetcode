class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)  
    {
          vector<vector<int>>vct;   
        sort(nums.begin(),nums.end());
        do
        {
            vct.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return vct;
    }
};