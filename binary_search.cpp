#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key){
	int beg = 0;
	int end = size-1;
	int mid;
	while (beg <= end){
		mid = (beg + end)/2;
		if(arr[mid] == key){
			return mid;
		}else if(key < arr[mid]){
			end = mid - 1;
		}else{
			beg = mid + 1;
		}
	}
		return -1;
}


int main(){
	int arr[20] = {1, 2 , 3, 4, 5, 6, 7, 8, 10, 11};
	int res, key, size;
	cout<<"Enter the key: "<<endl; cin>>key;
	size = 10;
	res = binary_search(arr, size, key);
	cout<< res<<endl;
	return 0;
}
