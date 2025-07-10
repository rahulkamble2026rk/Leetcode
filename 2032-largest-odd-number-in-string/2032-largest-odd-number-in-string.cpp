// class Solution {
// public:
//     string largestOddNumber(string input)  
//     {
//         string ans = ""; 
//         string str = "";  

//         if ((s_to_i(input) % 2) == 1)
//         {
//             return input;
//         }

//         for (int i = 0; i < input.size(); i++)
//         {
//             str += input[i]; 
//             long long num = s_to_i(str); 
//             if (num % 2 == 1)
//             {  
//                 if (!ans.empty())
//                 {
//                     long long num2 = s_to_i(ans);  
//                     if (num > num2)
//                     {
//                         ans = str;
//                     }
//                 } 
//                 else 
//                 {
//                     ans = str;
//                 }
//             }
//         } 
//         return ans;
//     } 

//     long long s_to_i(string temp)
//     {
//         reverse(temp.begin(), temp.end()); 
//         long long num2 = 0; 
//         long long mul = 1; 

//         for (long long i = 0; i < temp.size(); i++)
//         {
//             num2 += (temp[i] - '0') * mul;
//             mul *= 10;
//         } 
//         return num2;
//     }
// };
 

 class Solution {
public:
    string largestOddNumber(string input)  
    {
        for (int i = input.size() - 1; i >= 0; --i) {
            if ((input[i] - '0') % 2 == 1) {
                return input.substr(0, i + 1);  // return prefix ending at last odd digit
            }
        }
        return "";
    }
};
