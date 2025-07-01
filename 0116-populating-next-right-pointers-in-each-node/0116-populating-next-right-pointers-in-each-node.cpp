class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        vector<vector<Node*>> store;
        traverse_store(root, store);

        change(store);
        return root;
    }

    void traverse_store(Node* root, vector<vector<Node*>>& store) {
        queue<Node*> que1;
        queue<Node*> que2;
        vector<Node*> level;

        que1.push(root);

        do {
            while (!que1.empty()) {
                Node* temp = que1.front();
                que1.pop();

                level.push_back(temp);

                if (temp->left != NULL) que2.push(temp->left);
                if (temp->right != NULL) que2.push(temp->right);
            }

            store.push_back(level);
            level.clear();
            swap(que1, que2);
        } while (!que1.empty());
    }

    void change(vector<vector<Node*>>& store) {
        for (auto& level : store) {
            for (int i = 0; i < level.size() - 1; ++i) {
                level[i]->next = level[i + 1];
            }
            level.back()->next = NULL;
        }
    }
};
