#include <iostream>
using namespace std;

int binary_search(int arr[], int key, int beg, int end){
	int mid = (beg + end)/2;
	if((end - beg) < 0){
		return -1;
	}if(key == arr[mid]){
		return mid;
	}if (key < arr[mid]){
		return binary_search(arr, key, beg, mid-1);
	}return binary_search(arr, key, mid+1, end);
}

int main(){
	int arr[20] = {1, 2 , 3, 4, 5, 6, 7, 8, 10, 11};
	int res, key, size;
	cout<<"Enter the key: "<<endl; cin>>key;
	size = 10;
	int beg = 0; int end = size-1;
	res = binary_search(arr, key, beg, end);
	cout<< res<<endl;
	
	return 0;
}
