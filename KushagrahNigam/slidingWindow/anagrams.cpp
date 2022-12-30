#include<bits/stdc++.h>

using namespace std;
int anagram(string arr, string s) {
    int n = arr.size();
    int k = s.size();
    map<char, int> temp;
    for(int i=0; i<k; i++) temp[s[i]]++;
    int noOfUniqueElements = temp.size();

    int ans = 0;
    int i=0, j=0;
    while(j < n) {
        if(temp.find(arr[j]) != temp.end()) {
            temp[arr[j]]--;
            if(temp[arr[j]] == 0) noOfUniqueElements--;
        }

        if(j-i+1 < k) {
            j++;
            continue;
        }
        if(j-i+1 == k) {
            if(noOfUniqueElements == 0) ans++;
            if(temp.find(arr[i]) != temp.end()) {
                temp[arr[i]]++;
                noOfUniqueElements++;
            }
	        i++;
            j++;
        }
    }
    return ans;
}
int main() {
	cout<<"enter\n";
    string arr; cin>>arr;
    string s; cin>>s;
    cout<<anagram(arr, s)<<"\n";
    return 0;
}