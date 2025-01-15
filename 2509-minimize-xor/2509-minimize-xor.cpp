// class Solution {
// public:
//     int minimizeXor(int num1, int num2) 
//     { 
//         int xorresult = INT_MAX;
//         int ans = 0;
//         int count2 = __builtin_popcount(num2);

//         for (int i = 0; i < (1 << 20); i++) 
//         { 
//             if (__builtin_popcount(i) == count2) 
//             {     
//                 int currentXor = i ^ num1;
//                 if (currentXor < xorresult) 
//                 {
//                     xorresult = currentXor;
//                     ans = i; 
//                 }
//             }
//         } 
//         return ans;
//     }
// };

class Solution {
public:
    int minimizeXor(int num1, int num2)  
     {  
        int count=__builtin_popcount(num2);  
        int res=0;
        for(int i=31;i>=0&&count;i--)
        {
            if(num1&(1<<i))  //this is checkigther the points iss set or  not when go from teh heightest to the smallest one
            {
                    count--; 
                    res+=(1<<i);
            }
        }    

        for(int i=0;i<32 && count;i++)
        {
            if((num1&(1<<i))==0)
            {
                count--; 
                res+=(1<<i);
            }
        } 
        return res;
    }
};