#include<bits/stdc++.h>
using namespace std;

struct BNode
{
    int key;
    int order;
    BNode *sibling, *parent, *child;
    BNode(int key)
    {
        this -> key = key;
        this -> order = 0;
        this -> sibling = this -> parent = this -> child = NULL;
    }
};

class BHeap
{
    BNode *head;
    BNode *min;
    void combineTrees(BNode *root1, BNode *root2)
    {

        if(root1->key < root2->key){
            swap(root1,root2);
        }
        
        root1 -> parent = root2;
        root1 -> sibling = root2 -> child;
        root2 -> child = root1;
        root2 -> order = root2 -> order + 1;
    }

    BNode* combineHeaps(BHeap *heap1, BHeap *heap2)
    {
        BNode *temp1 = new BNode(0);
        BNode *temp2 = temp1;

        BNode *root1 = heap1 -> head;
        BNode *root2 = heap2 -> head;

        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        while (root1 != NULL || root2 != NULL)
        {
            if (root1 == NULL)
            {
                temp2 -> sibling = root2;
                temp2 = temp2 -> sibling;
                root2 = root2 -> sibling;
            }
            else if (root2 == NULL)
            {
                temp2 -> sibling = root1;
                temp2 = temp2 -> sibling;
                root1 = root1 -> sibling;
            }
            else
            {
                if (root1 -> order < root2 -> order)
                {
                    temp2 -> sibling = root1;
                    temp2 = temp2 -> sibling;
                    root1 = root1 -> sibling;
                }
                else
                {
                    temp2 -> sibling = root2;
                    temp2 = temp2 -> sibling;
                    root2 = root2 -> sibling;
                }
            }
        }
        return (temp1 -> sibling);
    }

public:

    BHeap() {
        this -> head = NULL;
    }

    BHeap(BNode* root){
        this -> head = root;
    }

    bool isEmpty(){
        return (this -> head == NULL);
    }

    void insert(BNode* root){

        BHeap* newHeap=new BHeap(root);
        this -> unionHeap(newHeap);
    }

    void unionHeap(BHeap *heap)
    {
        BHeap *heap_final = new BHeap();

        heap_final -> head = combineHeaps(this, heap);

        if (heap_final -> head == NULL)
        {
            this -> head = NULL;
            this -> min = NULL;
            return;
        }

        BNode *prev = NULL;
        BNode *curr = heap_final -> head;
        BNode *next = curr -> sibling;

        while (next != NULL)
        {
            if (curr -> order != next -> order){
                prev = curr;
                curr = next;
            }

            else if( curr -> order == next -> order && next -> sibling != NULL && next -> sibling -> order == curr -> order){
                prev = curr;
                curr = next;
            }

            else if (curr -> key <= next -> key){
                curr -> sibling = next -> sibling;
                combineTrees(next, curr);
            }

            else{
                if (prev == NULL) heap_final -> head = next;
                else prev -> sibling = next;
                combineTrees(curr, next);
                curr = next;
            }
            next = curr -> sibling;
        }

        this -> head = heap_final -> head;

        this -> min = heap_final -> head;
        curr = this -> head;
        while (curr != NULL)
        {
            if (curr -> key < this -> min -> key) this -> min = curr;
            curr = curr -> sibling;
        }
    }

    BNode* first()
    {
        return this -> min;
    }

    BNode* extractMin()
    {
        BNode *mini = this -> first();

        BNode *prev = NULL;
        BNode *curr1 = this -> head;
        while (curr1 != mini)
        {
            prev = curr1;
            curr1 = curr1 -> sibling;
        }

        if (prev == NULL) this -> head = curr1 -> sibling;

        else prev -> sibling = curr1 -> sibling;

        BNode *RevNode = NULL;
        BNode *curr2 = mini -> child;
        while (curr2 != NULL)
        {
            BNode *next = curr2 -> sibling;
            curr2 -> sibling = RevNode;
            RevNode = curr2;
            curr2 = next;
        }
        BHeap *temp = new BHeap();
        temp -> head = RevNode;
        this -> unionHeap(temp);

        return mini;
    }

    void decreaseKey(BNode *root, int val)
    {

        if(val > root->key){
            cout<<"Error! New value greater than current key!\n";
            return;
        }
        root -> key = val;

        BNode *temp1 = root;
        BNode *temp2 = temp1 -> parent;
        while (temp2 != NULL && temp1 -> key < temp2 -> key)
        {
            swap(temp1 -> key, temp2 -> key);

            temp1 = temp2;

            temp2 = temp1 -> parent;
        }

        if (temp1 -> key < this -> min -> key) this -> min = temp1;
    }


    void Delete(BNode *root)
    {
        decreaseKey(root, INT_MIN);
        extractMin();
    }

    void printTree(BNode* root){

        if(root==nullptr){
            return;
        }

        queue<BNode*> q;
q.push(root);
while (!q.empty()) {
BNode* node = q.front();
q.pop();
cout<<node->key<<" ";


if (node->child != nullptr) {
BNode* temp = node->child;
while (temp != nullptr) {
q.push(temp);
temp = temp->sibling;
}
}
}
   }

    void printHeap() {
BNode* curr = head;
while (curr != nullptr) {
cout<<"B"<<curr->order<<endl;
cout<<"There are "<<pow(2, curr->order)<<" nodes in this binomial tree"<<endl;
cout<<"The level order traversal of the tree is ";
this->printTree(curr);
curr = curr->sibling;
cout<<endl<<endl;
}
}
};
int main() {
    BHeap *heap = new BHeap();

    int choice;
    int key;

    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Extract Minimum" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print Heap" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                heap->insert(new BNode(key));
                break;

            case 2:
                if (!heap->isEmpty()) {
                    cout << "Minimum key is " << (heap->extractMin())->key << endl;
                } else {
                    cout << "Heap is empty." << endl;
                }
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                break;

            case 4:
                heap->printHeap();
                break;

            case 5:
                delete heap;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

