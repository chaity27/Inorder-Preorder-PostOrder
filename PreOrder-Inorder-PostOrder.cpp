#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> nodeStack;
    Node* currentNode = root;

    while (currentNode != NULL || !nodeStack.empty()) {
        while (currentNode != NULL) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }

        currentNode = nodeStack.top();
        nodeStack.pop();

        cout << currentNode->data << " ";

        currentNode = currentNode->right;
    }
}

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* currentNode = nodeStack.top();
        nodeStack.pop();

        cout << currentNode->data << " ";

        if (currentNode->right)
            nodeStack.push(currentNode->right);
        if (currentNode->left)
            nodeStack.push(currentNode->left);
    }
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> nodeStack;
    Node* currentNode = root;
    stack<int> resultStack;

    while (currentNode != NULL || !nodeStack.empty()) {
        if (currentNode != NULL) {
            nodeStack.push(currentNode);
            resultStack.push(currentNode->data);
            currentNode = currentNode->right;
        } else {
            currentNode = nodeStack.top();
            nodeStack.pop();
            currentNode = currentNode->left;
        }
    }

    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
}

int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
