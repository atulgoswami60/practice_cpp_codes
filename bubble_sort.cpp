#include <iostream>
using namespace std;

bubble_sort(int arr[], int size){
	int temp;
	for(int i = 0; i <= size-2; i++){
		for(int j = 0; j <= size-2; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
	int n; cout<<"Enter the size of array: \n"; cin>>n;
	int arr[n];
	cout<<"Enter the elements of array\n";
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	bubble_sort(arr, n);
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
