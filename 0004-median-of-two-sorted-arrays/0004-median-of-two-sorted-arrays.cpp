class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans; 
        for(int i:nums1)
        {
            ans.push_back(i);
        } 
         
         for(int j:nums2)
         {
            ans.push_back(j);
         } 
         sort(ans.begin(),ans.end()); 
         double answer=0.0; 
         if(ans.size()%2==1)
         { 
            int ind=ans.size()/2;
            answer=ans[ind];
         } 
         else if(ans.size()%2==0) 
         {
             int ind2=ans.size()/2; 
             int ind1=ind2-1; 
             answer=ans[ind1]+ans[ind2];  
             answer=answer/2.0;
         } 
         return answer;
    }
};