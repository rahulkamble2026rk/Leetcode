// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) 
//     {
//         long long count=0;  
       
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(j-i!=nums[j]-nums[i])
//                 { 
//                     cout<<nums[i]<<" "<<nums[j]<<endl;
//                     count++;
//                 }
//             }
//         } 
//         return count;
//     }
// }; 


class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    { 
        long long n=nums.size(); 
        long long total_pair=n*(n-1)/2; //total forming the total pair 
        
        unordered_map<int,int>freq; 

        long long good_pair=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(freq.count(nums[i]-i))
            {
                good_pair=good_pair+freq[nums[i]-i]; 
            } 
            freq[nums[i]-i]++;
            
        } 
        return total_pair-good_pair;

    }
};