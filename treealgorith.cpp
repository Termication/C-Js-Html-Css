#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void printTree(Node* root){
    if (root == nullptr) return;

    cout << root->data << endl;
    printTree(root->left);
    printTree(root->right);
}
int main(){
    Node* root=createNode(1);
    
    root->left = createNode(1);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);
    printTree(root);
}