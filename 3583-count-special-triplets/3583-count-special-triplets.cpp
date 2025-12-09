// class Solution {
// public:
//     int specialTriplets(vector<int>& nums)  
//     {
//         //step1:storing in the unordered_map
//         unordered_map<int,vector<int>>stdmap;
//         int n=nums.size(); 
//         for(int i=0;i<n;i++)
//             {
//                 stdmap[nums[i]].push_back(i);
//             } 


//         //step2:now while iterating: 
//         for(auto it:stdmap)
//             {
//                 int val=it.first; 
//                 vector<int>vct=it.second;  
//                 sort(vct.begin(),vct.end());
//                 if(val%2==0 && vct.size()>=2)
//                 {
//                     vector<int>copy=stdmap[val/2];  
                   
//                     if(!copy.empty())
//                     {
//                          sort(copy.begin(),copy.end()); 
//                         for(int j=0;j<copy.size();j++)
//                             {
                                
//                             }
//                     }
//                 }
//             } 
        
//     } 
// }; 

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> stdmap;

        // Step 1: Map each value to its indices
        for (int i = 0; i < n; i++) {
            stdmap[nums[i]].push_back(i);
        }

        long long total = 0;

        // Step 2: For each val where val is double of some smaller value
        for (auto it : stdmap) {
            int val = it.first;
            vector<int>& vct = it.second;
            sort(vct.begin(), vct.end());

            // Only check if val is even and val/2 exists in map
            if (val % 2 == 0 && stdmap.count(val / 2)) {
                vector<int>& midList = stdmap[val / 2];
                sort(midList.begin(), midList.end());

                for (int j : midList) {
                    // Count how many indices of val are before j (left)
                    int left = lower_bound(vct.begin(), vct.end(), j) - vct.begin();

                    // Count how many indices of val are after j (right)
                    int right = vct.end() - upper_bound(vct.begin(), vct.end(), j);

                    total = (total + (1LL * left * right) % MOD) % MOD;
                }
            }
        }

        return total;
    }
};
