#include<bits/stdc++.h>

using namespace std;
int main()
{
    cout<<"enter\n";
    string s;
    getline(cin, s);

    stringstream iss(s);
    string word;
    cout<<"\nwords which contains char a are:-\n";
    while(iss >> word)      //now iss will fetch every word to "word"
    {
        bool flag = false;
        int n = word.size();
        int i=0;
        while(i != n){
            if(word[i] == 'a'){
                flag = true;
                break;
            }
            i++;
        }
        if(flag == true) cout<<word<<" ";
    }

    //now iss would be empty so we have to tokonize again
    stringstream iss2(s);
    cout<<"\nwords which doesn't contains char a are:-\n";
    while(iss2 >> word)      //now iss2 will fetch every word to "word"
    {
        bool flag = false;
        int n = word.size();
        int i=0;
        while(i != n){
            if(word[i] == 'a'){
                flag = true;
                break;
            }
            i++;
        }
        if(flag == false) cout<<word<<" ";
    }
    return 0;
}