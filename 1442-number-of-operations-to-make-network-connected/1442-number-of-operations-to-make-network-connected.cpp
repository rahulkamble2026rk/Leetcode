class Disjoint
{
    public:  
    vector<int>size,parent; 
    Disjoint(int n)
    {
        size.resize(n);    //for 0 base indexing 
        parent.resize(n); 

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;     //Intiallly all node havinf the size of the 1
        } 

    }  
    int findupar(int node)   //this is for the finding the ultimate parent finding
    {
        if(node==parent[node])
        {
            return node; 
        } 
        return parent[node]=findupar(parent[node]);
    } 


    void unionBysize(int u,int v)
    {
        int ulp_u=findupar(u); 
        int ulp_v=findupar(v); 

        if(ulp_u==ulp_v)
        {
            return;
        } 
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v; 
            size[ulp_v]+=size[ulp_u];
        } 
        else 
        {
            parent[ulp_v]=ulp_u; 
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        Disjoint ds(n); 
        int cntextras=0; 
        for(auto it:connections)
        {
            int u=it[0]; 
            int v=it[1]; 
            if(ds.findupar(u)==ds.findupar(v))
            {
                cntextras++;
            } 
            else 
            {
                ds.unionBysize(u,v);
            }
        } 

        int node=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                node++;
            }
        } 

        int requireedges=node-1;    
        if(cntextras>=requireedges)
        {
            return requireedges;
        }  
        return -1;
    }
};