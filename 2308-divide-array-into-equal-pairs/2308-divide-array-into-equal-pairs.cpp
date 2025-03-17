class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        int n=nums.size(); 
        if(n%2)
        {
            return false;
        } 
        map<int,int>stdmap; 
        for(int i:nums)
        {
            stdmap[i]++;
        } 
        for(const auto &i:stdmap)
        {
            if(i.second%2==1)
            {
                return false;
            }
        } 
        return true;
    }
};