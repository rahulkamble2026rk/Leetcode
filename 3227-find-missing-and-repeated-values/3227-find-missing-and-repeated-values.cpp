class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n=grid.size()*grid.size(); 
         map<int,int>stdmap;
         for(int i=0;i<grid.size();i++)
         {
            for(int j=0;j<grid[i].size();j++)
            {
                stdmap[grid[i][j]]++;
            }
         } 
         vector<int>ans; 
         int two=0 ; 
         int single=0;
         for(int i=0;i<n;i++)
         {
            if(stdmap[i+1]==2)
            {
                two=i+1;
            } 
            else if(stdmap[i+1]==0)
            {
                single=i+1;
            }
         } 
         ans.push_back(two); 
         ans.push_back(single);
         return ans;
    }
};