#include<bits/stdc++.h>

using namespace std;

//heapify = O(logN)
//insert, delete = O(logN) becz after insert or delete we need to heapify
//build_heap = (N)
//get min = O(1)
class min_heap
{
private:
    vector<int> v;
    int n;

    //when insert we insert at last and we heapify_up
    void heapify_up(int i)// i is index number
    {
        while (i > 1 && v[i/2] > v[i]) //i/2 i.e its parent node
        {
            swap(v[i/2], v[i]);
            i /= 2; //i.e again go its up(parent) and check condition
        }
    }

    //when delete we exchange target element with last and delete last then we heapify_down
    void heapify_down(int i)// i is index number
    {

        //nodes which are > n/2 are all leaf nodes
        while (i <= n/2) //i.e we go down till non-leaf nodes
        {
            int min=i;

            if(v[2*i] < v[min])//if left child is small
                min=2*i;

            if(2*i+1 <=n && v[2*i+1] < v[min])//if right child exist and its smaller than min
                min=2*i+1;
            
            if(min != i){
                swap(v[i], v[min]);
                i=min;
            }
            else
                break;//out of loop
        }
    }
    void build_heap()//if we want to build a array of elements at once
    {
        for (int i = n/2; i >= 1; i--) //start with last non-leaf node and go till root 
        {
            heapify_down(i);
        }
    }
public:
    min_heap()//default constructor
    {
        v.push_back(0); //becoz we generally starts from index 1;
        n=0;
    }
    min_heap(vector<int> arr)//parameteraisd constructor
    {
        v.push_back(0);

        for(int i : arr)
            v.push_back(i);

        n= arr.size();

        build_heap();
    }

    int top()
    {
        return v[1];
    }

    void push(int num)
    {
        v.push_back(num);
        n++;
        heapify_up(n);
    }
    void pop()
    {
        swap(v[1], v[n]);//swap top with last node then delete the last node and check
                        //if everything is okay down there
        n--;
        heapify_down(1);
    }
};
int main()
{
    vector<int> arr{6,5,4,3,2,1};
    min_heap m(arr);

    cout<<m.top()<<"\n";
    
    return 0;
}
