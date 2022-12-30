#include "iostream"
using namespace std;
class test {
public :
                test() {
                        cout << "default constructor called"<<endl;
                }
                test(int x) {
                        cout << "int constructor called"<<endl;
                }
                test(float a) {
                        cout << "float constructor called" <<endl;
                }
};
main()
{
            test t1; //default con
            test *vecc = new test; //default constuctor
            vecc[0] = 10; //int constuctor

            cout<<endl;
            test a[2] = {10, 20}; //2 times int constuctor
            a[0] = 2.5f; //float constuctor
}
