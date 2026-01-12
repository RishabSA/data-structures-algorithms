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

class BSTNode {
public:
    int current;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;

    BSTNode(int val) {
        current = val;
    }

    BSTNode() = default;

    friend std::ostream& operator<<(std::ostream& os, const BSTNode& obj) {
        os << "BSTNode(current = " << obj.current << ")";
        return os;
    }
};

class BST {
public:
    BSTNode* root = nullptr;

    BST(int val) {
        root = new BSTNode(val);
    };

    BST() = default;

    void insert(std::vector<int> vals) {
        for (int val : vals) {
            insert(val);
        }
    }

    void insert(int val) {
        if (root == nullptr) {
            root = new BSTNode(val);
            return;
        }

        insert(root, val);
    };

    void insert(BSTNode* currentNode, int val) {
        if (val < currentNode->current) {
            if (currentNode->left == nullptr) {
                currentNode->left = new BSTNode(val);
                return;
            }
            
            insert(currentNode->left, val);
        } else {
            if (currentNode->right == nullptr) {
                currentNode->right = new BSTNode(val);
                return;
            }

            insert(currentNode->right, val);
        }
    };

    void inOrderTraversal() {
        // left, current, right
        if (root == nullptr) return;
        
        std::cout << "In Order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    };

    void inOrderTraversal(BSTNode* currentNode) {
        if (currentNode->left != nullptr) {
            inOrderTraversal(currentNode->left);
        }

        std::cout << currentNode->current << ", ";

        if (currentNode->right != nullptr) {
            inOrderTraversal(currentNode->right);
        }
    };

    void preOrderTraversal() {
        // current, left, right
        if (root == nullptr) return;
        
        std::cout << "Pre Order Traversal: ";
        preOrderTraversal(root);
        std::cout << std::endl;
    };

    void preOrderTraversal(BSTNode* currentNode) {
        std::cout << currentNode->current << ", ";
        
        if (currentNode->left != nullptr) {
            preOrderTraversal(currentNode->left);
        }

        if (currentNode->right != nullptr) {
            preOrderTraversal(currentNode->right);
        }
    };

    void postOrderTraversal() {
        // left, right, current
        if (root == nullptr) return;
        
        std::cout << "Post Order Traversal: ";
        postOrderTraversal(root);
        std::cout << std::endl;
    };

    void postOrderTraversal(BSTNode* currentNode) {
        if (currentNode->left != nullptr) {
            postOrderTraversal(currentNode->left);
        }

        if (currentNode->right != nullptr) {
            postOrderTraversal(currentNode->right);
        }

        std::cout << currentNode->current << ", ";
    };

    BSTNode* search(int val) {
        if (root == nullptr) return nullptr;

        return search(val, root);
    };

    BSTNode* search(int val, BSTNode* currentNode) {
        if (val == currentNode->current) return currentNode;

        if (val < currentNode->current && currentNode->left) {
            return search(val, currentNode->left);
        } else if (val > currentNode->current && currentNode->right) {
            return search(val, currentNode->right);
        }

        return nullptr;
    };

    BSTNode* remove(int val) {
        // If the node we are trying to remove is a child (none of its own children), just remove it
        // If the node we are trying to remove has one child, remove the node and make the parent node have this child as its own child in the same left or right
        // If the node we are trying to remove has two children, take the smallest child in the right subtree (by traversing and fully going left on the right subtree till there is no more left child) and make it the new parent replacing the deleted node, so that this way everything is already properly balanced

        if (root == nullptr) return nullptr;

        return remove(val, root, nullptr, false);
    };

    BSTNode* remove(int val, BSTNode* currentNode, BSTNode* parentNode, bool childIsParentLeft) {
        // Traverse postorder: left, right, current

        if (val < currentNode->current && currentNode->left) {
            return remove(val, currentNode->left, currentNode, true);
        } else if (val > currentNode->current && currentNode->right) {
            return remove(val, currentNode->right, currentNode, false);
        } else {
            // Found the node to delete
            if (currentNode->left == nullptr and currentNode->right == nullptr) {
                if (childIsParentLeft) parentNode->left = nullptr;
                else parentNode->right = nullptr;
                
                delete currentNode;
            } else if (currentNode->right == nullptr) {
                // Left child exists
                if (childIsParentLeft) parentNode->left = currentNode->left;
                else parentNode->right = currentNode->left;
                
                delete currentNode;
            } else if (currentNode->left == nullptr) {
                // Right child exists
                if (childIsParentLeft) parentNode->left = currentNode->right;
                else parentNode->right = currentNode->right;
                
                delete currentNode;
            } else {
                // Both children exist

            }
        }

        return nullptr;
    };

    BSTNode* getMin() {
        if (root == nullptr) return nullptr;

        return getMin(root);
    };

    BSTNode* getMin(BSTNode* currentNode) {
        if (currentNode->left) return getMin(currentNode->left);

        return currentNode;
    };

    BSTNode* getMax() {
        if (root == nullptr) return 0;

        return getMax(root);
    };

    BSTNode* getMax(BSTNode* currentNode) {
        if (currentNode->right) return getMax(currentNode->right);

        return currentNode;
    };
};

int main() {
    BST bst = BST(5);

    // Insertion
    bst.insert({10, -5, 20, 1, -1, -7, 6});

    // Traversals
    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    // Searching
    std::cout << "BST Searching for -1: " << *bst.search(-1) << std::endl;
    std::cout << "BST Searching for 6: " << *bst.search(6) << std::endl;
    std::cout << "BST Searching for 67: " << bst.search(67) << std::endl;

    std::cout << std::endl;

    std::cout << "Minimum node value: " << bst.getMin()->current << std::endl;
    std::cout << "Maximum node value: " << bst.getMax()->current << std::endl;

    return 0;
}