class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        map<int,int>stdmap; 
        for(int i:nums)
        {
            stdmap[i]++; 
        }  
        int res=0;
        for(const auto &i:stdmap)
        {
            if(i.second==2)
            {
                res^=i.first;
            }
        } 
        return res;
    }
};