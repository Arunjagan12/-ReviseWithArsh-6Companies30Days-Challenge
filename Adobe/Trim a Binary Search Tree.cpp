class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if (root == nullptr) {
            return nullptr;
        }

        // If the current node is outside the range [low, high], trim it
        if (root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        // Otherwise, recursively trim the left and right subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;  
    }
};