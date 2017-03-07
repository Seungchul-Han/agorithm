#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int value;
    int freq;
};

class LFUCache {

    public:
        LFUCache(int capacity) : capa(capacity), minFreq(0) {
        }

        int get(int key) {
            if (map.count(key) == 0) return -1;
            auto& node = map[key];
            fmap[node.freq].erase(imap[key]);
            node.freq++;
            fmap[node.freq].push_back(key);
            imap[key] = --(fmap[node.freq].end());

            if (fmap[minFreq].empty()) {
                minFreq = node.freq;
            }
            return node.value;
        }

        void set(int key, int value) {
            if (capa <= 0) return;

            if (get(key) != -1) {
                map[key].value = value;
                return;
            }

            if (map.size() >= capa) {
                int delete_key = fmap[minFreq].front();
                map.erase(delete_key);
                fmap[minFreq].pop_front();
                imap.erase(delete_key);

                cout << "evicts key : " << delete_key << endl;
            }
            Node node;
            node.value = value;
            node.freq = 0;
            map[key] = node;
            fmap[0].push_back(key);
            imap[key] = --fmap[0].end();
            minFreq = 0;
        }

    private:
        int capa;
        int minFreq;
        unordered_map<int, Node> map;   // key, node
        unordered_map<int, list<int>> fmap;   // frequency, key list
        unordered_map<int, list<int>::iterator> imap;   // key, key list iterator

};

int main()
{
    LFUCache cache(2);
    cache.set(1, 1);
    cache.set(2, 2);
    cout << "returns " << cache.get(1) << endl;
    cache.set(3, 3);
    cout << "returns " << cache.get(2) << endl;
    cout << "returns " << cache.get(3) << endl;
    cache.set(4, 4);
    cout << "returns " << cache.get(1) << endl;
    cout << "returns " << cache.get(3) << endl;
    cout << "returns " << cache.get(4) << endl;
}


