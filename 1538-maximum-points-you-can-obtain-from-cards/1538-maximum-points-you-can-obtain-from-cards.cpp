// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k)    //this approach may be not consider the middle heightest elemet
//     {  
//         int l=0; 
//         int sum=0; 
//         int r=cardPoints.size()-1; 
//         while(k!=0)
//         {
//             if(cardPoints[l]>cardPoints[r])
//             {
//                 sum+=cardPoints[l]; 
//                 l++;
//             } 
//             else
//             {
//                 sum+=cardPoints[r]; 
//                 r--;
//             } 
//             k--;
//         } 
//         return sum;
//     }
// }; 

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int leftsum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0); 
        int r=cardPoints.size()-1; 
        int maxsum=leftsum; 
        int rightsum=0;
        for(int i=k-1;i>=0;i--)
        {
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[r]; 
            r--; 
            maxsum=max(maxsum,leftsum+rightsum);
        } 
        return maxsum;
    }
};