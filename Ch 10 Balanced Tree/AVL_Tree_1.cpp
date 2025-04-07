#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// --------------------------------------------
// Node for AVL Tree
// --------------------------------------------
struct AVLNode {
    int key;             // The value stored in the node
    int height;          // Height of the node (used to keep balance)
    AVLNode* left;       // Pointer to left child
    AVLNode* right;      // Pointer to right child
    AVLNode* parent;     // Pointer to parent node (useful for upward traversal)

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

// --------------------------------------------
// AVL Tree Class
// --------------------------------------------
class AVLTree {
public:
    AVLNode* root = nullptr;

    // Public insert function
    void insert(int key) {
        if (!root) {
            // If the tree is empty, create the root node
            root = new AVLNode(key);
        } else {
            // Insert recursively and rebalance
            root = insertHelper(root, key);
        }
    }

    // In-order traversal to print the tree in sorted order
    void inOrderTraversal(AVLNode* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        cout << node->key << " ";
        inOrderTraversal(node->right);
    }

    AVLNode* getRoot() {
        return root;
    }

private:
    // --------------------------------------------
    // Recursive insert helper with balancing
    // --------------------------------------------
    AVLNode* insertHelper(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);  // Base case: create a new node

        if (key < node->key) {
            // Insert into left subtree
            AVLNode* leftChild = insertHelper(node->left, key);
            setChild(node, "left", leftChild);
        } else if (key > node->key) {
            // Insert into right subtree
            AVLNode* rightChild = insertHelper(node->right, key);
            setChild(node, "right", rightChild);
        } else {
            // Duplicate keys not allowed in BST
            return node;
        }

        // After inserting, rebalance this node to fix AVL property
        return rebalance(node);
    }

    // --------------------------------------------
    // Rotations for Rebalancing
    // --------------------------------------------

    // Left rotation: node is right-heavy and needs to rotate left
    void rotateLeft(AVLNode* node) {
        if (!node || !node->right) return;

        AVLNode* rightChild = node->right;
        AVLNode* rightLeftChild = rightChild->left;

        // Update the parent to point to the new root of the rotated subtree
        if (node->parent != nullptr) {
            replaceChild(node->parent, node, rightChild);
        } else {
            // node was root
            root = rightChild;
            root->parent = nullptr;
        }

        // Perform the actual rotation
        setChild(rightChild, "left", node);
        setChild(node, "right", rightLeftChild);

        // Update heights after rotation
        updateHeight(node);
        updateHeight(rightChild);
    }

    // Right rotation: node is left-heavy and needs to rotate right
    void rotateRight(AVLNode* node) {
        if (!node || !node->left) return;

        AVLNode* leftChild = node->left;
        AVLNode* leftRightChild = leftChild->right;

        if (node->parent != nullptr) {
            replaceChild(node->parent, node, leftChild);
        } else {
            // node was root
            root = leftChild;
            root->parent = nullptr;
        }

        // Perform the actual rotation
        setChild(leftChild, "right", node);
        setChild(node, "left", leftRightChild);

        // Update heights after rotation
        updateHeight(node);
        updateHeight(leftChild);
    }

    // --------------------------------------------
    // Rebalance Node
    // --------------------------------------------
    AVLNode* rebalance(AVLNode* node) {
        updateHeight(node);  // First, update the node's height

        int balance = getBalance(node);  // Check balance factor

        // Right-heavy case (balance factor -2)
        if (balance == -2) {
            if (getBalance(node->right) == 1) {
                // Right-Left case: double rotation
                rotateRight(node->right);
            }
            rotateLeft(node);
            return node->parent;
        }

        // Left-heavy case (balance factor +2)
        if (balance == 2) {
            if (getBalance(node->left) == -1) {
                // Left-Right case: double rotation
                rotateLeft(node->left);
            }
            rotateRight(node);
            return node->parent;
        }

        return node;  // Node is already balanced
    }

    // --------------------------------------------
    // Helper: Update Height of a Node
    // --------------------------------------------
    void updateHeight(AVLNode* node) {
        if (!node) return;
        int leftHeight = (node->left ? node->left->height : 0);
        int rightHeight = (node->right ? node->right->height : 0);
        node->height = max(leftHeight, rightHeight) + 1;
    }

    // --------------------------------------------
    // Helper: Compute Balance Factor
    // --------------------------------------------
    int getBalance(AVLNode* node) {
        if (!node) return 0;
        int leftHeight = (node->left ? node->left->height : 0);
        int rightHeight = (node->right ? node->right->height : 0);
        return leftHeight - rightHeight;  // Positive: left-heavy, Negative: right-heavy
    }

    // --------------------------------------------
    // Helper: Replace a child node with another
    // --------------------------------------------
    void replaceChild(AVLNode* parent, AVLNode* oldChild, AVLNode* newChild) {
        if (parent->left == oldChild) {
            parent->left = newChild;
        } else if (parent->right == oldChild) {
            parent->right = newChild;
        }

        if (newChild != nullptr) {
            newChild->parent = parent;  // Important: child knows who their parent is
        }
    }

    // --------------------------------------------
    // Helper: Set a left or right child and update back-pointer
    // --------------------------------------------
    void setChild(AVLNode* parent, const string& whichChild, AVLNode* child) {
        if (whichChild == "left") {
            parent->left = child;
        } else if (whichChild == "right") {
            parent->right = child;
        }

        if (child != nullptr) {
            child->parent = parent;  // Set back-pointer so child knows its parent
        }
    }
};

// --------------------------------------------
// Main: Test the AVL Tree
// --------------------------------------------
int main() {
    AVLTree tree;

    // Inserting nodes — tree will rebalance itself when needed
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);  // triggers Right Rotation
    tree.insert(25);  // triggers Left-Right Rotation
    tree.insert(40);
    tree.insert(50);  // triggers Left Rotation

    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.getRoot());
    cout << endl;

    return 0;
}
