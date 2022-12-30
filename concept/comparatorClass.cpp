#include<bits/stdc++.h>

using namespace std;
class student{
private:
    string name;
    int roll_no;

public:
    student(string name, int roll_no){
        this->name = name;
        this->roll_no = roll_no;
    }
    string getName(){
        return name;
    }
    int getRoll(){
        return roll_no;
    }
};

bool comp(student &s1, student &s2){
    if(s1.getRoll() < s2.getRoll()) return true;
    else return false;
}
int main()
{
    student s1("Ankit", 22);
    student s2("Satya", 21);
    student s3("Babu", 20);

    vector<student> vec = {s1, s2};
    vec.push_back(s3);

    sort(vec.begin(), vec.end(), comp);
    for(auto it : vec)
        cout<<it.getName()<<"\n";
    return 0;
}