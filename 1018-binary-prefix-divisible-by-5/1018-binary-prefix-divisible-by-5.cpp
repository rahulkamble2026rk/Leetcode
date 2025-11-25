class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)  
    {
        // firstly we have to convert the array into the string : 
        string str="";   
        vector<bool>vct;
       
        for(int i=0;i<nums.size();i++)
        {
            str+=char(nums[i]+'0');
            bool ans=convert_to_number(str);  

            vct.push_back(ans); 
        }  
        return vct;

    } 
    int convert_to_number(string str)
    {
        reverse(str.begin(),str.end());  
        long long power=1;
        long long sum=0;
        for(int i=0;i<str.size();i++)
        {    
            int bit=str[i]-'0'; 
            sum=sum+bit*power; 
            power=power*2;
            sum%=5; 
            power%=5;
        }    
        return (sum % 5 == 0);
    }
};