#include <iostream>

/*
Notes:

A binary search tree (BST) is a data structure where each node has at most two children, with the left child being less than the parent and the right child being greater than the parent. 

Access/search by key: O(log N)
Insert: O(log N)
Delete: O(log N)
Find min/max: O(log N)
Traversal (inorder/preorder/postorder): O(N)
Height computation: O(N)
*/

class Node {
public:
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int v) {
        value = v;
    };

    Node() = default;
};

class BST {
public:
    Node* root = nullptr;
    int count = 0;

    BST(int v) {
        root = new Node(v);
    };

    BST() = default;

    // O(log N)
    Node* add(int val) {
        if (root == nullptr) {
            root = new Node(val); 
            count++;

            return root;
        }

        return add(val, root);
    };

    void printAll() {
        if (root == nullptr) return;

        printAll(root);
    };

    void printAll(Node* currrentNode) {
        std::cout << currrentNode->value << std::endl;

        if (currrentNode->left != nullptr) {
            printAll(currrentNode->left);
        }
        
        if (currrentNode->right != nullptr) {
            printAll(currrentNode->right);
        }
    };

    Node* add(int val, Node* currentNode) {
        if (val < currentNode->value) {
            if (currentNode->left == nullptr) {
                Node* newNode = new Node(val);
                currentNode->left = newNode;
                count++;

                return newNode;
            } else {
                return add(val, currentNode->left);
            }
        } else {
            if (currentNode->right == nullptr) {
                Node* newNode = new Node(val);
                currentNode->right = newNode;
                count++;

                return newNode;
            } else {
                return add(val, currentNode->right);
            }
        }
    };

    Node* find(int val) {
        if (root == nullptr) return nullptr;

        return find(val, root);
    };

    Node* find(int val, Node* currentNode) {
        if (currentNode->value == val) return currentNode;

        if (val < currentNode->value) {
            return find(val, currentNode->left);
        } else if (val >= currentNode->value) {
            return find(val, currentNode->right);
        }

        return nullptr;
    };

    Node* getMin() {
        if (root == nullptr) return nullptr;

        return getMin(root);
    };

    Node* getMin(Node* currentNode) {
        if (currentNode->left != nullptr) return getMin(currentNode->left);

        return currentNode;
    };

    Node* getMax() {
        if (root == nullptr) return 0;

        return getMax(root);
    };

    Node* getMax(Node* currentNode) {
        if (currentNode->right != nullptr) return getMax(currentNode->right);

        return currentNode;
    };
};

int main() {
    BST tree = BST(5);
    tree.add(3);
    tree.add(7);
    tree.add(10);
    tree.add(1);
    tree.add(17);

    std::cout << "All nodes in BST:" << std::endl;
    tree.printAll();

    std::cout << std::endl;

    std::cout << "Node with value 7: " << tree.find(7)->value << std::endl; 

    std::cout << std::endl;

    std::cout << "Minimum node value: " << tree.getMin()->value << std::endl;
    std::cout << "Maximum node value: " << tree.getMax()->value << std::endl;

    return 0;
}