#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
long long findSmallest(long long num)
{
    string s = to_string(abs(num));
    if(num >= 0) sort(s.begin(), s.end());
    else sort(s.begin(), s.end(), greater<char>());

    if(num >= 0){
        int index = s.find_first_not_of('0');
        swap(s[0], s[index]);
    }

    long long ans = stoll(s);
    if(num < 0) ans *= -1;
    return ans;
}
int main()
{
    //find the smallest number without leading zero.  1< num < 1e15
    cout<<"enter\n";
    long long int num; cin>>num;
    cout<<findSmallest(num);
    return 0;
}