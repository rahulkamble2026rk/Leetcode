class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        vector<vector<Node*>> store;
        traverse_store(root, store);
        connect_levels(store);
        return root;
    }

    void traverse_store(Node* root, vector<vector<Node*>>& store) {
        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<Node*> level;

            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                level.push_back(node);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            store.push_back(level);
        }
    }

    void connect_levels(vector<vector<Node*>>& store) {
        for (auto& level : store) {
            for (int i = 0; i < level.size() - 1; ++i) {
                level[i]->next = level[i + 1];
            }
            level.back()->next = NULL; // Last node in level
        }
    }
};
