// class Solution {
// public:
//     string lastSubstring(string s)  
//     {
//         //for the lexigrophically use the max(string,string) 
         
//          string res=""; 
//          for(int i=0;i<s.size();i++)
//          {  
//             for(int j=0;j<s.size();j++)
//             {
//                 res=max(res,s.substr(i,j+1));
//             }   
//          } 
//          return res;
//     }
// }; 

#include <string_view>

class Solution {
public:
    string lastSubstring(string s) {
        char maxChar = *max_element(s.begin(), s.end());
        string_view best = "";

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == maxChar) {
              string_view candidate = string_view(s).substr(i);
                if (candidate > best) {
                    best = candidate;
                }
            }
        }

        return string(best);
    }
};
