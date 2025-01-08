class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    { 
        vector<int>index; 
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            index.push_back(distance(nums2.begin(),find(nums2.begin(),nums2.end(),nums1[i])));
        } 
        for(int i=0;i<index.size();i++)
        {    
             int flag=0;
            for(int j=index[i];j<nums2.size();j++)
            {
                if(nums2[j]>nums2[index[i]])
                {
                    ans.push_back(nums2[j]);  
                    flag=1;
                    break;
                }
            } 
            if(flag==0)
            {
                ans.push_back(-1);
            }
        } 
        return ans;
    }

};
