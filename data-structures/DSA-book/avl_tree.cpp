#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <stack>

template <typename T>
class Node {
public:
    // Getters
    T getValue() { return value; }
    Node<T> *getLeft() { return left; }
    Node<T> *getRight() { return right; }
    int getHeight() { return height; }

    // Setters
    void setValue(T val) { value = val; }
    void setLeft(Node<T> *l) { left = l; }
    void setRight(Node<T> *r) { right = r; }
    void setHeight(int h) { height = h; }

private:
    T value{};
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    int height = 1;
};

template <typename T>
class AVL {
public:
    void destroy(Node<T>* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        destroy(currentNode->getLeft());
        destroy(currentNode->getRight());

        delete currentNode;
    }

    AVL() {
        // An AVL tree is a BST with a self-balancing condition
        // The diﬀerence between the height of the left and right subtrees cannot be no more than one

        // Worst case of all operations of BST is O(N)
        // Worst case of all operations of AVL is O(log(N))

        root = nullptr;
        treeLength = 0;
    };

    ~AVL() {
        destroy(root);
    }

    int getTreeLength() { return treeLength; }

    void PrintTree() {
        if (root != nullptr) {
            PrintTree(root);
        }
    };

    void PrintTree(Node<T> *currentNode) {
        // Printed format:
        // Node <value> has children left: <value_left> and right: <value_right>

        std::cout << "Node " << currentNode->getValue();

        if ((currentNode->getLeft() != nullptr) || (currentNode->getRight() != nullptr)) {
            std::cout << " has children";
            if (currentNode->getLeft() != nullptr) {
                std::cout << " left: " << currentNode->getLeft()->getValue();
            }

            if (currentNode->getRight() != nullptr) {
                std::cout << " right: " << currentNode->getRight()->getValue();
            }
        } else {
            std::cout << " has no children.";
        }
        std::cout << "\n";

        if (currentNode->getLeft() != nullptr) {
            PrintTree(currentNode->getLeft());
        }

        if (currentNode->getRight() != nullptr) {
            PrintTree(currentNode->getRight());
        }
    };

    void PreOrder() {
        if (root != nullptr) {
            PreOrder(root);
            std::cout << "\n";
        }
    };

    // PreOrder Traversal
    // O(N)
    void PreOrder(Node<T> *currentNode) {
        if (currentNode != nullptr) {
            std::cout << "Value: " << currentNode->getValue() << "\n";
            PreOrder(currentNode->getLeft());
            PreOrder(currentNode->getRight());
        }
    };

    void PostOrder() {
        if (root != nullptr) {
            PostOrder(root);
            std::cout << "\n";
        }
    };

    // PostOrder Traversal
    // O(N)
    void PostOrder(Node<T> *currentNode) {
        if (currentNode != nullptr) {
            PostOrder(currentNode->getLeft());
            PostOrder(currentNode->getRight());
            std::cout << "Value: " << currentNode->getValue() << "\n";
        }
    };

    void InOrder() {
        if (root != nullptr) {
            InOrder(root);
            std::cout << "\n";
        }
    };

    // InOrder Traversal
    // O(N)
    void InOrder(Node<T> *currentNode) {
        if (currentNode != nullptr) {
            InOrder(currentNode->getLeft());
            std::cout << "Value: " << currentNode->getValue() << "\n";
            InOrder(currentNode->getRight());
        }
    };

    // Breadth First Traversal
    // O(N)
    void BreadthFirst() {
        if (root != nullptr) {
            std::queue<Node<T>*> queue;
            Node<T> *currentNode = root;

            while (currentNode != nullptr) {
                std::cout << "Value: " << currentNode->getValue() << "\n";

                if (currentNode->getLeft() != nullptr) {
                    queue.push(currentNode->getLeft());
                }

                if (currentNode->getRight() != nullptr) {
                    queue.push(currentNode->getRight());
                }

                if (queue.size() != 0) {
                    currentNode = queue.front();
                    queue.pop();
                } else {
                    currentNode = nullptr;
                }
            }
            std::cout << "\n";
        }
    };

    int NodeHeight(Node<T> *currentNode) {
        if (currentNode == nullptr) {
            return 0;
        }

        return currentNode->getHeight();
    };

    // Symmetric Left Rotation
    // O(1)
    void LeftRotation(Node<T> *currentNode) {
        if (currentNode->getRight() != nullptr) {
            Node<T> *rightNode = currentNode->getRight();
            currentNode->setRight(rightNode->getLeft());
            rightNode->setLeft(currentNode);

            currentNode->setHeight(1 + std::max(NodeHeight(currentNode->getLeft()), NodeHeight(currentNode->getRight())));
            rightNode->setHeight(1 + std::max(NodeHeight(rightNode->getLeft()), NodeHeight(rightNode->getRight())));
        }
    };

    // Symmetric Right Rotation
    // O(1)
    void RightRotation(Node<T> *currentNode) {
        if (currentNode->getLeft() != nullptr) {
            Node<T> *leftNode = currentNode->getLeft();
            currentNode->setLeft(leftNode->getRight());
            leftNode->setRight(currentNode);

            currentNode->setHeight(1 + std::max(NodeHeight(currentNode->getLeft()), NodeHeight(currentNode->getRight())));
            leftNode->setHeight(1 + std::max(NodeHeight(leftNode->getLeft()), NodeHeight(leftNode->getRight())));
        }
    };

    void CheckBalance(Node<T> *currentNode) {
        if (currentNode->getLeft() == nullptr && currentNode->getRight() == nullptr) {
            currentNode->setHeight(-1);
        } else {
            currentNode->setHeight(1 + std::max(NodeHeight(currentNode->getLeft()), NodeHeight(currentNode->getRight())));
        }

        if (NodeHeight(currentNode->getLeft()) - NodeHeight(currentNode->getRight()) > 1) {
            if (NodeHeight(currentNode->getLeft()->getLeft()) - NodeHeight(currentNode->getLeft()->getRight()) > 0) {
                RightRotation(currentNode);
            } else {
                LeftRotation(currentNode);
                RightRotation(currentNode);
            }
        } else if (NodeHeight(currentNode->getLeft()) - NodeHeight(currentNode->getRight()) < -1) {
            if (NodeHeight(currentNode->getRight()->getLeft()) - NodeHeight(currentNode->getRight()->getRight()) < 0) {
                LeftRotation(currentNode);
            } else {
                RightRotation(currentNode);
                LeftRotation(currentNode);
            }
        }
    };

    void Insert(T newVal) {
        if (root == nullptr) {
            root = new Node<T>();
            root->setValue(newVal);
        } else {
            InsertNode(root, newVal);
        }

        treeLength++;
    };

    // Recursively find the proper leaf node and insert the new node
    // O(log(N))
    void InsertNode(Node<T> *currentNode, T newVal) {
        if (newVal < currentNode->getValue()) {
            if (currentNode->getLeft() == nullptr) {
                Node<T> *newNode = new Node<T>();
                newNode->setValue(newVal);

                currentNode->setLeft(newNode);
            } else {
                InsertNode(currentNode->getLeft(), newVal);
            }
        } else {
            if (currentNode->getRight() == nullptr) {
                Node<T> *newNode = new Node<T>();
                newNode->setValue(newVal);

                currentNode->setRight(newNode);
            } else {
                InsertNode(currentNode->getRight(), newVal);
            }
        }

        // Balance the AVL Tree to have left and right subtrees be similar in height
        CheckBalance(currentNode);
    }

    // Return a pointer to the node that has the value
    Node<T> *Search(T value) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->getValue() == value) {
            return root;
        } else {
            return Search(root, value);
        }
    };

    // O(log(N))
    Node<T> *Search(Node<T> *currentNode, T value) {
        if (currentNode->getValue() == value) {
            return currentNode;
        }
        
        // If leaf, return nullptr
        if (currentNode->getLeft() == nullptr && currentNode->getRight() == nullptr) {
            return nullptr;
        }

        if (currentNode->getLeft() != nullptr && currentNode->getValue() > value) {
            return Search(currentNode->getLeft(), value);
        } else if (currentNode->getRight() != nullptr && currentNode->getValue() < value) {
            return Search(currentNode->getRight(), value);
        }

        return nullptr;
    };

    // Return a pointer to the parent of the node that has the value
    Node<T> *FindParent(T value) {
        if (root == nullptr) {
            return nullptr;
        } else {
            return FindParent(root, value);
        }
    };

    Node<T> *FindParent(Node<T> *currentNode, T value) {
        if (value < currentNode->getValue()) {
            if (currentNode->getLeft() == nullptr) {
                return nullptr;
            } else if (currentNode->getLeft()->getValue() == value) {
                return currentNode;
            } else {
                return FindParent(currentNode->getLeft(), value);
            }
        } else {
            if (currentNode->getRight() == nullptr) {
                return nullptr;
            } else if (currentNode->getRight()->getValue() == value) {
                return currentNode;
            } else {
                return FindParent(currentNode->getRight(), value);
            }
        }
    };

    Node<T> *FindMin() {
        if (root == nullptr) {
            return nullptr;
        } else {
            return FindMin(root);
        }
    };

    Node<T> *FindMin(Node<T> *currentNode) {
        if (currentNode->getLeft() == nullptr) {
            return currentNode;
        } else {
            return FindMin(currentNode->getLeft());
        }
    };

    Node<T> *FindMax() {
        if (root == nullptr) {
            return nullptr;
        } else {
            return FindMax(root);
        }
    };

    Node<T> *FindMax(Node<T> *currentNode) {
        if (currentNode->getRight() == nullptr) {
            return currentNode;
        } else {
            return FindMax(currentNode->getRight());
        }
    };

    int FindMaxDepth() {
        if (root == nullptr) {
            return 0;
        } else {
            return FindMaxDepth(root);
        }
    };

    int FindMaxDepth(Node<T> *currentNode) {
        if (currentNode == nullptr) return 0;

        return 1 + std::max(FindMaxDepth(currentNode->getLeft()), FindMaxDepth(currentNode->getRight()));
    };

    int FindMinDepth() {
        if (root == nullptr) {
            return 0;
        } else {
            return FindMinDepth(root);
        }
    };

    int FindMinDepth(Node<T> *currentNode) {
        if (currentNode == nullptr)
            return 0;
        else if (currentNode->getLeft() == nullptr) {
            return 1 + FindMinDepth(currentNode->getRight());
        } else if (currentNode->getRight() == nullptr) {
            return 1 + FindMinDepth(currentNode->getLeft());
        } else {
            return 1 + std::min(FindMinDepth(currentNode->getLeft()), FindMinDepth(currentNode->getRight()));
        }
    };

    // Delete the node with value and re-order the tree
    // O(log(N))
    bool Remove(T value) {
        if (root == nullptr) {
            return false;
        }

        std::stack<Node<T>*> path;
        Node<T>* nodeToRemove = root;
        Node<T> *parent = nullptr;

        while (nodeToRemove != nullptr && nodeToRemove->getValue() != value) {
            path.push(nodeToRemove);
            parent = nodeToRemove;

            if (value < nodeToRemove->getValue()) {
                nodeToRemove = nodeToRemove->getLeft();
            } else { 
                nodeToRemove = nodeToRemove->getRight();
            }
        }

        if (nodeToRemove == nullptr) {
            return false;
        }
        
        if (getTreeLength() == 1) {
            root = nullptr;
            treeLength--;
            return true;
        }

        if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() == nullptr) {
            // Case 1. the value to remove is a leaf node

            if (nodeToRemove->getValue() < parent->getValue()) {
                parent->setLeft(nullptr);
            } else {
                parent->setRight(nullptr);
            }
        } else if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() != nullptr) {
            // Case 2. the value to remove has a right subtree, but no left subtree

            if (nodeToRemove->getValue() < parent->getValue()) {
                parent->setLeft(nodeToRemove->getRight());
            } else {
                parent->setRight(nodeToRemove->getRight());
            }
        } else if (nodeToRemove->getRight() == nullptr && nodeToRemove->getLeft() != nullptr) {
            // Case 3. the value to remove has a left subtree, but no right subtree

            if (nodeToRemove->getValue() < parent->getValue()) {
                parent->setLeft(nodeToRemove->getLeft());
            } else {
                parent->setRight(nodeToRemove->getLeft());
            }
        } else {
            // Case 4. the value to remove has both a left and right subtree, so we promote the largest value in the left subtree.

            // Find the largest value in the left subtree
            Node<T> *largestLeftValue = nodeToRemove->getLeft();
            while (largestLeftValue->getRight() != nullptr) {
                largestLeftValue = largestLeftValue->getRight();
            }

            // Set the right node of the parent of the largest value to empty
            FindParent(largestLeftValue->getValue())->setRight(nullptr);
            // Reassign the largest value as the new root
            nodeToRemove->setValue(largestLeftValue->getValue());
        }

        while (!path.empty()) {
            // Trackback to the root node check balance
            CheckBalance(path.top());
            path.pop();
        }

        treeLength--;
        return true;
    };

private:
    Node<T> *root;
    int treeLength;
};

int main() {
    // Define the range
    int min = -100;
    int max = 100;
    int size = 10;

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution
    std::uniform_int_distribution<> distrib(min, max);

    AVL<int> tree;

    int insertedValues[size];

    // Insertion
    std::cout << "Inserted: ";
    for (int i = 0; i < size; ++i) {
        int insertValue = distrib(gen);
        std::cout << insertValue << " ";
        tree.Insert(insertValue);
        insertedValues[i] = insertValue;
    }
    std::cout << "\n\n";

    tree.PrintTree();
    std::cout << "\n";

    for (int i = -100; i < 100; ++i) {
        // Search
        Node<int> *FoundNode = tree.Search(i);

        if (FoundNode != nullptr) {
            std::cout << "Found " << i << "\n";
        }

        // Find Parent
        Node<int> *ParentNode = tree.FindParent(i);

        if (ParentNode != nullptr) {
            std::cout << "Found Parent of " << i << " is: " << ParentNode->getValue() << "\n";
        }
    }
    std::cout << "\n";

    // Min and Max Values
    Node<int> *minimumNode = tree.FindMin();
    std::cout << "The minimum node in the tree has a value of: " << minimumNode->getValue() << "\n";

    Node<int> *maximumNode = tree.FindMax();
    std::cout << "The maximum node in the tree has a value of: " << maximumNode->getValue() << "\n";

    // Tree Length and Depth
    int treeLength = tree.getTreeLength();
    std::cout << "The tree has " << treeLength << " items." << "\n";

    int maxTreeDepth = tree.FindMaxDepth();
    std::cout << "The tree has a maximum depth of " << maxTreeDepth << "." << "\n";

    int minTreeDepth = tree.FindMinDepth();
    std::cout << "The tree has a minimum depth of " << minTreeDepth << "." << "\n\n";

    // Traversals
    std::cout << "Traversals:" << "\n\n";

    std::cout << "PreOrder Traversal:" << "\n";
    tree.PreOrder();

    std::cout << "PostOrder Traversal:" << "\n";
    tree.PostOrder();

    std::cout << "InOrder Traversal:" << "\n";
    tree.InOrder();

    std::cout << "BreadthFirst Traversal:" << "\n";
    tree.BreadthFirst();

    // Deletion
    if (tree.Remove(insertedValues[0])) {
        std::cout << "Successfully removed " << insertedValues[0] << "\n";
    } else {
        std::cout << "Failed to remove " << insertedValues[0] << "\n";
    }

    if (tree.Remove(insertedValues[3])) {
        std::cout << "Successfully removed " << insertedValues[3] << "\n";
    } else {
        std::cout << "Failed to remove " << insertedValues[3] << "\n";
    }

    if (tree.Remove(max + 5)) {
        std::cout << "Successfully removed " << max + 5 << "\n";
    } else {
        std::cout << "Failed to remove " << max + 5 << "\n";
    }

    // Tree Length and Depth
    treeLength = tree.getTreeLength();
    std::cout << "The tree has " << treeLength << " items." << "\n";

    maxTreeDepth = tree.FindMaxDepth();
    std::cout << "The tree has a maximum depth of " << maxTreeDepth << "." << "\n";

    minTreeDepth = tree.FindMinDepth();
    std::cout << "The tree has a minimum depth of " << minTreeDepth << "." << "\n\n";

    tree.PrintTree();

    return 0;
}