// class Solution {
// public:
//     int compareVersion(string version1, string version2)  
//     {
//         //if the version 1>version2 then return 1 , else return -1  
//         //the value of revision is it integer converion ignoring leadin zeros 
//         // to compare vefsion , we have to ignore the leading zero's 

//         string str1,str2; 
//         int i=0,j=0; 

//         while(1)
//         {
//             while(version1[i]!='.' && version2[j]!='.')
//             {
//                 str1+=version1[i]; 
//                 str2+=version2[j]; 
//                 i++; 
//                 j++;
//             } 

//             if(version1[i]=='.' && version2[j]=='.')
//             {
//                 int num1=stoi(str1); 
//                 int num2=stoi(str2); 
//                 if(num1>num2)
//                 {
//                     return -1;
//                 }
//                 else if(num1<num2)
//                 {
//                     return 1;
//                 } 
//                 else 
//                 {
//                     continue;
//                 }
//             } 

//             else if(version1[i]=='.')
//             {
//                 while(version2[j]!='.')
//                 {
//                     str2+=version[j]; 
//                     j++;
//                 } 

//                 int num1=stoi(str1); 
//                 int num2=stoi(str2); 
//                 if(num1>num2)
//                 {
//                     return -1;
//                 }
//                 else if(num1<num2)
//                 {
//                     return 1;
//                 }
                
//             } 

//             else 
//             {
//                 while(version1[i]!='.')
//                 {
//                     str1+=version[i]; 
//                     i++;
//                 } 

//                 int num1=stoi(str1); 
//                 int num2=stoi(str2); 
//                 if(num1>num2)
//                 {
//                     return -1;
//                 }
//                 else if(num1<num2)
//                 {
//                     return 1;
//                 }
//             }
//         }
//     }
// };


// Optimal: two pointers + on-the-fly parse
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int n1 = version1.length(), n2 = version2.length();
        while (i1 < n1 || i2 < n2) {
            int v1 = 0, v2 = 0;
            while (i1 < n1 && version1[i1] != '.') v1 = v1 * 10 + (version1[i1++] - '0');
            while (i2 < n2 && version2[i2] != '.') v2 = v2 * 10 + (version2[i2++] - '0');
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            i1++; i2++; // skip '.' if present
        }
        return 0;
    }
};