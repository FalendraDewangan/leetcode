// Link to leetcode Problem
// https://leetcode.com/problems/lru-cache/

// Solution 1 : Brute Force
class LRUCache {
    vector<pair<int, int>> cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        for(int i=0; i<cache.size(); i++)
        {
            if(cache[i].first == key)
            {
                int val = cache[i].second;
                cache.erase(cache.begin()+i);
                cache.push_back({key, val});
                return val;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        // If already present
        for(int i=0; i<cache.size(); i++)
        {
            if(cache[i].first == key)
            {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }

        // If not already present
        if(cache.size()==cap)
        {
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
    }
};

// Solution 2 : Optimal
class LRUCache {
    // Front of list denotes that the node is recently used
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            makeRecentlyUsed(key);
            return mp[key].second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // If already present
        if(mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
            return;
        }

        // If not already present
        dll.push_front(key);
        mp[key] = {dll.begin(), value};
        n--;

        if(n<0)
        {
            int val = dll.back();
            mp.erase(mp.find(val));
            dll.pop_back();
            n++;
        }
    }
};
