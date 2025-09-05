// class Solution {
// public:
//     int makeTheIntegerZero(int num1, int num2) 
//     {
//         //storing the values of the  
//         vector<long long >store; 
//         for(int i=0;i<=60;i++)
//         {
//             store.push_back(pow(2,i)+num2);
//         } 

//         //so now we have to array now we have to find whehter number is occuring or not if yes then how many steps are required: 
         
//          if(min_step(0,num1,store)==INT_MAX)
//          {
//             return -1;
//          } 
//          return min_step(0,num1,store);
//     } 

//     int min_step(int ind,int num,vector<long long >&store)
//     {
//         if(ind>=store.size())
//         {
//             return INT_MAX;
//         } 
//         if(num==0)
//         {
//             return 0;
//         } 

//         int take=INT_MAX; 
//         if(num>=store[ind])
//         {   
//             int res=min_step(ind,num-store[ind],store);
//             if(res!=INT_MAX)
//             {
//                 take=1+res;
//             }
//         } 

//         int nottake=min_step(ind+1,num,store); 
//         return min(take,nottake);
//     }
// }; 

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL * num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= __builtin_popcountll(x)) {
                return k;
            }
        }
        return -1;
    }
};