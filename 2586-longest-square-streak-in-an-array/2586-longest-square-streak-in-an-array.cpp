// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums)  
//     {
//         set<int>st(nums.begin(),nums.end());   
//         set<int>vct;
//         for(int i:st)
//         {
//             if(st.find(pow(i,2))!=st.end())
//             {   
               
//                 vct.insert(i);  
//                  cout<<"I am going "<<i<<endl;
//                 vct.insert(pow(i,2)); 
//                  cout<<"I am going "<<pow(i,2)<<endl;
//             }
//         }
//         if(vct.size()<2)
//         {
//             return -1;
//         } 
//         int count=0;
//         for(size_t index=1;index<st.size();index++) 
//         {
//             auto it=next(st.begin(),index); 
//             auto prev_it=prev(it); 
//             if((*it)==pow(*prev_it,2))
//             {
//                 count++;
//             } 
//         }
//         return count;
//     }
// }; 


typedef long long ll;
class Solution {
public:
   int longestSquareStreak(vector<int>& nums) {
        set<ll> st(nums.begin(), nums.end());   
        ll maxStreak = -1; 

        for (int i : st) {
            ll count = 1;  
             ll current = i; 

            while (st.find(current * current) != st.end()) {  // Continue the streak
                current = current * current;
                count++;
            }

            if (count > 1) {  
                maxStreak = max(maxStreak, count);
            }
        }
        return maxStreak;
    }
};