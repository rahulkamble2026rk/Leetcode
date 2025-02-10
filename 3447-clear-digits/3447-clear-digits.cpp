// class Solution {
// public:
//     string clearDigits(string s)
//     {
//         int n=s.size(); 
//         for(int i=0;i<n;i++)
//         {
//             if((s[i]>=97 && s[i]<=122) && (s[i+1]>=48 && s[i+1]<=57))
//             {
//                 s.erase(i,2); 
//                 i-=1;
//             }
//         } 
//         return s;
//     }
// }; 

class Solution {
public:
    string clearDigits(string s)
    { 
        stack<char>stk; 
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=48 && s[i]<=57) 
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            } 
            else
            {
                stk.push(s[i]);
            }
        } 

        string ans=""; 
        while(!stk.empty())
        {
            ans+=stk.top(); 
            stk.pop();
        } 
        
        reverse(ans.begin(),ans.end()); 
        return ans;
    } 
};