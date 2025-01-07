// class Solution {
// public:
//     vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries)
//     {
//         vector<vector<int>> vct; 
//         vector<string> mark; 
//         vector<int> t; 

//         // Step 1: XOR queries and store results
//         for (int i = 0; i < queries.size(); i++) {
//             int x = queries[i][0]; 
//             int y = queries[i][1];  
//             cout << "Result:->" << (x ^ y) << endl;
//             t.push_back(x ^ y); // Store XOR result
//         }

//         // Step 2: Convert XOR results to binary strings
//         for (int i = 0; i < t.size(); i++) { 
//             cout << "Conversion is :->" << convert(t[i]) << endl;
//             mark.push_back(convert(t[i])); // Store the binary string
//         }

//         // Step 3: Find each binary string in the main string 's'
//         for (int i = 0; i < mark.size(); i++) {   
//             vector<int> temp;
//             size_t pos = s.find(mark[i]);  // Corrected substring search
            
//             // Handle case where substring is found
//             if (pos != string::npos) {
//                 temp.push_back(pos); // start index of the substring
//                 temp.push_back(pos + mark[i].size() - 1); // end index of the substring
//                 vct.push_back(temp);  // Store the result
//             } else {
//                 temp.push_back(-1); 
//                 temp.push_back(-1);  
//                 vct.push_back(temp);  // No match found, return [-1, -1]
//             }
//         }

//         return vct;
//     }

//     string convert(int num)
//     {
//         string res = ""; 
//         while (num > 0) {
//             res += num % 2 + '0'; // Convert each digit to binary
//             num /= 2;
//         }
        
//         // If the binary string is empty (i.e., for num = 0), return "0"
//         if (res.empty()) {
//             return "0";
//         }

//         cout << "String is " << res << endl;  
//         reverse(res.begin(), res.end());  // Reverse to get the correct binary representation
//         return res;
//     }
// };
 
 class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> vct; 
        unordered_map<string, int> substrMap; 
        
        for (int len = 1; len <= 30; ++len) { 
            for (int i = 0; i + len <= s.size(); ++i) {
                string sub = s.substr(i, len);
                if (substrMap.find(sub) == substrMap.end()) {
                    substrMap[sub] = i;
                }
            }
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0]; 
            int y = queries[i][1];  
            int result = x ^ y;
            
            string binaryResult = convert(result);
            
            vector<int> temp;
            if (substrMap.find(binaryResult) != substrMap.end()) {
                int startIdx = substrMap[binaryResult];
                temp.push_back(startIdx);
                temp.push_back(startIdx + binaryResult.size() - 1);
            } else {
                temp.push_back(-1);
                temp.push_back(-1);
            }
            vct.push_back(temp);
        }

        return vct;
    }

    string convert(int num) {
        string res = ""; 
        while (num > 0) {
            res += num % 2 + '0'; 
            num /= 2;
        }
        
        if (res.empty()) {
            return "0";
        }

        reverse(res.begin(), res.end());  
        return res;
    }
};
