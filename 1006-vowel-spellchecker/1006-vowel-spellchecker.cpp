// class Solution {
// public:
//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
//     {
//         //step1: traversing the queries 
//         //if the word is exactly match then return that word from wordList 
//         //if the query matches upto captilization then u should return first match from wordlist 
//         //if the query matches via the vowel error, if matches due to vowel <-> vowel then return first from wordlist 
//         //if no match then "";

//         unordered_map<string,int>stdmap; 
//         for(int i=0;i<wordlist.size();i++)
//         {
//             stdmap[wordlist[i]]=1; 
//         }  

//         unordered_map<string,string>stdmap2; 
//         for(int i=0;i<wordlist.size();i++)
//         {  
//             string word=wordlist[i]; 
//             transform(word.begin() , word.end() , word.begin() , ::tolower);
//             if (stdmap2.find(word) == stdmap2.end()) 
//             {  
//                 stdmap2[word] = wordlist[i]; 
//             }
//         } 

//         vector<string>ans;  
//         int ind=0;
//         int n=wordlist.size();
//         for(int i=0; i<queries.size();i++)
//         {
//             if(stdmap.count(queries[i]))
//             {
//                 ans.push_back(queries[i]);
//             } 
//             else 
//             {
//                 //1.captalization:  
//                 string query=queries[i]; 
//                 transform(query.begin(),query.end() , query.begin() , ::tolower);
//                 if(stdmap2.count(query))
//                 {   
//                     ans.push_back( stdmap2[query]);
//                     continue;
//                 }
//                 //2.vowel error:  
            
//                 ind=0; 

//                 transform(queries[i].begin(), queries[i].end() ,queries[i].begin(), ::tolower);
//                 while(ind<n)
//                 {
//                     if(queries[i].length()==wordlist[ind].length())
//                     { 
//                         string lowerWord = wordlist[ind];  
//                         transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
//                         if(check(queries[i] , lowerWord) )
//                         {
//                             ans.push_back(wordlist[ind]); 
//                             break;
//                         }
//                     } 
//                     ind++;
//                 }

//                 if(ind==n)
//                 {
//                     ans.push_back("");
//                 } 

//             }
//         } 

//         return ans;
//     } 

//     int compare(string str,string str2)
//     {
//         transform(str.begin(),str.end(),str.begin(),::tolower); 
//         transform(str2.begin(),str2.end(),str2.begin(),::tolower); 

//         if(str==str2)
//         {
//             return 1;
//         } 
//         return 0;
//     } 

//     int check(string One,string Two)
//     {  
//         int ind=0;
//         while(ind<One.size())
//         { 
//             if(One[ind]==Two[ind] || ( isVowel(One[ind]) && isVowel(Two[ind]) ) )
//             {
//                 ind++;
//             } 
//             else 
//             {
//                 return 0;
//             }
            
//         }  
//         if(ind==One.size())
//         {
//               return 1;
//         } 
//         return 0;
      
//     } 

//     int isVowel(char ch)
//     {    
//         ch=tolower(ch);
//         if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
//         {
//             return 1;
//         } 
//         return 0;
//     }
// };


class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        unordered_map<string,int> stdmap;
        for (int i = 0; i < wordlist.size(); i++) {
            stdmap[wordlist[i]] = 1;
        }

        unordered_map<string,string> stdmap2;
        unordered_map<string,string> vowelMap;

        for (int i = 0; i < wordlist.size(); i++) {  
            string word = wordlist[i];
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            if (stdmap2.find(lowerWord) == stdmap2.end())
                stdmap2[lowerWord] = wordlist[i];

            string masked = maskVowels(lowerWord);
            if (vowelMap.find(masked) == vowelMap.end())
                vowelMap[masked] = wordlist[i];
        }

        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (stdmap.count(queries[i])) {
                ans.push_back(queries[i]);
                continue;
            }

            string query = queries[i];
            transform(query.begin(), query.end(), query.begin(), ::tolower);

            if (stdmap2.count(query)) {
                ans.push_back(stdmap2[query]);
                continue;
            }

            string maskedQuery = maskVowels(query);
            if (vowelMap.count(maskedQuery)) {
                ans.push_back(vowelMap[maskedQuery]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }

    string maskVowels(string s) {
        for (char &ch : s) {
            if (isVowel(ch)) ch = '*';
        }
        return s;
    }

    int isVowel(char ch) {
        ch = tolower(ch);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return 1;
        return 0;
    }
};
