#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return bst(preorder, 0, preorder.size() - 1);
  }

  TreeNode* bst(const vector<int>& p, int l, int r) {
    if (r >= p.size() || l > r) return nullptr;
    TreeNode* root = new TreeNode(p[l]);

    int k = l + 1;
    for (; k <= r && p[l] > p[k]; k++);

    root->left = bst(p, l + 1, k - 1);
    root->right = bst(p, k, r);

    return root;
  }
};
