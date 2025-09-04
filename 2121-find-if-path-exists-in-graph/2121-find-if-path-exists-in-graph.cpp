//  class Node
//  {
//    public: 
//    int vertex; 
//    Node* next; 
//    Node()
//    {
//     next=NULL;
//    } 
//    Node(int x)
//    {
//     vertex=x; 
//     next=NULL;
//    }
//  };
//  class Solution {
// public: 
//       Node*head;
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
//     { 

//         head=new Node[n]; 
//         for(int i=0;i<n;i++)
//         {
//             head[i]=NULL;
//         }
        
      
//         for(const auto&edge:edges)
//         {
//             int u=edge[0]; 
//             int v=edge[1]; 
//             pass(u,v); 
//             pass(v,u);
//         } 

//         int* visited; 
//         visited=new int[n]{0}; 


        
//      void dfs_rec(int*visited,int V)
//      {
//         // cout<<source; 
//         visited[V]=1; 
         
//          Node* T=head[V]; 
//          while(T!=NULL)
//          {
//             for(int i=0;i<n;i++)
//             {
//                 if(visited[i]==0)
//                 {
//                     dfs_rec(visited,T->vertex);
//                 }
//             } 
//             T=T->next;
//          }
//      } 

//      void pass(int u,int v)
//      {
//       if(head[u]==NULL)
//             {
//                 head[u]=new Node(v); 
//             } 
//             else 
//             {
//                 Node* p=new Node(u); 
//                 while(p->next!=NULL)
//                 {
//                     p=p->next
//                 } 
//                 p->next=new Node(v);
//             }
//      }

// }; 

class Node {
public:
    int vertex;
    Node* next;

    // Constructor for initializing the node
    Node(int x) {
        vertex = x;
        next = NULL;
    }
};

class Solution {
public:
    Node** head;  // Array of linked list heads

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Initialize the array of linked list heads
        head = new Node*[n];
        for (int i = 0; i < n; i++) {
            head[i] = NULL;
        }

        // Step 2: Populate the adjacency list using the edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            addEdge(u, v);  // Add v to u's list
            addEdge(v, u);  // Add u to v's list (since the graph is bi-directional)
        }

        // Step 3: Initialize visited array
        int* visited = new int[n]{0};

        // Step 4: Perform DFS from the source node
        dfs_rec(visited, source);

        // Step 5: Check if the destination was visited
        bool pathExists = visited[destination] == 1;

        // Clean up allocated memory
        delete[] visited;
        for (int i = 0; i < n; ++i) {
            Node* current = head[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] head;

        return pathExists;
    }

private:
    // DFS traversal using recursion
    void dfs_rec(int* visited, int V) {
        visited[V] = 1;  // Mark the current node as visited

        Node* temp = head[V];  // Get the head of the linked list for vertex V
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (visited[neighbor] == 0) {
                dfs_rec(visited, neighbor);  // Visit the neighbor recursively
            }
            temp = temp->next;  // Move to the next neighbor
        }
    }

    // Function to add an edge to the adjacency list
    void addEdge(int u, int v) {
        Node* newNode = new Node(v);  // Create a new node for vertex v
        newNode->next = head[u];  // Insert the new node at the beginning of the list
        head[u] = newNode;  // Update the head of the list
    }
};
