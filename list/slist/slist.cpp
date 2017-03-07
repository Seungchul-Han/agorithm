#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T mData;
    Node* mNext;
public:
    Node(T data) : mData(data), mNext(NULL) {}
};

template<typename T>
class SList
{
    private:
        Node<T>* mHead;
        Node<T>* MakeNode(T data);

    public:
        SList() : mHead(NULL) {}
        void Print();
        void PushBack(T data);
        void PushFront(T data);
        void Insert(int pos, T data);
        void Delete(int pos);
        void Reverse();
};

template<typename T>
Node<T>* SList<T>::MakeNode(T data)
{
    return new Node<T>(data);
}

template<typename T>
void SList<T>::Print()
{
    Node<T>* node = mHead;
    cout << "List : ";
    while (NULL != node) {
        cout << node->mData << " ";
        node = node->mNext;
    }
    cout << endl;
}

template<typename T>
void SList<T>::PushBack(T data)
{
    Node<T>* newNode = MakeNode(data);
    if (NULL == mHead) {
        mHead = newNode;
        return;
    }

    Node<T>* temp = mHead;
    while (temp->mNext != NULL) {
        temp = temp->mNext;
    }
    temp->mNext = newNode;
}

template<typename T>
void SList<T>::PushFront(T data)
{
    Node<T>* newNode = MakeNode(data);
    if (NULL == mHead) {
        mHead = newNode;
        return;
    }

    Node<T>* temp = mHead;
    newNode->mNext = temp;
    mHead = newNode;
}

template<typename T>
void SList<T>::Insert(int pos, T data)
{
    Node<T>* newNode = MakeNode(data);
    if (1 == pos) {
        newNode->mNext = mHead;
        mHead = newNode;
        return;
    }
    Node<T>* node = mHead;
    for (int i = 2; i < pos; ++i) {
        if (NULL != node->mNext)
            node = node->mNext;
    }
    newNode->mNext = node->mNext;
    node->mNext = newNode;
}

template<typename T>
void SList<T>::Delete(int pos)
{
    if (NULL == mHead) return;
    Node<T>* node = mHead;
    if (1 == pos) {
        mHead = node->mNext;
        delete node;
        return;
    }
    for (int i = 2; i < pos; ++i) {
        if (NULL != node->mNext)
            node = node->mNext;
    }

    if (node->mNext != NULL) {
        Node<T>* target = node->mNext;
        node->mNext = target->mNext;
        delete target;
    }

}

template<typename T>
void SList<T>::Reverse()
{
    Node<T>* prev = NULL;
    Node<T>* current = mHead;
    Node<T>* next = current->mNext;

    while (NULL != current) {
        current->mNext = prev;
        prev = current;
        current = next;
        if (NULL != next)
            next = current->mNext;
    }
    mHead = prev;
}

int main()
{
    SList<int> list;
    list.PushFront(4);
    list.PushBack(5);
    list.PushFront(3);
    list.PushBack(6);
    list.PushBack(7);
    list.PushBack(8);
    list.PushBack(9);
    list.PushFront(2);
    list.Insert(1, 11);
    list.Insert(3, 13);
    list.Insert(5, 15);
    list.Insert(20, 20);

    list.Print();
    list.Delete(1);
    list.Print();
    list.Delete(11);
    list.Print();
    list.Delete(7);
    list.Print();

    SList<int> list2;
    list2.PushBack(1);
    list2.Print();
    list2.Reverse();
    list2.Print();

    SList<int> list3;
    list3.PushBack(1);
    list3.PushBack(2);
    list3.Print();
    list3.Reverse();
    list3.Print();

    SList<int> list4;
    list4.PushBack(5);
    list4.PushBack(4);
    list4.PushBack(3);
    list4.PushBack(2);
    list4.PushBack(1);
    list4.Print();
    list4.Reverse();
    list4.Print();


    return 0;
}
