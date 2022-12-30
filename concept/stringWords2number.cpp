#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getPhoneNumber' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string getPhoneNumber(string s) {
    stringstream iss(s);
    string ans    = "";
    string temp   = "";
    bool doub = false;
    bool trip = false;
    while(iss >> temp) {
        if(temp == "double")  {
            doub = true;
        }
        if(temp == "triple")  {
            trip = true;
        }
        if(temp == "zero")  {
            if(doub) {
                ans += '0';
                ans += '0';
                doub = false;
            }
            else if(trip) {
                ans += '0';
                ans += '0';
                ans += '0';
                trip = false;
            }
            else ans += '0';
        }
        if(temp == "one")   {
            if(doub) {
                ans += '1';
                ans += '1';
                doub = false;
            }
            else if(trip) {
                ans += '1';
                ans += '1';
                ans += '1';
                trip = false;
            }
            else ans += '1';
        }
        if(temp == "two")   {
            if(doub) {
                ans += '2';
                ans += '2';
                doub = false;
            }
            else if(trip) {
                ans += '2';
                ans += '2';
                ans += '2';
                trip = false;
            }
            else ans += '2';
        }
        if(temp == "three") {
            if(doub) {
                ans += '3';
                ans += '3';
                doub = false;
            }
            else if(trip) {
                ans += '3';
                ans += '3';
                ans += '3';
                trip = false;
            }
            else ans += '3';
        }
        if(temp == "four")  {
            if(doub) {
                ans += '4';
                ans += '4';
                doub = false;
            }
            else if(trip) {
                ans += '4';
                ans += '4';
                ans += '4';
                trip = false;
            }
            else ans += '4';
        }
        if(temp == "five")  {
            if(doub) {
                ans += '5';
                ans += '5';
                doub = false;
            }
            else if(trip) {
                ans += '5';
                ans += '5';
                ans += '5';
                trip = false;
            }
            else ans += '5';
        }
        if(temp == "six")   {
            if(doub) {
                ans += '6';
                ans += '6';
                doub = false;
            }
            else if(trip) {
                ans += '6';
                ans += '6';
                ans += '6';
                trip = false;
            }
            else ans += '6';
        }
        if(temp == "seven") {
            if(doub) {
                ans += '7';
                ans += '7';
                doub = false;
            }
            else if(trip) {
                ans += '7';
                ans += '7';
                ans += '7';
                trip = false;
            }
            else ans += '7';
        }
        if(temp == "eight") {
            if(doub) {
                ans += '8';
                ans += '8';
                doub = false;
            }
            else if(trip) {
                ans += '8';
                ans += '8';
                ans += '8';
                trip = false;
            }
            else ans += '8';
        }
        if(temp == "nine")  {
            if(doub) {
                ans += '9';
                ans += '9';
                doub = false;
            }
            else if(trip) {
                ans += '9';
                ans += '9';
                ans += '9';
                trip = false;
            }
            else ans += '9';
        }
    }
    return ans;
}

int main()
{
	//nine double five six zero four zero seven one six
	//9556049716
    string s;
    getline(cin, s);
    string result = getPhoneNumber(s);
	cout<<result<< "\n";
    return 0;
}
