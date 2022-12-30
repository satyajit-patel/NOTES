#include<bits/stdc++.h>

using namespace std;
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

#define     IOS     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define     int     long long int
#define     vi      vector<int>
#define     endl    "\n" 
void contestSolve() {
    int tc; cin>>tc;
    while(tc--) {
        
    }
}
void normalSolve() {
    string s = "1501";
    s.push_back('7');
    s.push_back('6');
    s.pop_back();
    cout<<s<<"\n";
    cout<<s.find_first_of('0')<<"\n";
    int n = stoi(s);
    n /= 10;
    s = to_string(n);
    cout<<s<<"\n";
    auto it = s.find('5');
    if(it != string::npos) cout<<"char 5 found at index "<<it<<"\n";
    else cout<<"char not found\n";
    s.erase(s.begin()+2);
    cout<<s<<"\n";
    s.insert(3,"This is fun");
    cout<<s<<"\n";    
    log(s.front(), s.back());
    s.clear();
    cout<<s.empty()<<"\n";
    
    cout<<endl;
    string str = "not everythig no yet";
    //string str; getline(cin, str);
    stringstream iss(str);
    string word;
    while(iss >> word) {
        cout<<word<<" ";
    }

    cout<<endl;
    string str2 = "baa-baa-black-sheep-have-you-any-owl";
    istringstream iss2(str2);
    string token;
    while(getline(iss2, token, '-')) {
        cout<<token<<" ";
    }
}
signed main() {
    IOS
    //contestSolve()
    normalSolve();
    return 0;
}