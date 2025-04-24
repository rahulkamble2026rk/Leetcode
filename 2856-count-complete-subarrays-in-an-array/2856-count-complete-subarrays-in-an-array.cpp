class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        unordered_set<int>st;  
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        } 
      int distinct=st.size();

        for(int i=0;i<nums.size();i++)
        {     
            unordered_map<int,int>stdmap;
            for(int j=i;j<nums.size();j++)
            {
               
                stdmap[nums[j]]++;
                if(stdmap.size()==distinct)
                {
                    count+=(nums.size()-j); 
                    break;
                }
            }
        } 
        return count;
    } 
    bool check(vector<int>temp,int dist)
    {  
     
       unordered_set<int>st;   
       if(temp.size()<dist)
       {
        return false;
       }
        int count=0;
        for(int i=0;i<temp.size();i++)
        {
            st.insert(temp[i]);
        }  
        return st.size()==dist;
    }
}; 

// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) 
//     { 
//         const int n=nums.size(); 
//         unordered_set<int>uniq(nums.begin(),nums.end()); 
//         const need=uniq.size(); 

     
//         int ans=0; 
        
//         for(int i=0;i<n;++right) 
//         {
//             unordered_map<int,int>freq; 
//             int have=0; 

//             for(int j=i;j<n;j++)
//             {
//                 if(freq[nums[j]]==1)
//                 {
//                     ++have;
//                 } 
//                 if(have==need)
//                 {
//                     ++ans;
//                 }
//             }
//         } 
//         return ans;
//     }
// };