// Leetcode Problem Link 
// https://leetcode.com/problems/data-stream-as-disjoint-intervals/

// Solution 1
class SummaryRanges {
    unordered_set<int> present;
    vector<int> elements;
public:
    SummaryRanges() {
        present.clear();
        elements.clear();
    }
    
    void addNum(int value) {
        if(present.count(value)<=0)
        {
            // Doing it by insertion sort logic
            int i = elements.size();
            elements.push_back(value);
            while(i-1>=0 && elements[i-1]>value)
            {
                    elements[i] = elements[i-1];
                    i--;
            }
            elements[i] = value;
            present.insert(value);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        int i=0, n=elements.size();
        while(i<n)
        {
            int left = elements[i];
            
            while(i+1<n && elements[i]+1 == elements[i+1])
                i++;

            ans.push_back({left, elements[i]});
            i++;
        }
        return ans;
    }
};

// Solution 2
class SummaryRanges {
    map<int,int> m;
public:
    SummaryRanges() {
        m.clear();
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;

        auto just_bada = m.upper_bound(value);

        if(just_bada != m.begin())
        {
            auto just_piche = just_bada;
            just_piche--;

            if(just_piche->second >= value)
                return;

            if(just_piche->second == value-1)
            {
                left = just_piche->first;
            }
        }

        if(just_bada != m.end() && just_bada->first==value+1)
        {
            right = just_bada->second;
            m.erase(just_bada);
        }

        m[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto ele : m)
            ans.push_back({ele.first, ele.second});

        return ans;
    }
};
