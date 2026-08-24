#include <iostream>
using namespace std;

int main(){
	int n; cout<<"Enter the size of the array: \n"; cin>>n;
	int arr[n];
	cout<<"Enter the values of array (space separated)"<<endl;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	
	int largest = arr[0];
	for(int i = 0; i<n; i++){
		if (arr[i] >= largest){
			largest = arr[i];
		}
	}
	cout<<"largest element of the array is: "<<largest<<"\n";
}
