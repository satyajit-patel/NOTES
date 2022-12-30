#include<iostream>

using namespace std;
class emp {
private:
    int sal;
protected:
    int id;
public:
    string name;
    static string college;
    void set_data(int sal, int id, string name) {
        this->sal = sal;
        this->id = id;
        this->name = name;
        //non-static method can access both static and non-static data member.......but
        //static method can only access static data member
    }
    friend class emp2;
};
string emp :: college = "VSSUT";
class emp2 {
public:
    void display(emp &obj) {
        cout<<obj.sal<<" "<<obj.id<<" "<<obj.name<<" "<<emp::college<<endl;
    }
};
int main() {
    emp e1;
    e1.set_data(10000, 1, "first");
    emp2 e2;
    e2.display(e1);
    return 0;
}