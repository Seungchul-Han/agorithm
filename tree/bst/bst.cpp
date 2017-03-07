#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T mData;
    Node* mLeft;
    Node* mRight;
    Node(T data) : mData(data), mLeft(NULL), mRight(NULL) {}
};

template<typename T>
class Bst {
    Node<T>* mRoot = NULL;
    Node<T>* MakeNode(T data);
    Node<T>* Insert(Node<T>* node, T data);
    Node<T>* Delete(Node<T>* node, T data);
    Node<T>* FindMin(Node<T>* node);
    bool Search(Node<T>* node, T data);
    void PrintTree(Node<T>* node);

public:
    void Insert(T data);
    void Delete(T data);
    bool Search(T data);
    void PrintTree();
};

template<typename T>
Node<T>* Bst<T>::MakeNode(T data)
{
    return new Node<T>(data);
}

template<typename T>
Node<T>* Bst<T>::Insert(Node<T>* node, T data)
{
    if (NULL == node) {
        node = MakeNode(data);
        if (NULL == mRoot) mRoot = node;
    }
    else if (node->mData >= data) node->mLeft = Insert(node->mLeft, data);
    else if (node->mData < data) node->mRight = Insert(node->mRight, data);

    return node;
}

template<typename T>
void Bst<T>::Insert(T data)
{
    Insert(mRoot, data);
}

template<typename T>
Node<T>* Bst<T>::FindMin(Node<T>* node)
{
    if (NULL == node) return NULL;
    while (node->mLeft) {
        node = node->mLeft;
    }
    return node;
}

template<typename T>
Node<T>* Bst<T>::Delete(Node<T>* node, T data)
{
    if (NULL == node) return NULL;
    else if (node->mData > data) node->mLeft = Delete(node->mLeft, data);
    else if (node->mData < data) node->mRight = Delete(node->mRight, data);
    else {
        if (NULL == node->mLeft && NULL == node->mRight) {
            delete node;
            node = NULL;
        }
        else if (NULL != node->mLeft && NULL == node->mRight) {
            Node<T>* temp = node;
            node = node->mLeft;
            delete temp;
        }
        else if (NULL == node->mLeft && NULL != node->mRight) {
            Node<T>* temp = node;
            node = node->mRight;
            delete temp;
        }
        else {
            Node<T>* temp = FindMin(node->mRight);
            node->mData = temp->mData;
            node->mRight = Delete(node->mRight, temp->mData);
        }
     }

    return node;
}

template<typename T>
void Bst<T>::Delete(T data)
{
    Delete(mRoot, data);
}

template<typename T>
void Bst<T>::PrintTree(Node<T>* node)
{
    if (NULL == node) return;
    PrintTree(node->mLeft);
    cout << node->mData << ", ";
    PrintTree(node->mRight);
}

template<typename T>
void Bst<T>::PrintTree()
{
    PrintTree(mRoot);
    cout << endl;
}

template<typename T>
bool Bst<T>::Search(Node<T>* node, T data)
{
    if (NULL == node) return false;
    else if (node->mData > data) return Search(node->mLeft, data);
    else if (node->mData < data) return Search(node->mRight, data);

    return true;
}

template<typename T>
bool Bst<T>::Search(T data)
{
    return Search(mRoot, data);
}

int main()
{
    Bst<int> tree;
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(25);
    tree.Insert(35);
    tree.PrintTree();

    cout << "Delete 21" << endl;
    tree.Delete(21);
    tree.PrintTree();

    cout << "Delete 5" << endl;
    tree.Delete(5);
    tree.PrintTree();

    cout << "Delete 15" << endl;
    tree.Delete(15);
    tree.PrintTree();

    cout << "Delete 30" << endl;
    tree.Delete(30);
    tree.PrintTree();

    cout << "Search 20 : " << tree.Search(20) << endl;
    cout << "Search 10 : " << tree.Search(10) << endl;
    cout << "Search 35 : " << tree.Search(35) << endl;
    cout << "Search 17 : " << tree.Search(17) << endl;
    cout << "Search 30 : " << tree.Search(30) << endl;
    cout << "Search 15 : " << tree.Search(15) << endl;
    cout << "Search 5 : " << tree.Search(5) << endl;
    return 0;
}

