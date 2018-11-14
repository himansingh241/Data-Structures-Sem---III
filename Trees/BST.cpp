#include<iostream>
#include<queue>
#include "BSTNode.h"
using namespace std;

template<typename T>
class BST
{
    BSTNode<T> *root;
    T value;
    public:
    BST()
    {
        root = NULL;
    }
    void insert(T value);
    void insert(T value, BSTNode<T> *&temp);
    BSTNode<T>* search(T value);
    BSTNode<T>* search(T value, BSTNode<T> *temp);
    void preOrder();
    void preOrder(BSTNode<T> *temp);
    void inOrder();
    void inOrder(BSTNode<T> *temp);
    void postOrder();
    void postOrder(BSTNode<T> *temp);
    int count();
    int count(BSTNode<T> *temp);
    int countLeadNodes();
    int countLeadNodes(BSTNode<T> *temp);
    void levelOrderTraversal();
    void levelOrderTraversal(BSTNode<T> *temp);
    T max();
    T max(BSTNode<T> *temp);
    T min();
    T min(BSTNode<T> *temp);
    void deleteNode(T value);
};

template<typename T>
void BST<T> :: insert(T value)
{
    if (root == NULL)
    {
        BSTNode<T> *temp = new BSTNode<T>(value);
        root = temp;
        return;
    }
    insert(value, root);
}

template<typename T>
void BST<T> :: insert(T value, BSTNode<T> *&temp)
{
    if (temp == NULL)
    {
        temp = new BSTNode<T> (value);
        return;
    }
    if (temp -> value > value)
        insert(value, temp -> lchild);
    else
        insert(value, temp -> rchild);
}

template<typename T>
BSTNode<T>* BST<T> :: search(T value)
{
    if (root == NULL)
        throw "Empty tree";
    return search(value, root);
}

template<typename T>
BSTNode<T>* BST<T> :: search(T value, BSTNode<T> *temp)
{
    if (temp == NULL)
        return NULL;
    if (temp -> value == value)
        return temp;
    if (temp -> value > value)
        return search(value, temp -> lchild);
    return search(value, temp -> rchild);
}

template<typename T>
void BST<T> :: preOrder()
{
    if (root == NULL)
        throw "Empty Tree";
    preOrder(root);
}

template<typename T>
void BST<T> :: preOrder(BSTNode<T> *temp)
{
    cout << temp -> value << "  ";
    if (temp -> lchild != NULL)
        preOrder(temp -> lchild);
    if (temp -> rchild != NULL)
        preOrder(temp -> rchild);
}

template<typename T>
void BST<T> :: inOrder()
{
    if (root == NULL)
        throw "Empty Tree";
    preOrder(root);
}

template<typename T>
void BST<T> :: inOrder(BSTNode<T> *temp)
{
    if (temp -> lchild != NULL)
        preOrder(temp -> lchild);
    cout << temp -> value << "  ";
    if (temp -> rchild != NULL)
        preOrder(temp -> rchild);
}

template<typename T>
void BST<T> :: postOrder()
{
    if (root == NULL)
        throw "Empty Tree";
    preOrder(root);
}

template<typename T>
void BST<T> :: postOrder(BSTNode<T> *temp)
{
    if (temp -> lchild != NULL)
        preOrder(temp -> lchild);
    if (temp -> rchild != NULL)
        preOrder(temp -> rchild);
    cout << temp -> value << "  ";
}

template<typename T>
int BST<T>:: count()
{
    if (root == NULL)
        throw "Empty Tree";
    return count(root);
}

template<typename T>
int BST<T>:: count(BSTNode<T> *temp)
{
    if (temp == NULL)
        return 0;
    return 1 + count(temp -> lchild) + count(temp -> rchild);
}

template<typename T>
int BST<T>:: countLeadNodes()
{
    if (root == NULL)
        throw "Empty Tree";
    return countLeadNodes(root);
}

template<typename T>
int BST<T>:: countLeadNodes(BSTNode<T> *temp)
{
    if (temp == NULL)
        return 0;
    if (temp -> lchild == NULL && temp -> rchild == NULL)
        return 1;
    return countLeadNodes(temp -> lchild) + countLeadNodes(temp -> rchild);
}

template<typename T>
void BST<T> :: levelOrderTraversal()
{
    if (root == NULL)
        throw "Empty Tree";
    levelOrderTraversal(root);
}

template<typename T>
void BST<T> :: levelOrderTraversal(BSTNode<T> *temp)
{
    queue<BSTNode<T>*> q;
    cout << temp -> value << "  ";
    if (temp -> lchild != NULL)
        q.push(temp -> lchild);
    if (temp -> rchild != NULL)
        q.push(temp -> rchild);
    while (!q.empty())
    {
        BSTNode<T> *p = q.front();
        q.pop();
        cout << p -> value << "  ";
        if (p -> lchild != NULL)
            q.push(p -> lchild);
        if (p -> rchild != NULL)
            q.push(p -> rchild);
    }
}

template<typename T>
T BST<T> :: max()
{
    if (root == NULL)
        throw "Empty Tree";
    return max(root);
}

template<typename T>
T BST<T> :: max(BSTNode<T> *temp)
{
    if (temp -> rchild == NULL)
        return temp -> value;
    return max(temp -> rchild);
}

template<typename T>
T BST<T> :: min()
{
    if (root == NULL)
        throw "Empty Tree";
    return min(root);
}

template<typename T>
T BST<T> :: min(BSTNode<T> *temp)
{
    if (temp -> lchild == NULL)
        return temp -> value;
    return min(temp -> lchild);
}

template<typename T>
void BST<T> :: deleteNode(T value)
{
    if (root == NULL)
        throw "Empty Tree";
    BSTNode<T> *fp = root;
    BSTNode<T> *p = root;
    while (p != NULL && p -> value != value)
    {
        if (p -> value > value)
        {
            fp = p;
            p = p -> lchild;
        }
        else
        {
            fp = p;
            p = p -> rchild;
        }
    }
    // Node to be deleted is leaf node
    if (p -> rchild == NULL && p -> rchild == NULL)
    {
        if (fp -> rchild == p)
            fp -> rchild = NULL;
        else 
            fp -> lchild = NULL;
    }

    // Node to be deleted has one child
    else if ((p -> lchild != NULL && p -> rchild == NULL) || (p -> lchild == NULL && p -> rchild != NULL))
    {

        if (fp -> rchild)
        {
            if (p -> rchild != NULL)
                fp -> rchild = p -> rchild;
            else
                fp -> rchild = p -> lchild;
        }
        else
            if (p -> rchild != NULL)
                fp -> lchild = p -> rchild;
            else
                fp -> lchild = p -> lchild;
    }

    // Node to be deleted has both child.
    else if (p -> rchild != NULL && p ->  lchild != NULL)
    {
        BSTNode<T> *fq = p;
        BSTNode<T> *q = p -> rchild;
        while (q -> lchild != NULL)
        {
            fq = q;
            q = q -> lchild;
        }
        p -> value = q -> value;
        if (q -> rchild != NULL)
        {
            if (fq -> rchild == q)
                fq -> rchild = q -> rchild;
            else 
                fq -> lchild = q -> rchild;
        }
        else
        {
            if (fq -> rchild == q)
                fq -> rchild = NULL;
            else 
                fq -> lchild = NULL;
        }
    }
}

int main()
{
    BST<int> p;
    p.insert(10);
    p.insert(11);
    p.insert(3);
    p.insert(2);
    p.insert(4);
    p.insert(5);
    p.insert(6);
    p.levelOrderTraversal();
    p.deleteNode(3);
    cout << '\n';
    p.levelOrderTraversal();
}