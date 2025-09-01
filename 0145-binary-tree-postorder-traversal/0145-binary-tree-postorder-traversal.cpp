/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void  Postorder(TreeNode* root, vector<int> &arr){
        if(root==nullptr) return;
        Postorder(root->left,arr);
        Postorder(root->right,arr);
        arr.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;

        Postorder(root,arr);
        return arr;
    }
};