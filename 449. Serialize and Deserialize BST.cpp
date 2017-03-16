/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        res += 'b';
        int v = root->val;
        if (root->right) { res += this->serialize(root->right) + 'r'; }
        if (root->left) { res += this->serialize(root->left) + 'l'; }
        res += to_string(v);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        if (!len) return nullptr;
        return helper(data, len);
    }
    
    TreeNode *helper(string &data, int &len) {
        int numLen = 0;
        for (int pos = len - 1; 0 <= pos; --pos) {
            if (('0' <= data[pos] && data[pos] <= '9') || data[pos] == '-') ++numLen;
            else break;
        }
        int v = stoi(data.substr(len - numLen, numLen));
        TreeNode *aNode = new TreeNode(v);
        len -= numLen;
        if (data[len-1] == 'l') { len--; aNode->left = this->helper(data, len); }
        if (data[len-1] == 'r') { len--; aNode->right = this->helper(data, len); }
        if (data[len-1] == 'b') { len--; return aNode; }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
