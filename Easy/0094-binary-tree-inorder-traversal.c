int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1;
    int count = 0;
    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        result[count++] = curr->val;
        curr = curr->right;
    }

    *returnSize = count;
    return result;
}
