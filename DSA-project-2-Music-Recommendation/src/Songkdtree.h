#ifndef SONGKDTREE_H
#define SONGKDTREE_H
#include <iostream>
#include <array>
#include <cmath>
using namespace std;

template <size_t K>
class KDTree {
private:
    // Node structure representing each point in the KDTree
    struct Node {
        // Point in K dimensions
        array<double, K> point;
        // Pointer to left child
        Node* left;
        // Pointer to right child
        Node* right;

        // Constructor to initialize a Node
        Node(const array<double, K>& pt) : point(pt), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr; // Root of the KDTree


    // Recursive function to insert a point into the KDTree
    Node* insertRecursive(Node* node, const array<double, K>& point, int depth) {
        // Base case: If node is null, create a new node
        if (node == nullptr) return new Node(point);

        // Calculate current dimension (cd)
        int cd = depth % K;

        // Compare point with current node and decide to go left or right
        if (point[cd] < node->point[cd])
            node->left = insertRecursive(node->left, point, depth + 1);
        else
            node->right = insertRecursive(node->right, point, depth + 1);

        return node;
    }

    // Recursive function to search for a point in the KDTree
    bool searchRecursive(Node* node, const array<double, K>& point, int depth) const {
        // Base case: If node is null, the point is not found
        if (node == nullptr) return false;

        // If the current node matches the point, return true
        if (node->point == point) return true;

        // Calculate current dimension (cd)
        int cd = depth % K;

        // Compare point with current node and decide to go left or right
        if (point[cd] < node->point[cd])
            return searchRecursive(node->left, point, depth + 1);
        else
            return searchRecursive(node->right, point, depth + 1);
    }
    //Recursive memory cleanup
    void freeTree(Node* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:
    // Constructor to initialize the KDTree with a null root
    KDTree() : root(nullptr) {}
    //Destructor to prevent memory leaks
    ~KDTree() {
        freeTree(root);
    }
    // Public function to insert a point into the KDTree
    void insert(const array<double, K>& point) {
        root = insertRecursive(root, point, 0);
    }

    // Public function to search for a point in the KDTree
    bool search(const array<double, K>& point) const {
        return searchRecursive(root, point, 0);
    }
};

#endif //SONGKDTREE_H
