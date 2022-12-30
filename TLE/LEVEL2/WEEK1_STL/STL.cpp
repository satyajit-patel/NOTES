/*

v.begin(), v.end();
v.rbegin(), v.rend();
v.push_back(val), v.pop_back();
v.empty(), v.size();
v.insert(it, val), v.erase(it);
v.clear();

//O(N)
sort, reverse
min_element, max_element
find, count
fill, iota --->auto increments by 1 starting from given value
is_sorted, accumulate ---->gives sum of entire element in range + init(given) element
sort(begin, end, comparator);

Default comparator of integers and pairs:
//but we can't call it directly
bool compare(int a, int b) {
        return a < b;
}
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)        
    return a.second < b.second;    
    return a.first < b.first;
}

comparator for set
set<int, decltype(cmp)*> s(cmp);

*/

#include<bits/stdc++.h>
using namespace std;
#define endl    "\n"

bool pairASCE(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        if(a.second < b.second) return true;
        else return false;
    }
    else {
        if(a.first < b.first) return true;
        else return false;
    }
}
bool pairDESC(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return (a.second > b.second);
    else return (a.first > b.first);
}
bool intASCE(int a, int b) {
    if(a < b) return true;
    else return false;
}
bool intDESC(int a, int b) {
    if(a > b) return true;
    else return false;
}
int main() {
    int n = 15;
    vector<int> vec(n, 0);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    std::fill(vec.begin()+5, vec.begin()+10, 1);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    std::iota(vec.begin()+10, vec.end(), 5);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    vec.insert(vec.begin()+1, 720);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    vec.erase(vec.begin());
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    vec.erase(vec.begin()+1, vec.begin()+5);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    auto it = std::min_element(vec.begin(), vec.end());
    cout<<"min element = "<<*it<<" and index is "<<it-vec.begin()<<endl;

    it = std::find(vec.begin(), vec.end(), 720);
    if(it == vec.end()) cout<<"not found\n";
    else cout<<"found at index "<<it-vec.begin()<<endl;

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    cout<<"total sum is "<<sum<<endl;

    int c = std::count(vec.begin(), vec.end(), 1);
    cout<<"the #occurance of 1 is "<<c<<endl;

    if(std::is_sorted(vec.begin(), vec.end())) cout<<"vector is sorted\n";
    else cout<<"vector is not sorted\n";

    std::sort(vec.begin(), vec.end(), intASCE);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    std::sort(vec.begin(), vec.end(), intDESC);
    for(auto &it : vec) cout<<it<<" ";
    cout<<endl;

    vector<pair<int, int>> v;
    v.push_back({1, 900});
    v.push_back({2, 700});
    v.push_back({2, 800});
    std::sort(v.begin(), v.end(), pairASCE);
    for(auto &i : v) cout<<"{"<<i.first<<","<<i.second<<"}"<<" ";
    cout<<endl;

    std::sort(v.begin(), v.end(), pairDESC);
    for(auto &i : v) cout<<"{"<<i.first<<","<<i.second<<"}"<<" ";
    cout<<endl;

    cout<<"\nnow comparator in set\n";
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(4);
    for(auto &i : s) cout<<i<<" ";
    cout<<endl;
    
    //set<int, decltype(cmp)*> s(cmp);
    set<int, decltype(intDESC)*> ss(intDESC);
    ss.insert(1);
    ss.insert(2);
    ss.insert(3);
    for(auto &i : ss) cout<<i<<" ";
    cout<<endl;

    set<pair<int,int>> s1;
    s1.insert({2, 800});
    s1.insert({1, 900});
    s1.insert({2, 700});
    for(auto &i : s1) cout<<"{"<<i.first<<","<<i.second<<"}"<<" ";
    cout<<endl;

    //set<int, decltype(cmp)*> s(cmp);
    //O(logN)
    set<pair<int,int>, decltype(pairDESC)*> s2(pairDESC);
    s2.insert({2, 800});
    s2.insert({1, 900});
    s2.insert({2, 700});
    for(auto &i : s2) cout<<"{"<<i.first<<","<<i.second<<"}"<<" ";
    cout<<endl;

    return 0;
}