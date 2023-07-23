#include<bits/stdc++.h>

using namespace std;
bool cmp1(int x, int y) {
    return x > y;
}
void str() {
    string s = "0123456";
    cout<<s<<"\n";
    int n = stoi(s);
    n /= 10;
    s = to_string(n);
    cout<<s<<"\n";
    
    string str = "not everythig not yet";
    //getline(cin, str);
    stringstream iss(str);
    string word;
    while(iss >> word) {
        cout<<word<<" ";
    }
    cout<<"\n";


    /*
    // ["one.two.three","four.five","six"] => ["one","two","three","four","five","six"]
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(auto& it:words) {
            std::stringstream ss(it);
            for(std::string word; std::getline(ss, word, separator);) if(!word.empty()) ans.push_back(word);
        }
        return ans;
    }
    */
};
}
bool cmp2(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) return true;
    else if(p1.second == p2.second) {
        if(p1.first > p2.first) return true;
    }
    return false;
}
void comparator() {
    vector<int> arr = {1,2,3,4,8,7,6,5};
    sort(arr.begin(), arr.end(), cmp1);
    for(auto &it:arr) cout<<it<<" ";
    cout<<"\n";

    vector<pair<int, int>> v = {{1,2}, {2,1}, {4,1}};
    //sort according to 2nd element and if both 2nd element are same then sort the ist number as descending order
    //{4,1}, {2,1}, {1,2}
    sort(v.begin(), v.end(), cmp2);
    for(auto &it:v) cout<<it.first<<","<<it.second<<" ";
    cout<<"\n";
}
void sett() {
    set<int> s;
    s.clear();
    for(int i=1; i<=5; i++) s.insert(i);
    s.erase(s.find(2));
    s.erase(s.begin());
    if(s.count(1) != 0) cout<<"found\n";
    else cout<<"not found\n";
    for(auto &it:s) cout<<it<<" ";
    cout<<"\n";
    int lb = *s.lower_bound(3);
    int ub = *s.upper_bound(3);
    cout<<lb<<" "<<ub<<"\n";
}
void mapp() {
    map<string, int> m;
    m.clear();
    m["Hello"] = 50;
    m.insert(make_pair("Hi", 100));
    m.insert(make_pair("Hay", 200));
    auto it = m.find("Hello"); //returns pair if present m.end()
    cout<<it->first<<" "<<it->second<<"\n";
    m.erase("Hello");
    if(m.count("Hello") != 0) cout<<"found\n";
    else cout<<"not found\n";
    for(auto &it:m) cout<<it.first<<" "<<it.second<<"\n"; //as now we are directly accesing it so .(dot) othersise ->(arrow)

}
int main() {
    sett();
    cout<<"----------------------------------------\n";
    mapp();
    cout<<"----------------------------------------\n";
    comparator();
    cout<<"----------------------------------------\n";
    str();
    return 0;
}