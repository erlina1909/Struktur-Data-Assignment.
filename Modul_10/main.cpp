#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

Node* buatNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Node* &root, int x) {
    if (root == NULL) {
        root = buatNode(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}

int jumlahNode(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + jumlahNode(root->left) + jumlahNode(root->right);
}

int totalInfo(Node* root) {
    if (root == NULL)
        return 0;
    return root->info + totalInfo(root->left) + totalInfo(root->right);
}

int kedalaman(Node* root) {
    if (root == NULL)
        return 0;

    int kiri = kedalaman(root->left);
    int kanan = kedalaman(root->right);

    if (kiri > kanan)
        return kiri + 1;
    else
        return kanan + 1;
}

int main() {
    cout << "Hello World" << endl;

    Node* root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); // duplikat, tidak masuk
    insertNode(root, 7);

    cout << "InOrder : ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder : ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    postOrder(root);
    cout << endl;

    cout << "kedalaman : " << kedalaman(root) << endl;
    cout << "jumlah node : " << jumlahNode(root) << endl;
    cout << "total : " << totalInfo(root) << endl;

    return 0;
}