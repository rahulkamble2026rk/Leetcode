// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k)  
//     {
//         set<int>st;  
//         int sum=0;
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];  
//             if(st.find(sum-k)!=st.end())
//             {
//                 count++;
//             }
//             st.insert(sum); 

//         } 
//         return count+1;
//     }
// }; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> st;
        int sum = 0;
        int count = 0;
        st[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (st.find(sum - k) != st.end()) {
                count += st[sum - k];
            }
            st[sum]++;
        }

        return count;
    }
};
