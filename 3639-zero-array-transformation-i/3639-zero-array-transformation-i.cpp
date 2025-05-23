class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int>vct(nums.size()+1,0); 
        for(int i=0;i<queries.size();i++)
        {
            int left=queries[i][0]; 
            int right=queries[i][1]; 
            vct[left]+=1;  
            vct[right+1]-=1;
            
        } 

        for(int i=1;i<vct.size();i++)
        {
            vct[i]+=vct[i-1];
        } 
       
         for(int j=0;j<vct.size();j++)
         {
            cout<<vct[j]<<endl;
         } 
         for(int j=0;j<vct.size()-1;j++)
         {
            if(vct[j]<nums[j])
            {
                return false;
            }
         }
        return true;
    }
};