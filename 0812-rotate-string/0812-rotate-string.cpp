// class Solution {
// public:
//     bool rotateString(string s, string goal) 
//     { 
//         if(s.size()!=goal.size())
//         {
//             return false;
//         }
//        s=s+s; 
       
//        string ans; 
//        for(int i=0;i<s[i];i++)
//        {
//           if(s[i]!=32)
//           {
//              ans+=s[i];
//           }
//        }
        
//         int x=ans.find(goal); 
//         if(x!=-1)
//         {
//             return true;
//         } 
//        return false;
//     }
// };

class Solution {
public:
    bool rotateString(string s, string goal) 
    { 
        
        if(s.size() != goal.size()) {
            return false;
        }

     
        s = s + s;

        
        if(s.find(goal) != string::npos) {
            return true;
        } 

        return false;
    }
};
