class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int>posi;
        vector<int>negi; 
         
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i]<0)
            {
                negi.push_back(nums[i]);
            } 
            else 
            {
                posi.push_back(nums[i]);
            }
         } 
          
          vector<int>ans; 
          int k=0; 
          while(k<negi.size())
          {
              ans.push_back(posi[k]); 
              ans.push_back(negi[k]); 
              k++;
          } 
          return ans;
    }
};