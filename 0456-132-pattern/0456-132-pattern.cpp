// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int i = 0;
//         int j = i + 1;
//         int k = j + 1;
//         if (is_sorted(nums.begin(), nums.end())) {
//             return false;
//         }
//         // while(i<nums.size()-2)
//         // {
//         //     if(nums[i]<nums[k])
//         //     {
//         //         if(nums[k]<nums[j])
//         //         {
//         //             return true;
//         //         }
//         //     }
//         //     i++;
//         // }
//         // return true;
//         if (nums.size() < 3) 
//         {
//             return false;
//         }
//         bool flag = false;
//         vector<int> vct;
//         pattern132(nums, 0, vct, 3, flag);
//         return flag;
//     }

//     void pattern132(vector<int> nums, int index, vector<int>&vct, int size,bool& flag) 
//     {
//         if(index == nums.size())
//         {
//             if(vct.size()==3) 
//             {
//                 if(vct[0]<vct[2] && vct[2]<vct[1]) 
//                 {
//                     flag = true;
//                 }
//             }
//             return;
//         }

//         if(flag)
//         {
//             return;
//         }
//         vct.push_back(nums[index]);
//         pattern132(nums, index + 1, vct, size, flag);
//         vct.pop_back();
//         pattern132(nums, index + 1, vct, size, flag);
//     }
// }; 


class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> stk;
        int second = INT_MIN;

        for (int i = n - 1; i >= 0; --i) 
        {    
             int x=nums[i];

            if (x<second) 
            {
                return true;
            }

            while (!stk.empty() && x > stk.top()) 
            {
                second = stk.top();
                stk.pop();
            }

            stk.push(x);
        }

        return false;
    }
};

