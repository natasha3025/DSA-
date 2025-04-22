#include <iostream>
using namespace std;

class Tnode {
public:
    int data, lbit, rbit;
    Tnode *lp, *rp;
};

class TBT {
public:
    Tnode *root, *head;

    TBT() {
        root = NULL;
        head = new Tnode();
        head->data = -999;
        head->lbit = 0;
        head->rbit = 1;  // Right always points to itself
        head->lp = head;
        head->rp = head;
    }

    void insert();
    void inorder();
    void preorder();
};

void TBT::insert() {
    Tnode *temp, *newnode;
    char ans;

    if (root == NULL) {
        root = new Tnode();
        cout << "Enter root value: ";
        cin >> root->data;

        root->lp = head;
        root->rp = head;
        root->lbit = 0;
        root->rbit = 0;

        head->lp = root;
        head->lbit = 1;
        return;
    }

    do {
        newnode = new Tnode();
        cout << "Enter node value: ";
        cin >> newnode->data;
        newnode->lbit = 0;
        newnode->rbit = 0;

        temp = root;
        while (true) {
            if (newnode->data < temp->data) {
                if (temp->lbit == 0) {
                    newnode->lp = temp->lp;
                    newnode->rp = temp;
                    temp->lp = newnode;
                    temp->lbit = 1;
                    break;
                } else {
                    temp = temp->lp;
                }
            } else if (newnode->data > temp->data) {
                if (temp->rbit == 0) {
                    newnode->rp = temp->rp;
                    newnode->lp = temp;
                    temp->rp = newnode;
                    temp->rbit = 1;
                    break;
                } else {
                    temp = temp->rp;
                }
            } else {
                cout << "Duplicate value. Skipping.\n";
                delete newnode;
                break;
            }
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
}

void TBT::inorder() {
    Tnode *temp = root;

    if (temp == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    while (temp->lbit == 1)
        temp = temp->lp;

    while (temp != head) {
        cout << temp->data << " ";

        if (temp->rbit == 1) {
            temp = temp->rp;
            while (temp->lbit == 1)
                temp = temp->lp;
        } else {
            temp = temp->rp;
        }
    }
    cout << "\n";
}

void TBT::preorder() {
    Tnode *temp = root;

    if (temp == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    while (temp != head) {
        cout << temp->data << " ";

        if (temp->lbit == 1)
            temp = temp->lp;
        else {
            while (temp->rbit == 0 && temp->rp != head)
                temp = temp->rp;
            temp = temp->rp;
        }
    }
    cout << "\n";
}

int main() {
    TBT T1;
    int choice;

    do {
        cout << "\n------------MENU--------------";
        cout << "\n1. Insert";
        cout << "\n2. Display (Inorder)";
        cout << "\n3. Display (Preorder)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                T1.insert();
                break;
            case 2:
                cout << "Inorder Traversal: ";
                T1.inorder();
                break;
            case 3:
                cout << "Preorder Traversal: ";
                T1.preorder();
                break;
            case 4:
                cout << "Thank you!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
