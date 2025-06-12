class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums)  
    {
        nums.push_back(nums[0]);
        int maxi=-1e9; 
        for(int i=0;i<nums.size()-1;i++)
        {
            maxi=max(maxi,abs(nums[i]-nums[i+1]));
        } 
        return maxi;
    }
};