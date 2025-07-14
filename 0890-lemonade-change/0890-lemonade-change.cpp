class Solution {
public:
    bool lemonadeChange(vector<int>& bills)  
    {
        int five=0; 
        int ten=0; 
        int twenty=0; 
        int sum=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                five++; 
                sum+=5; 
               
            } 
            else if(bills[i]==10)
            {
                int amount_req=bills[i]-5;
                int need=amount_req/5; 
                if(five>=need)
                {
                    five-=need; 
                    sum=sum-(5*need); 
                     ten++;
                } 
                else
                {
                    return false;
                }
            } 
            else if(bills[i]==20)
            {
                int amount_req=bills[i]-5; 
                
                if(ten>=1 && five>=1)
                {
                    ten--;
                    five--;
                }
               else if(five>=3)
                {
                      
                    five-=3;
                } 
                else
                {
                    return false;
                }
            }
        } 

        return true;
    }
};