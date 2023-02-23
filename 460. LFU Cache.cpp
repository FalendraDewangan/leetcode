// Leetcode problem link
// https://leetcode.com/problems/lfu-cache/

class LFUCache {
    int cap;
    unordered_map<int, list<vector<int>>::iterator> mp;  // To store key -> address mapping for deleting in linked list
    map<int, list<vector<int>>> freq;    // To store key value with counter ie. counter -> {key, value, counter} mapping and ordered because we want to delete key value with lowest counter that we wiil get in front

    void makeMostFrequentlyUsed(int key)
    {
        auto vec =  (*(mp[key]));

        // Erase it from current counter
        freq[vec[2]].erase(mp[key]);


        if(freq[vec[2]].empty())
            freq.erase(vec[2]);

        // Now insert it to new updated counter
        vec[2]++;
        freq[vec[2]].push_front(vec);

        // Update the address in mp corresponding to key
        mp[key] = freq[vec[2]].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        mp.clear();
        freq.clear();
    }

    int get(int key) {
        // If it is not present in mp ie. it do not have address entry in freq map so return -1
        if(mp.count(key) <= 0)
            return -1;

        // If it is present then retrive value and make it most frequent 

        auto &vec =  *(mp[key]);
        int value = vec[1];
        makeMostFrequentlyUsed(key);

        return value;
    }
    
    void put(int key, int value) {

        if(cap==0 && mp.size()==0)
            return;

        // If already present
        if(mp.count(key) > 0)
        {
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeMostFrequentlyUsed(key);
            return;
        }

        // If not already present then check for entry if we have to remove another for it or not
        // if cap == 0 then we have to remove one entry
        if(cap == 0)
        {
            auto &vec = freq.begin()->second.back();
            int k = vec[0];
            int f = vec[2];

            freq[f].erase(mp[k]);
            if(freq[f].empty())
                freq.erase(f);

            mp.erase(k);
            cap++;
        }

        // if not already present
        freq[1].push_front({key, value, 1});
        mp[key] = freq[1].begin();
        cap--;  
    }
};
