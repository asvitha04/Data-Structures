#include<iostream>
#include<cstdlib>
#define SPACE 10
using namespace std;
struct Node{
    Node *left;
    Node *right;
    int data;

    Node(int val) {
    left = nullptr;
    right = nullptr;
    data = val;
    }
};
int height(Node * root)
{
    if (root == NULL)
      return -1;
    else {
      int lheight = height(root -> left);
      int rheight = height(root -> right);
      if (lheight > rheight)
        return (lheight + 1);
      else
        return (rheight + 1);
    }
  }
int BalanceFactor(Node * n)
{
    if (n == NULL)
      return 0;
    return height(n -> left) - height(n -> right);
  }

Node * rightRotate(Node * y) {
    Node * x = y -> left;
    Node * T2 = x -> right;
    x -> right = y;
    y -> left = T2;

    return x;
  }

Node * leftRotate(Node * x) {
    Node * y = x -> right;
    Node * T2 = y -> left;
    y -> left = x;
    x -> right = T2;

    return y;
  }

Node* insert_data(Node *root,int val)
{
    Node* new_node = new Node(val);
    new_node->data=val;
    if(!root)
    {
        root = new_node;
        return root;
    }
        if(val>(root->data)){
            root->right=insert_data(root->right,val);
        }
        else if(val<(root->data)){
             root->left=insert_data(root->left,val);
        }
        int bf =BalanceFactor(root);
            if (bf > 1 && val < root -> left -> data)
                return rightRotate(root);
            if (bf < -1 && val > root -> right -> data)
                return leftRotate(root);
            if (bf > 1 && val > root -> left -> data)
                {
                root -> left = leftRotate(root -> left);
                return rightRotate(root);
                }
            if (bf < -1 && val < root -> right -> data)
                {
                root -> right = rightRotate(root -> right);
                return leftRotate(root);
                }
        return root;
}
void display(Node* root)
{
    if (root != NULL)
     {
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}
Node* search_ele(Node* root,int item){
    if (root == nullptr) {
    cout << "Item is not found!";
    return nullptr;
    }

    if (root !=NULL){
         if(item>(root->data)){
            root->right=search_ele(root->right,item);
        }
        else if(item<(root->data)){
             root->left=search_ele(root->left,item);
        }
        else if(item==(root->data)){
            cout<<"\n"<<root->data<<" is found!";
        }
    }
    else
    {
        cout<<"Item is not found!";
    }
 return root;
}
Node* delete_ele(Node* root, int val) {
    if (!root) {
        return nullptr;
    }

    if (val > root->data) {
        root->right = delete_ele(root->right, val);
    }
    else if (val < root->data) {
        root->left = delete_ele(root->left, val);
    }
    else if (val == root->data) {
        // Case 1: No children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
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

    }

    else {
        cout << "\nElement to be deleted is not found!";
    }

             int bf=BalanceFactor(root);
            if (bf == 2 && BalanceFactor(root -> left) >= 0)
                return rightRotate(root);
            else if (bf == 2 && BalanceFactor(root -> left) == -1)
                {
                root -> left = leftRotate(root -> left);
                return rightRotate(root);
                }
            else if (bf == -2 && BalanceFactor(root -> right) <= -0)
                return leftRotate(root);
            else if (bf == -2 && BalanceFactor(root -> right) == 1)
                {
                root -> right = rightRotate(root -> right);
                return leftRotate(root);
                }

    return root;
}

void printtree(Node * root, int space) {
    if (root == NULL)
      return;
    space += SPACE;
    printtree(root -> right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " "; 
    cout << root -> data << "\n";
    printtree(root -> left, space);
  }


int main()
{
    Node* root = new Node(30);
    insert_data(root,20);
    insert_data(root,40);
    insert_data(root,50);
    insert_data(root, 10);
    insert_data(root, 25);
    display(root);
    search_ele(root, 25);
    delete_ele(root, 10);
    cout <<"\n10 is deleted!"<<endl;
    printtree(root, 5);
    return 0;
}
