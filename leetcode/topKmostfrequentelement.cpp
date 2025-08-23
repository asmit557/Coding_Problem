class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int> mp;
    int n = words.size();
    for(int i=0;i<n;i++){
        mp[words[i]]++;
    }
    vector<pair<int,string>> v;
    for(auto i:mp){
        v.push_back({i.second,i.first});
    }
    
    // Correct comparator function
    auto comp = [](const pair<int,string>& p1, const pair<int,string>& p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    };
    
    sort(v.begin(), v.end(), comp);  // Use the comparator
    
    vector<string> str;
    for(int i=0;i<k;i++){
        str.push_back(v[i].second);  // Push the string, not the frequency
    }
    return str;
 }
};
