// // class Solution {
// // public:
// //     long long maxTotalValue(vector<int>& nums, int k) 
// //     { 
// //         //step1: we have to divide nums into the k no. of the subarrays , like  
         
// //          priority_queue<long long >ans;
// //          for(int i=0;i<nums.size()-1;i++)
// //          { 
// //             priority_queue<int>pq1; 
// //             priority_queue<int,vector<int>,greater<int>>pq2;    
// //             pq1.push(nums[i]); 
// //             pq2.push(nums[i]); 

// //              ans.push(0);
// //             for(int j=i+1;j<nums.size();j++)
// //             {
// //                 pq1.push(nums[j]); 
// //                 pq2.push(nums[j]); 
                
// //                 int x=pq1.top(); 
// //                 int y=pq2.top(); 
// //                 ans.push(x-y);
// //             }
// //          } 


// //          int sum=0;
// //          while(k--)
// //          {  
// //             cout<<ans.top()<<"->";
// //             sum+=ans.top(); 
// //             ans.pop();
// //          } 
        
// //         //  while (k > 0 && !ans.empty())
      
// //         return sum;

// //     }
// // };

// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         priority_queue<long long> ans; // To store max - min for each subarray
//         int n = nums.size();
        
//         // Generate all subarray values (max - min)
//         for (int i = 0; i < n; i++) {
//             priority_queue<int> pq1; // Max heap
//             priority_queue<int, vector<int>, greater<int>> pq2; // Min heap
//             pq1.push(nums[i]);
//             pq2.push(nums[i]);
            
//             for (int j = i; j < n; j++) {
//                 pq1.push(nums[j]);
//                 pq2.push(nums[j]);
                
//                 long long maxVal = pq1.top();
//                 long long minVal = pq2.top();
//                 ans.push(maxVal - minVal); // Store max - min
//             }
//         }
        
//         // Find the maximum value in ans
//         if (ans.empty()) return 0;
//         long long maxDiff = ans.top(); // Get the largest max - min value
        
//         // Since we can choose the same subarray multiple times,
//         // the optimal solution is to take the maximum difference k times
//         return maxDiff * k;
//     }
// }; 

// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         long long maxDiff = 0; // Track the maximum max - min value
//         int n = nums.size();
        
//         // Iterate over all possible subarrays
//         for (int i = 0; i < n; i++) {
//             priority_queue<int> pq1; // Max heap
//             priority_queue<int, vector<int>, greater<int>> pq2; // Min heap
//             pq1.push(nums[i]);
//             pq2.push(nums[i]);
            
//             // Generate subarrays starting at i
//             for (int j = i; j < n; j++) {
//                 pq1.push(nums[j]);
//                 pq2.push(nums[j]);
                
//                 long long maxVal = pq1.top();
//                 long long minVal = pq2.top();
//                 maxDiff = max(maxDiff, maxVal - minVal); // Update max difference
//             }
//         }
        
//         // Return the maximum difference multiplied by k
//         return maxDiff * k;
//     }
// }; 

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)  
    {    
        int maxi=*max_element(nums.begin(),nums.end()); 
        int mini=*min_element(nums.begin(),nums.end()); 
        
        return (1LL*(maxi-mini)*k); 
    }
};