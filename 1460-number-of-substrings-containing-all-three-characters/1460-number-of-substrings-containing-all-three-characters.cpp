// class Solution {
// public:
//     int numberOfSubstrings(string s) 
//     {
//         int l=0; 
//         int r=0; 
//         int total=0; 
         
//         for(int i=0;i<s.size();i++)
//         {   
//             string str="";
//             for(int j=i;j<s.size();j++)
//             {
//                 str+=s[j]; 
//                 if(check(str)) 
//                 {
//                     total=total+(s.size()-j); 
//                     break;
//                 }
//             }
//         } 
//         return total;
//     } 
//     int check(string str)
//     {     
//         int a=0,b=0,c=0;
//         for(int i=0;i<str.size();i++)
//         {
//             if(str[i]=='a')
//             {
//                 a++;
//             } 
//             else if(str[i]=='b')
//             {
//                 b++;
//             } 
//             else if(str[i]=='c')
//             {
//                 c++;
//             }
//         } 
//         if(a>=1&&b>=1&&c>=1)
//         {
//             return true;
//         } 
//         return false;
//     }
// };

class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        int r=0; 
        int l=0;  
        string str="";
        vector<int>vct(3,-1); 
        int count=0;  
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            vct[s[i]-'a']=i; 
            if(vct[0]!=-1 && vct[1]!=-1 && vct[2]!=-1)
            {
                count=count+(1+min({vct[0],vct[1],vct[2]}));
            }
        } 
        return count;
    }
};
