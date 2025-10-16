// class Solution {
// public:
//     int findSmallestInteger(vector<int>& nums, int value)  
//     {
//         //In one operation u can add or subtract the value from any element of nums , 
//         //MEX(minimum excluded) of array is the smallest missing positive number  

//         //step1: Means Basically u have to form the Array of which have the , means push the abs value in teh array , if the value is neg then mult by -1 then do % val then insert and else just do % val then insert into array 

//         vector<int>store; 
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<0)
//             {
//                 int temp=nums[i]*(-1); 
//                 store.push_back(temp%value);
//             } 
//             else 
//             {
//                 store.push_back(nums[i]%value);
//             }
//         } 

//         sort(store.begin(),store.end()); 

//         int ans=0; 
//         int ind=0; 
//         while(ind<store.size()-1)
//         {
//             if(store[ind+1]==store[ind] || store[ind+1]==store[ind]+1)
//             {
//                 ind++;
//             } 
//             else 
//             {
//                 ans=store[ind]+1;
//                 break;
//             }
//         } 

//         if(ind==store.size()-1)
//         {  
//             ans=store[store.size()-1]+1;
//         }
//         return ans;
//     }
// }; 

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value)  
    {
        // Step 1: Convert each element to its positive remainder modulo 'value'
        vector<int> store;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = ((nums[i] % value) + value) % value;  // handles negatives
            store.push_back(temp);
        }

        // Step 2: Count frequency of each remainder
        unordered_map<int, int> freq;
        for(int x : store) freq[x]++;

        // Step 3: Try to build MEX from 0 upwards
        int ans = 0;
        while(true)
        {
            int rem = ans % value;
            if(freq[rem] > 0)
            {
                freq[rem]--;   // use one element with this remainder
                ans++;         // move to next number
            }
            else break;        // stop when you can’t make current number
        }

        return ans;
    }
};
