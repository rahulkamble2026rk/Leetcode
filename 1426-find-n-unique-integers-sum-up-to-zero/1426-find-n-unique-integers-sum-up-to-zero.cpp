// class Solution {
// public:
//     vector<int> sumZero(int n)  
//     { 
//         vector<int>vct;  

//         if(n%2)
//         {
//             int start=(n/2)+1; 

//             for(int i=start;i>=1;i--)
//             {
//                 vct.push_back(i*(-1)); 
//             }  

//           vct.push_back(0);
            
           

//             int size=vct.size();
//             for(int i=0;i<size;i++)
//             {
//                 if(vct[i] != 0) // don't mirror 0
//                     vct.push_back(vct[i] * (-1)); 
//             } 
//             sort(vct.begin(),vct.end()); 

//         } 
//         else 
//         {
//             int start=(n/2); 
//             for(int i=start;i>=1;i--)
//             {
//                 vct.push_back(i*(-1));
//             } 
//              int size=vct.size();
//             for(int j=size-1;j>=0;j--)
//             {
//                 vct.push_back(vct[j]*(-1));
//             } 
//             sort(vct.begin(),vct.end());
//         } 

//         return vct;
//     }
// };


class Solution {
public:
    vector<int> sumZero(int n)  
    { 
        vector<int> vct;  

        if(n % 2) // odd
        {
            int start = (n/2); 
            for(int i=start; i>=1; i--)
            {
                vct.push_back(i * (-1)); 
            }  
            
            vct.push_back(0); // insert the middle element

            int size = vct.size();
            for(int i=0; i<size; i++)
            {
                if(vct[i] != 0) // don't mirror 0
                    vct.push_back(vct[i] * (-1)); 
            } 
            sort(vct.begin(), vct.end()); 
        } 
        else // even
        {
            int start = (n/2); 
            for(int i=start; i>=1; i--)
            {
                vct.push_back(i * (-1));
            } 
            int size = vct.size();
            for(int j=size-1; j>=0; j--)
            {
                vct.push_back(vct[j] * (-1));
            } 
            sort(vct.begin(), vct.end());
        } 

        return vct;
    }
};
