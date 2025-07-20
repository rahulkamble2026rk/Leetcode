class Node
{
    //create the ref. of array of the 26 size: 
    Node* Links[26]; 
    bool flag; 

    public: 
    Node()
    {
        for(int i=0;i<26;i++)
        {
            Links[i]=NULL;
        } 
        flag=false;
    } 

    bool containsKey(char ch)
    {
        if(Links[ch-'a']!=NULL)
        {
            return true;
        } 
        return false;
    }  

    void put(char ch,Node* node)
    {
        Links[ch-'a']=node;
    } 

    Node* get(char ch)
    {
        return Links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    } 

    bool isEnd()
    {
        return flag;
    }

};
class Trie 
{
    public: 
    Node* root; 

    Trie()  
    {
        root=new Node();
    }
    
    void insert(string word)  
    {
        Node* node=root; 

        for(int i=0;i<word.length();i++)
        {
            if(node -> containsKey(word[i])==false)  //if that character is not present then put that node
            {
                node->put(word[i],new Node());
            } 
            node=node->get(word[i]);
        } 
        node->setEnd();
    }
    
    bool search(string word)  
    { 
        Node* node=root; 

        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            } 
            node=node->get(word[i]);
        } 
        return node->isEnd();
        
    }
    
    bool startsWith(string prefix) 
    {
        Node* node=root;

        for(int i=0;i<prefix.length();i++)
        {
            if(node->containsKey(prefix[i]))
            {
                node=node->get(prefix[i]);
            }  
            else
            {
                return false;
            }
        } 

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */