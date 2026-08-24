#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size){
	int n = size;
	for(int i = 0; i<n; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}
	
int main(){
	int arr[10] = {1, 5, 10, 9, 2, 11, 15, 20, 30, 35};
	
	int size = sizeof(arr)/sizeof(arr[0]); cout<<size;
	int key; cout<<"Enter the key: "; cin>>key;
	int res = linearSearch(arr, key, size);
	
	if(res != -1){
		cout<<"element is found at index "<<res<<endl;
	}else{
		cout<<"Element is not found !!";
	}
	
}	
	

