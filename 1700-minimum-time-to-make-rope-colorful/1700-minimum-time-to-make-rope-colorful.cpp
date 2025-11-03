class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)  
    {
        // you are given the neeetTime , where each show a time in seconds that Bob needs to remove the ith ballon from the rope 
         

         //we have to return the minimum time to make the rope colorful 

         //when the two consecutive are same then the time of summation we have to add the minimum one  


        stack<pair<char,int>>stk;  
        pair<char,int>pt; 
        stk.push({colors[0],neededTime[0]}); 
        pt=stk.top();
        int sum=0;
        for(int i=1;i<colors.size();i++)
        {  
             auto pt = stk.top(); 
            if(pt.first==colors[i])
            {
                int x=pt.second; 
                int y=neededTime[i]; 
                if(x>=y)
                {
                    sum+=y; //zar yenara time kami asel tar don't add or consider into the sum
                } 
                else 
                {
                    sum+=x; 
                    if(!stk.empty())
                    {
                        stk.pop();
                    } 
                    stk.push({colors[i],neededTime[i]});
                }
            } 
            else 
            {
                stk.push({colors[i],neededTime[i]});
            }
        } 

        return sum;



    }
};