class Solution {
public: 
static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    { 
        priority_queue<pair<int,int>>maxheap;  
        for(int i=0;i<nums.size();i++)
        {
            maxheap.push({nums[i],i});
        }
        vector<pair<int,int>>ans; 
        while(k!=0)
        {
            ans.push_back(maxheap.top()); 
            maxheap.pop();
            k--;
        }
        sort(ans.begin(),ans.end(),compare); 
        vector<int>res; 
        for(const auto& p :ans)
        {
            res.push_back(p.first);
        }
         return res;
    }
};