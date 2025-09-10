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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh = findlh(root);
        int rh = findrh(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

      int findlh(TreeNode * root){
        int hght=0;
        while(root){
            hght++;
            root=root->left;
        }
        return hght;
      }

      int findrh(TreeNode * root){
        int hght=0;
        while(root){
            hght++;
            root=root->right;
        }
        return hght;
      }
};