#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else if (data == root->data ){
        cout << "Data sudah ada!"<<endl;
    }

    return root;
}

Node* cariNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return cariNode(root->left, data);
    }

    return cariNode(root->right, data);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int findMinValue(Node* root) {
    if (root == NULL) {
        cout << "Pohon kosong." << endl;
        return -1;
    }

    if (root->left == NULL) {
        return root->data;
    }

    return findMinValue(root->left);
}

int findMaxValue(Node* root) {
    if (root == NULL) {
        cout << "Pohon kosong." << endl;
        return -1;
    }

    if (root->right == NULL) {
        return root->data;
    }

    return findMaxValue(root->right);
}

void findChildren(Node* root, int data) {
    Node* node = cariNode(root, data);
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        cout << "Node tidak memiliki anak." << endl;
        return;
    }

    if (node->left != NULL) {
        cout << "Anak kiri: " << node->left->data << endl;
    } else {
        cout << "Anak kiri: Tidak ada anak" << endl;
    }

    if (node->right != NULL) {
        cout << "Anak kanan: " << node->right->data << endl;
    } else {
        cout << "Anak kanan: Tidak ada anak" << endl;
    }
}

int main() {
    Node* root = NULL;

    cout << "Masukkan node ke dalam pohon (-1 untuk berhenti):" << endl;
    int data;
    while (true) {
        cout << "Masukkan data: ";
        cin >> data;
        if (data == -1) {
            break;
        }
        root = insertNode(root, data);
    }

    cout << "Kunjungan Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Kunjungan Preorder: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Kunjungan Postorder: ";
    postorderTraversal(root);
    cout << endl;

    int searchData;
    cout << "Masukkan data yang ingin dicari: ";
    cin >> searchData;
    Node* searchResult = cariNode(root, searchData);
    if (searchResult != NULL) {
        cout << searchData << " ditemukan dalam pohon." << endl;
    } else {
        cout << searchData << " tidak ditemukan dalam pohon." << endl;
    }

    int jumlahNode = countNodes(root);
    cout << "Jumlah node dalam pohon: " << jumlahNode << endl;

    int tinggi = treeHeight(root);
    cout << "Tinggi pohon: " << tinggi << endl;

    int nilaiMinimum = findMinValue(root);
    if (nilaiMinimum != -1) {
        cout << "Nilai minimum dalam pohon: " << nilaiMinimum << endl;
    }

    int nilaiMaksimum = findMaxValue(root);
    if (nilaiMaksimum != -1) {
        cout << "Nilai maksimum dalam pohon: " << nilaiMaksimum << endl;
    }

    int dataDenganAnak;
    cout << "Masukkan data node yang ingin diketahui anak-anaknya: ";
    cin >> dataDenganAnak;
    findChildren(root, dataDenganAnak);

    return 0;
}