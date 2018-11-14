#include<iostream>
using namespace std;

template<typename T>
class BSTNode
{
    public:
    T value;
    BSTNode *lchild;
    BSTNode *rchild;
    BSTNode(T v, BSTNode *l = NULL, BSTNode *r = NULL)
    {
        value = v;
        lchild = l;
        rchild = r;
    }
};