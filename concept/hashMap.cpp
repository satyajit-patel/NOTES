#include<bits/stdc++.h>

using namespace std;
class hashMap{
private:
    int bucketSize;
    vector<pair<int, string>> vec[10];
public:
    hashMap(){ //constructor
        bucketSize = 10;
    }
    int hash(int key){
        return key % bucketSize;
    }
    void insert(int rollNumber, string name){
        int index = hash(rollNumber);
        vec[index].push_back({rollNumber, name});
    }
    void remove(int rollNumber){
        int index = hash(rollNumber);
        for(int i=0; i<vec[index].size(); i++){
            if(vec[index][i].first == rollNumber){
                swap(vec[index][i], vec[index][vec[index].size()-1]); //replace with lats and pop_back;
                vec[index].pop_back();
                cout<<"found and deleted successfully\n";
                return;
            }
        }
        cout<<"NIL\n";
    }
    string search(int rollNumber){
        int index = hash(rollNumber);
        for(auto &it : vec[index]){
            if(it.first == rollNumber){
                return it.second;
            }
        }
        return "NIL\n";
    }
    void print(){
        for(int i=0; i<bucketSize; i++){
            cout<<"Bucket #"<<i<<": ";
            for(auto it : vec[i]){
                cout<<"{"<<it.first<<" "<<it.second<<"}";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    hashMap m;

    //rollNumber is unique
    m.insert(20, "Babu");
    m.insert(120, "Jyotika");
    m.insert(21, "Satya");
    m.insert(22, "Ankit");
    m.insert(122, "Soumya");
    m.insert(23, "Alok");
    m.insert(123, "Subrat");
    m.insert(1123, "Sonali");

    m.print();
    cout<<m.search(122)<<"\n";
    m.remove(122);
    cout<<m.search(122)<<"\n";
    m.print();
    return 0;
}