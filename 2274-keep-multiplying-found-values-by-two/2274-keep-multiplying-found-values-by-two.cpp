class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int ans=0; 
        while(1)
        {
          
            auto val=find(nums.begin(),nums.end(),original); 
            if(val==nums.end())
            {
                ans=original; 
                break;
            }  
            else
            {
                  original*=2;  
            }

        }
        return ans;
    }
};