class Solution {
public:
    vector<int> memLeak(int memory1, int memory2)  
    { 
         int second=1; 
         
        while(true)
        {
            if(memory1>=memory2)
            {
                if(memory1>=second)
                {
                    memory1-=second;
                }   
                else
                {
                    break;
                }
            } 
            else
            {
               if(memory2>=second)
                {
                    memory2-=second;
                }   
                else
                {
                    break;
                }
            } 
            
            if(second==INT_MAX-1)
            {
                break;
            } 
            second++;
        } 
        return {second,memory1,memory2};
    }
};