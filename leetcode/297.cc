/*
 * It's a design problem, whatever implements match the need is OK
 */
class Codec {
public:
    vector<string> Split(string s, char delim=',') {
        vector<string> result;
        istringstream ss(s);
        string element;
        while (getline(ss, element, delim)) {
            result.push_back(element);
        }
        return result;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if (top == nullptr) {
                result += ",null";
            }
            else {
                result += ("," + to_string(top->val));
                q.push(top->left);
                q.push(top->right);
            }
        }
        return result.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elements = Split(data);
        vector<TreeNode*> nodes(elements.size(), nullptr);
        int i = 0, j = 1;
        while (i < elements.size() && j < elements.size()) {
            if (elements[i] != "null") {
                if (nodes[i] == nullptr) {
                    nodes[i] = new TreeNode(stoi(elements[i]));
                }
                if (elements[j] != "null") {
                    nodes[j] = new TreeNode(stoi(elements[j]));
                }
                if (elements[j + 1] != "null") {
                    nodes[j + 1] = new TreeNode(stoi(elements[j + 1]));
                }
                nodes[i]->left = nodes[j];
                nodes[i]->right = nodes[j + 1];
                j += 2;
            }
            ++i;
        }
        if (elements.size() == 0) return nullptr;
        else return nodes[0];
    }
};
