#include<bits/stdc++.h>

using namespace std;

// pulkit's code
int partition(vi &arr, int l, int r)
{
	int id = rng() % (r - l + 1) + l;
	swap(arr[r], arr[id]);

	int i = l;

	for (int j = l; j <= r; ++j)
		if (arr[j] <= arr[r])
			swap(arr[i], arr[j]), i++;

	return i - 1;
}

void quick_sort(vi &arr, int l, int r)
{
	if (l >= r)
		return;

	int p_i = partition(arr, l, r);
	quick_sort(arr, l, p_i - 1);
	quick_sort(arr, p_i + 1, r);
}






int partition(int arr[], int low, int high)
{
    int pivot= arr[low], i=low, j=high;

    while (i < j)
    {
        for ( i; i <= high && arr[i] <= pivot; i++);
        for ( j; arr[j] > pivot; j--);
        

        if(i < j)
            swap(arr[i], arr[j]);
        
    }
    swap(arr[low], arr[j]);

    return j;
    
}
void quick_sort(int arr[], int low, int high)
{

    int partition_index;
    if(low < high)
    {
        partition_index = partition(arr, low, high);
        /*
        for (int i = 0; i < 8; i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<"\n\n";
        */
        quick_sort(arr, low, partition_index -1);
        quick_sort(arr, partition_index +1, high);
    }

}
int main()
{
    int arr[8]={35, 50, 15, 25, 80, 20, 90, 45};
    int low=0,high=7;

    quick_sort(arr, low, high);

    cout<<"sorted\n";
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}



//////errorrr