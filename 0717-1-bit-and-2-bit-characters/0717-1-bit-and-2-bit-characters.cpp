class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)  
    {
        //we have two special characters  
        // first character can be represented by one bit 0 
        // The second characrer can be repented by two bits , (10 or 11) 
        //array of bits that ends with 0 , return true if last charactrer must be a one-bit characrer  
        //zevdya zevde 11, kiva 10 hotil te baga  

       int n=bits.size();  
       int flag=0; 

        int i=0;
       for(i=0;i<bits.size()-1;)
       {
            if( bits[i]==1 && (bits[i+1]==0 || bits[i+1]==1) )
            {
                i+=2; 
            } 
            else if(bits[i]==0)
            {
                i+=1;
            }
       }    
    
        if(i>=n)
        {
            return false;
        }
        if(bits[i]==0)
        {
            return true;
        } 
        return false;

       
    }
};