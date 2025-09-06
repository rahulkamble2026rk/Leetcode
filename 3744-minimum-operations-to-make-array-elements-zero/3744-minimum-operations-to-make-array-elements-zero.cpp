// class Solution {
// public:
//     long long minOperations(vector<vector<int>>& queries) 
//     {
//        long long  ans=0;
//       for(int i=0;i<queries.size();i++)
//       {
//            int l=queries[i][0]; 
//            int r=queries[i][1]; 

//            int l_step=__builtin_popcount(l); 
//            int r_step=__builtin_popcunt(r); 

//            if(l_step==r_step)    //means it beongs to same grp
//            {
//                 int total_number=(r-l)+1; 
//                 int total_step=(total_number)*(l_step); 

//                 ans=ans+(total_step)/2;
//            } 
//            else 
//            {

//            }
//       }    
//     }

    
//     }
// }; 

class Solution {
    using ll = long long;

public:
    ll get(int num) {
        int i = 1;
        int base = 1;
        ll cnt = 0;
        while (base <= num) {
            cnt += 1ll * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1);
            i++;
            base *= 2;
        }
        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for (auto& q : queries) {
            res += (get(q[1]) - get(q[0] - 1) + 1) / 2;
        }
        return res;
    }
};