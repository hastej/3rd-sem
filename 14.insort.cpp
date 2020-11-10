#include<iostream>
#include<vector>

using namespace std; 

void insertionsort(vector<int> &arr, int n) 
{ 
	int key, j; 
	for (int i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 

		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 

		arr[j + 1] = key; 
	} 
} 

void display(vector<int> &arr,int n){

    for (int i = 0; i < n; i++) 
    {
		cout << arr[i] << " "; 
    }

	cout << endl;
}

int main() 
{ 
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

	vector<int> arr(n,0); 

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    cout<<endl<<"Array is : ";
    display(arr,n);
    cout<<endl;

	insertionsort(arr, n); 

    cout<<"Sorted array is : ";
    display(arr,n);

	return 0; 
}