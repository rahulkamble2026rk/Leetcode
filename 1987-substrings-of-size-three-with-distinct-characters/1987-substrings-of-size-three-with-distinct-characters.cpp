class Solution {
public:
    int countGoodSubstrings(string s)  
    {
        int left=0;  
        int count=0; 
        int n=s.size();
        while(left<n-2)
        {
            string str1=s.substr(left,3);
            if(str1[0]!=str1[1] &&  str1[1] != str1[2] && str1[0] != str1[2])
            {
                count++;
            } 
            left++;
        } 
        return count;
    }
};