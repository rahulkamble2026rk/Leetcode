// class Solution {
// public:
//     int longestNiceSubarray(vector<int>& nums) 
//     {
//        int ans=0; 
//        int i=0,j=0;  
//        int num=0; //Imagine this is like we take the one whole set of the 0 , like 00000000000
//        for(i=0;i<nums.size();i++)
//        {
//             while((num & nums[i])!=0)    //jab tak & of the numbers is not equal to zero then upto that continue the loop
//             {
//                 num^=nums[j];   //1^1=0; 
//                 j++;
//             } 
//             //no problem  
//             num|=nums[i];  //setting bits inside num 
//             ans=max(ans,i-j+1);
//        }
//         return ans;
//     } 

//     //T.C: Log(n)
// }; 


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    { 
        int n=nums.size(); 
        int ans=0; 
        int j=0; 
        bitset<32>bits; ///track the bits of the current window  , this will convert the number into 32 bits

        for(int i=0;i<n;i++)
        {
            bitset<32>numBits(nums[i]); //will convert the number into 32 bits

            while((bits & numBits).any())  //this ckecks whthet the bits get overlapperd or not like ( 1 & 1 )
            {
                bitset<32>removeBits(nums[j]);
                 bits^=removeBits; 
                 j++;
            } 
            bits|=numBits; 
            ans=max(ans,i-j+1);
        } 
        return ans;
    }
};