// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs)  
//     {
//         // you are given an array of n  strings , all of the same length  
//         // we may choose any deltion indices , and we delete all the characters in those indices for each stirng  
//         //we have to check that after by which column of remove teh string array will become lexigrophic in order (increasing) 

//         //I will take each character of the first string , and always compare with teh next string , and also I will update the current character as well 
         

//          string str=strs[0]; 
//          for(int i=0;i<str.size();i++)
//          {

//          }
//     }
// }; 

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // resolved[i] indicates strs[i] < strs[i+1] is finalized
        vector<bool> resolved(n - 1, false);
        int unresolved = n - 1;
        int deletions = 0;

        for (int col = 0; col < m && unresolved > 0; col++) {
            bool bad = false;

            // Check for lexicographical violation
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                deletions++;
                continue;
            }

            // Lock in strictly ordered row pairs
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                    resolved[i] = true;
                    unresolved--;
                }
            }
        }

        return deletions;
    }
};