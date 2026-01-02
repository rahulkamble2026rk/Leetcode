class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)  
    {
        // type1 costs : cost1 and 1 unit to type 1 req. 
        // type2 coss: cost 2 and 1 unit to type 1 erq. 
        // type3: cost1+cost2 and both types 2 req. 

        // we have to collect enogh items so that total contribution toward type 1 at lest need1 and  
         

         long p1=min(cost1+cost2,costBoth); 
         long p2=min(cost1,costBoth); 
         long p3=min(cost2,costBoth); 

         int cnt=min(need1,need2); 

         int extra1=need1-cnt; 
         int extra2=need2-cnt; 

         long totalcost=(cnt*p1)+(extra1*p2)+(extra2*p3);  

         return totalcost;
    }
};