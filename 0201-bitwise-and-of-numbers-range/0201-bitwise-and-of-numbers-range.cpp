// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) 
//     {   
//         int num=left; 
//         bitset<32>bits=left; 
//         for(long long i=left+1;i<=right;i++) 
//         {   

//             num=num&i;
//         } 
//         return num;
//     }
// }; 


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {    
        int n=right; 
        int m=left;
         while(n>m)  
          {
            n = n & n-1;
          } 
       return m&n;
    }
};