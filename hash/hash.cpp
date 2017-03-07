#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


template<typename K, typename V>
struct HashNode
{
    K mKey;
    V mValue;

    public:
        HashNode(const K& key, const V& value) : mKey(key), mValue(value) {}
};

template<typename K, unsigned long TS>
struct HashFunc {
    unsigned long operator()(const K& key) const {
        return static_cast<unsigned long>(key) % TS;
    }
};

template<typename K, typename V, typename F>
class HashTable {
private:
    vector<list<HashNode<K, V>*>> mTable;
    F hashfunc;
public:
    HashTable(size_t size) {
        mTable.resize(size);
    }
    void put(const K& key, const V& value);
    bool get(const K& key, V& value);
};

template<typename K, typename V, typename F>
void HashTable<K, V, F>::put(const K& key, const V& value)
{
    unsigned long hash = hashfunc(key);

    cout << "hash value: " << hash << endl;
    auto& list = mTable[hash];

    for (auto& node : list) {
        if (node->mKey == key) {
            node->mValue = value;
            return;
        }
    }

    list.push_back(new HashNode<K, V>(key, value));
}

template<typename K, typename V, typename F>
bool HashTable<K, V, F>::get(const K& key, V& value)
{
    unsigned long hash = hashfunc(key);
    auto& list = mTable[hash];
    for (auto& node : list) {
        if (node->mKey == key) {
            value = node->mValue;
            return true;
        }
    }

    return false;
}

int main()
{
    constexpr int TableSize = 10000;
    HashTable<int, int, HashFunc<int, TableSize>> ht(TableSize);
    ht.put(1, 10);
    ht.put(2, 20);
    ht.put(3, 30);
    ht.put(13, 130);
    ht.put(23, 230);

    int key = 0;
    int value = 0;
    key = 1; ht.get(key, value); cout << key << " " << value << endl;
    key = 2; ht.get(key, value); cout << key << " " << value << endl;
    key = 3; ht.get(key, value); cout << key << " " << value << endl;
    key = 13; ht.get(key, value); cout << key << " " << value << endl;
    key = 23; ht.get(key, value); cout << key << " " << value << endl;

    return 0;
}

