#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// https://www.hackerrank.com/challenges/ctci-merge-sort/problem?isFullScreen=true

long inversion;
void merge(vector<int>&arr, int L, int mid, int H) {
    int n1 = mid-L+1;
    int n2 = H-mid;
    vector<int> A(n1), B(n2);
    for(int i=0; i<n1; i++) A[i] = arr[L+i];
    for(int i=0; i<n2; i++) B[i] = arr[(mid+1)+i];
    int i = 0, j = 0;
    while(i<n1 && j<n2) {
        if(A[i] <= B[j]) arr[L++] = A[i++];
        else {
            inversion += A.size()-i;
            arr[L++] = B[j++];
        }
    }
    while(i < n1) arr[L++] = A[i++];
    while(j < n2) arr[L++] = B[j++];
}

void merge_sort(vector<int>& arr, int L, int H) {
    if(L < H) {
        int mid = (L + H)/2; 
        merge_sort(arr, L, mid);
        merge_sort(arr, mid+1, H);
        merge(arr, L, mid, H);
    }
}

long countInversions(vector<int>& arr) {
    inversion = 0;
    merge_sort(arr, 0, arr.size()-1);
    return inversion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
