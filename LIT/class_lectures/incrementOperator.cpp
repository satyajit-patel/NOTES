#include<iostream>
int main() {
    int x = 5;

    // x++ i.e print and increment
    // ++x only increment.. atlast asign the large value to all ++x
    // and it's rigt associative

    //        <--------------------------------                                
    // inside:- 8          8        7         6
    std::cout<<x++<<" "<<++x<<" "<<++x<<" "<<++x<<"\n";
    // print :- 8          9        9         9
    return 0;
}
