class ProductOfNumbers 
{
public: 
    vector<int>vct;
    ProductOfNumbers() 
    {
        
    }
    
    void add(int num) 
    {
        vct.push_back(num);    
    }
    
    int getProduct(int k) 
    {
        int mul=1; 
        int n=vct.size(); 
        int j=n-1; 
        for(int i=0;i<k;i++)
        {
            mul=mul*vct[j]; 
            j--;
        }     
        return mul;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */