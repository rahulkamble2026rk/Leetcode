// class Solution {
// public:
//     vector<int> separateDigits(vector<int>& nums)  
//     {
//         vector<int>vct; 
//         for(int i=0;i<nums.size();i++)
//         {
//             seperate_digit(nums[i],vct);
//         } 
//         return vct;
//     }  

//     void seperate_digit(int num,vector<int>&vct) 
//     { 
//         num=reverse_integer(num);
//        while(num>0)
//        {
//         int rem=num%10; 
//         num/=10;  
//         if(rem!=0)
//         {
//             vct.push_back(rem);
//         }
        
//        }
//     } 


//     int reverse_integer(int num)
//     {
//         int result=0; 
//         int mul=1;
//         while(num>0)
//         {
//            int rem=num%10; 
//            result=rem+ (result*mul); 
//            mul*=10; 
//            num/=10;
//         } 
//         return result;
//     }



// }; 


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)  
    {
        vector<int> vct; 

        for(int i = 0; i < nums.size(); i++)
        {
            seperate_digit(nums[i], vct);
        } 

        return vct;
    }  

    void seperate_digit(int num, vector<int>& vct) 
    { 
        string str = to_string(num);

        for(int i = 0; i < str.size(); i++)
        {
            vct.push_back(str[i] - '0');
        }
    } 

};