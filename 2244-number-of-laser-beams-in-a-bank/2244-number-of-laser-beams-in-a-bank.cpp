 class Solution {
public: 

int count_one(string str)
{   
    int count=0;
    for(int i=0;i<str.size();i++)
    {
         if(str[i]=='1')
         {
            count++;
         }
    } 
    return count;
}
    int numberOfBeams(vector<string>& bank)  
    {
        vector<int>presence; 
        for(int i=0;i<bank.size();i++)
        {  
            int count=count_one(bank[i]);
            presence.push_back(count);
        } 

        //finding the next non-zero number and sum into the varible, 
         
         int sum=0; 
        for(int i=0;i<presence.size();i++)
        { 
            if(presence[i] !=0)
            {
                int ind=find_next_index(i+1, presence);  
                if(ind!=99999) 
                {
                    sum=sum+(presence[i] *presence[ind]); 
                }
            }
        } 

        return sum;
    } 

    int find_next_index(int ind,vector<int>vct)
{
    while( ind<vct.size() && vct[ind]==0 )
    {
        ind++;
    }  

    if(ind==vct.size())  
    {
        return 99999;
    }

   
    return ind;
    
   
}
};  




//binary string , 0 means -> empty , 1 means-> security device  
 
// There is one Leaser beam between any two security devices if the condition met: 

// 1. If the two devices are located on diff. rows , r1 and r2 where r1<r2 
// 2. for each row i where r1<i<r2 , then there is no security devices in the ith row 

// we have to return the total laser number of beams in the bank 