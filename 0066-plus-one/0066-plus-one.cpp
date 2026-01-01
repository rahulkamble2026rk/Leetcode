// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits)  
//     {
//         //ok means we have to add 1 to extrame last element , if any carry then fwd to it's left side element: 

//         int n=digits.size(); 
//         deque<int>que; 
//         for(int i=0;i<digits.size();i++)
//         {
//             que.push_back(digits[i]);
//         } 

//         // int carry=1; 
        
//         // int first=que.back();  
//         // que.pop_back();
//         // first+=1; 
//         // if(first==10)
//         // {
//         //     if (!que.empty()) {
//         //         int second = que.back(); 
//         //         que.pop_back();
//         //         second += 1; 
//         //         que.push_back(second); 
//         //         que.push_back(0);
//         //     } else {
//         //         // Case like [9]
//         //         que.push_back(1);
//         //         que.push_back(0);
//         //     }
//         // } 
//         // else 
//         // {

//         // que.push_back(first);
//         // }  
//           int carry = 1;

//         while (!que.empty() && carry) {
//             int val = que.back();
//             que.pop_back();
//             val += carry;

//             if (val == 10) {
//                 que.push_back(0);
//                 carry = 1;
//             } else {
//                 que.push_back(val);
//                 carry = 0;
//             }
//         }

//         // If carry still exists (case like [9,9,9])
//         if (carry) {
//             que.push_front(1);
//         }
         
//          vector<int>ans; 
//          while(!que.empty())
//          {   
//             ans.push_back(que.front());
//             que.pop_front();
//          } 
//          return ans;

//     }
// };

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;     
    }
};