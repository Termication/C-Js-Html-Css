#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;

    printTree(root->right);
    std::cout << root->data << " ";
    printTree(root->left);
    
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = createNode(1);
    
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8);
    root->right->right->left = createNode(9);

    std::cout << "Binary Tree elements: ";
    printTree(root);
    std::cout << std::endl;

    // Don't forget to delete the allocated memory
    deleteTree(root);

    return 0;
}
