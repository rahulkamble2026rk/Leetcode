class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) 
    {  
        int countx=0;
        vector<int>occurancex;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==x)
            {    
                occurancex.push_back(i);
                countx++;
            }
        }  
       
       vector<int>ans;
        for(int i:queries)
        {
            if(i>countx)
            {
                ans.push_back(-1);
            } 
            else
            {
                ans.push_back(occurancex[i-1]);
            }
        } 
        return ans;

    }
};