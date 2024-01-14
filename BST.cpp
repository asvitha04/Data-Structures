#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int val) : left(nullptr), right(nullptr), data(val) {}

    Node(const Node& other) : left(nullptr), right(nullptr), data(other.data) {
        if (other.left) {
            left = new Node(*other.left);
        }
        if (other.right) {
            right = new Node(*other.right);
        }
    }

    Node& operator=(const Node& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }

        data = other.data;

        if (other.left) {
            left = new Node(*other.left);
        }
        if (other.right) {
            right = new Node(*other.right);
        }

        return *this;
    }

    ~Node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};


Node* insert_data(Node *root, int val) {
    if (!root) {
        return (new Node(val));
    }
    if (val > root->data) {
        root->right = insert_data(root->right, val);
    } else if (val < root->data) {
        root->left = insert_data(root->left, val);
    }
    return root;
}

void display(Node* root) {
    if (root != nullptr) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

Node* search_ele(Node* root, int item) {
    if (root != nullptr) {
        if (item > root->data) {
            return search_ele(root->right, item);
        } else if (item < root->data) {
            return search_ele(root->left, item);
        } else if (item == root->data) {
            cout << "\n" << root->data << " is found!";
            return root;
        }
    }
    cout << "Item is not found!";
    return nullptr;
}

Node* delete_ele(Node* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val > root->data) {
        root->right = delete_ele(root->right, val);
    } else if (val < root->data) {
        root->left = delete_ele(root->left, val);
    } else if (val == root->data) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* pred = root->left;
            Node* predParent = nullptr;

            while (pred->right != nullptr) {
                predParent = pred;
                pred = pred->right;
            }

            root->data = pred->data;

            if (predParent != nullptr) {
                predParent->right = pred->left;
            } else {
                root->left = pred->left;
            }

            delete pred;
        }
        cout << "\nElement is deleted!";
    } else {
        cout << "\nElement to be deleted is not found!";
    }

    return root;
}

int main() {
    Node root(30);
    insert_data(&root, 20);
    insert_data(&root, 40);
    insert_data(&root, 50);
    insert_data(&root, 10);
    insert_data(&root, 25);
    
    cout << "Original tree: ";
    display(&root);

    Node* foundNode = search_ele(&root, 25);
    if (foundNode) {
        cout << "\nNode found: " << foundNode->data;
    }

    cout << "\nAfter deleting 25: ";
    Node* root1 = delete_ele(&root, 25);
    display(root1);

    return 0;
}
