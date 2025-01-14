class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        vector<vector<int>>vct; 
        int i=0,j=0; 
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i][0]>nums2[j][0])
            {
                vct.push_back(nums2[j]); 
                j++;
            }
            else if(nums1[i][0]==nums2[j][0])
            {  
                int x=nums1[i][1]+nums2[j][1]; 
                vector<int>temp; temp.push_back(nums1[i][0]); temp.push_back(x);
                vct.push_back(temp); 
                i++; 
                j++;
            } 
            else 
            {
                 vct.push_back(nums1[i]); 
                i++;
            }
        } 
      while(i<nums1.size())
      {
        vct.push_back(nums1[i]); 
        i++;
      } 
      while(j<nums2.size())
      {
        vct.push_back(nums2[j]); 
        j++;
      } 
      return vct;
    }
};