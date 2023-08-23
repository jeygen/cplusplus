/*
146. LRU Cache
Medium

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

*/ 

class LRUCache {
  public:
        LRUCache(int capacity) {
                  
        }
            
        int get(int key) {
                      
        }
                
        void put(int key, int value) {
                        
        }
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
 */

// classic solution, 0(1) get and set

#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> lru;  // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map; // key to {key, value}

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if(map.find(key) == map.end()) return -1;

        // Move the accessed item to the end (most recently used)
        lru.splice(lru.end(), lru, map[key]);

        return map[key]->second;
    }

    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            // If key already exists, erase it
            lru.erase(map[key]);
        }

        // Add the new key-value to the end
        lru.push_back({key, value});
        map[key] = --lru.end(); // Point to the new last element

        // If capacity is exceeded, remove the LRU element
        if(lru.size() > capacity) {
            map.erase(lru.front().first);
            lru.pop_front();
        }
    }
};

// all hash map sol

#include <unordered_map>
#include <iostream>

class LRUCache {
    int capacity;
    std::unordered_map<int, int> cache;               // Actual cache storage: key -> value
    std::unordered_map<int, int> keyToTimestamp;      // key -> timestamp mapping
    std::unordered_map<int, int> timestampToKey;      // timestamp -> key mapping
    int timestamp = 0;                                // Emulate a LRU order

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Move the accessed item to the most recent timestamp
        int oldTimestamp = keyToTimestamp[key];
        keyToTimestamp.erase(key);
        timestampToKey.erase(oldTimestamp);
        
        timestampToKey[timestamp] = key;
        keyToTimestamp[key] = timestamp;
        timestamp++;
        
        return cache[key];
    }

    void put(int key, int value) {
        if (cache.size() >= capacity) {
            // Evict the least recently used item
            int lruKey = timestampToKey.begin()->second;
            cache.erase(lruKey);
            keyToTimestamp.erase(lruKey);
            timestampToKey.erase(timestampToKey.begin());
        }
        
        // If the key exists, update its timestamp
        if (cache.find(key) != cache.end()) {
            int oldTimestamp = keyToTimestamp[key];
            keyToTimestamp.erase(key);
            timestampToKey.erase(oldTimestamp);
        }

        cache[key] = value;
        keyToTimestamp[key] = timestamp;
        timestampToKey[timestamp] = key;
        timestamp++;
    }
};

