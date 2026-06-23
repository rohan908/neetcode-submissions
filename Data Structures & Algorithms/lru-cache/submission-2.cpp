#include <unordered_map>
#include <list>
class LRUCache {
private:
    int cap;
    int currSize;
    //{value, iterator to key in dll}
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    //dll stores the actual keys
    std::list<int> dll; 

public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1; 

        //erase is O(1), remove is not
        dll.erase(it->second.second);
        dll.push_back(key);
        it->second.second = --dll.end(); //update iterator, so we can return the value
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        //key exists
        if (it != cache.end()){
                    //erase is O(1), remove is not
            dll.erase(it->second.second);
            dll.push_back(key);
            it->second = {value, --dll.end()}; //update iterator, so we can return the value
        }
        else {
            //key does not exist
            if (cache.size() == cap) {
                int lruKey = dll.front();
                dll.pop_front();
                cache.erase(lruKey);
            }
            dll.push_back(key);
            cache[key] = {value, --dll.end()};
        }
    }
};
