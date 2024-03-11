#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

// Node structure for AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;  // new node is initially added at leaf
    return node;
}

// Function to get the height of the tree
int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node N
int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Function to insert a key in the subtree rooted with node and returns the new root of the subtree.
Node* insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  // Equal keys are not allowed in BST
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Function to search a key in the subtree rooted with node and returns the node if found, nullptr otherwise.
Node* search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

int main() {
    srand(time(0)); // Khởi tạo bộ sinh số ngẫu nhiên
    std::vector<int> data; // Tạo một vector để lưu trữ dữ liệu

    // Sinh 10 số ngẫu nhiên trong khoảng từ 1 đến 100
    for (int i = 0; i < 10000; ++i) {
        int num = rand() % 10000 + 1; // Sinh số ngẫu nhiên
        data.push_back(num); // Thêm số vào vector
    }

    // In ra các số đã sinh
    for (int num : data) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // Xây dựng cây AVL từ tập dữ liệu
    Node* root = nullptr;
    for (int num : data) {
        root = insert(root, num);
    }

    // Sinh một số ngẫu nhiên và đo thời gian tìm kiếm số này trên cây AVL
    int search_num = 50; // Sinh số ngẫu nhiên
    auto start = std::chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
    Node* result = search(root, search_num); // Tìm kiếm số trên cây AVL
    auto end = std::chrono::high_resolution_clock::now(); // Kết thúc đo thời gian
    std::chrono::duration<double, std::milli> elapsed = end - start; // Tính thời gian đã trôi qua

    // In ra kết quả tìm kiếm và thời gian thực thi
    if (result != nullptr) {
        std::cout << "Found " << search_num << " in the AVL tree.\n";
    } else {
        std::cout << "Did not find " << search_num << " in the AVL tree.\n";
    }
    std::cout << "Search time: " << elapsed.count() << " milliseconds.\n";

    return 0;
}

