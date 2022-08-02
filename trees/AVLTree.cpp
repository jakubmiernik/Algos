#include <iostream>
#include <cassert>

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data_) : data(data_), height(1), left(nullptr), right(nullptr)
    {
    }
};

class AVLTree
{
    Node *root;

    void printHelper(Node *root, std::string indent, bool last)
    {
        if (root != nullptr)
        {
            std::cout << indent;
            if (last)
            {
                std::cout << "R----";
                indent += "   ";
            }
            else
            {
                std::cout << "L----";
                indent += "|  ";
            }

            std::cout << root->data << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    int getHeight(Node *nn)
    {
        if (nn == NULL)
            return 0;
        return nn->height;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return getHeight(node->left) - getHeight(node->right);
    }

    Node *insertHelp(Node *node, int val)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return new Node(val);

        if (val > node->data)
        {
            node->right = insertHelp(node->right, val);
        }
        else
        {
            node->left = insertHelp(node->left, val);
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && val < node->left->data)
        {
            return rightRotate(node);
        }
        if (balance > 1 && val > node->right->data)
        {
            node->right = leftRotate(node->right);
            return rightRotate(node->right);
        }
        if (balance < -1 && val > node->left->data)
        {
            return leftRotate(node);
        }
        if (balance < -1 && val < node->right->data)
        {
            node->left = rightRotate(node->left);
            return leftRotate(node->left);
        }

        return node;
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void print()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }

    void insert(int val)
    {
        root = insertHelp(root, val);
    }
};

int main()
{
    AVLTree brTree;

    brTree.insert(55);
    brTree.insert(40);
    brTree.insert(65);
    brTree.insert(60);
    brTree.insert(75);
    brTree.insert(57);

    brTree.print();
}
