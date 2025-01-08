// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
//     { 
//         vector<int>index; 
//         vector<int>ans;
//         for(int i=0;i<nums1.size();i++)
//         {
//             index.push_back(distance(nums2.begin(),find(nums2.begin(),nums2.end(),nums1[i])));
//         } 
//         for(int i=0;i<index.size();i++)
//         {    
//              int flag=0;
//             for(int j=index[i];j<nums2.size();j++)
//             {
//                 if(nums2[j]>nums2[index[i]])
//                 {
//                     ans.push_back(nums2[j]);  
//                     flag=1;
//                     break;
//                 }
//             } 
//             if(flag==0)
//             {
//                 ans.push_back(-1);
//             }
//         } 
//         return ans;
//     }

// };
 

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
       
       stack<int>stk; 
       int n=nums2.size();  
       vector<int>store;
       for(int i=n-1;i>=0;i--)
       {
            int x=nums2[i]; 
            while(!stk.empty()&&x>stk.top())
            {
                stk.pop();
            } 
            if(!stk.empty())
            {
                store.push_back(stk.top());
            } 
            else 
            {
                store.push_back(-1); 
            } 
             stk.push(x);
       } 

       for(int i:store)
       {
        cout<<i<<": ";
       } 
       reverse(store.begin(),store.end());
       for(int i=0;i<index.size();i++)
       {
         ans.push_back(store[index[i]]);
       } 
       return ans;
    }
 };