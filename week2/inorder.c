#include <stdio.h>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
//review this
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}   

void inorder(struct TreeNode* root, int* index, int* result) {
    if (root == NULL) return;

    inorder(root->left, index, result);
    result[*index] = root->val;
    (*index)++;
    inorder(root->right, index, result);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* result = malloc(sizeof(int) * (*returnSize));

    int index = 0;
    inorder(root, &index, result);

    return result;
}


int main(void){

}
