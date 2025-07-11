// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) 
//     {   
        

//         int size1=a.size(); 
//         int size2=b.size();  
//         char ch2=a[0]; 
//         char ch=b[0];
        

//         vector<int>store2; 
//         for(int i=0;i<b.size();i++) 
//         {
//             if(b[i]==ch2)
//             {
//                 store2.push_back(i);
//             }
//         } 

        
//         int flag=0;
//         for(int i=0;i<store2.size();i++)
//         {
//             if(b.substr(store2[i],size1)==a && flag==0)
//             {
//                 flag=1;
//             } 
//             if(flag==1)
//             {
//                 break;
//             }
//         } 

//         int ans=0;
//         if(flag==0)
//         {
//             ans=-1; 
//             return ans;
//         } 


//         vector<int>store; 

//         int i=1;  
//         form(a,store,b,ch);
//         if(check(a,store,b,ch))
//         {  
//             return 1;
//         }
//         while(1)
//         {
//            a+=a;  
//            form(a,store,b,ch);
//            if(check(a,store,b,ch))
//            {
//             return i+1;
//            } 
//            i++;
//         } 
//         return ans;

//     } 

//     bool check(string a,vector<int>&store,string b,char ch)
//     {
//         for(int i=0;i<store.size();i++)
//         {
//             if(a.substr(store[i],b.size())==b)
//             {
//                 return true;
//             }
//         } 
//         return false;
//     } 

//     void form(string a, vector<int>&store,string b, char ch ) 
//     {
//             for(int i=0;i<a.size();i++)
//             {
//                 if(a[i]==ch)
//                 {
//                     store.push_back(i);
//                 }
//             }
//     }
// };


class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        string original = a;
        int i = 1;
        vector<int> store;

        // First check without repeating
        form(a, store, b[0]);
        if (check(a, store, b)) {
            return i;
        }

        // Try repeating until a's length exceeds b's + 2 * a (safe upper bound)
        while (a.size() <= b.size() + 2 * original.size()) {
            a += original;
            i++;
            store.clear();  // Clear previous indices
            form(a, store, b[0]);  // Start matching from positions where a[i] == b[0]
            if (check(a, store, b)) {
                return i;
            }
        }

        return -1;
    }

    bool check(string& a, vector<int>& store, string& b)
    {
        for (int i = 0; i < store.size(); i++) {
            if (store[i] + b.size() <= a.size() && a.substr(store[i], b.size()) == b) {
                return true;
            }
        }
        return false;
    }

    void form(string& a, vector<int>& store, char ch)
    {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == ch) {
                store.push_back(i);
            }
        }
    }
};
