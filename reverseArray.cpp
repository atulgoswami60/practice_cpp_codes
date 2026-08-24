#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cout<<"Enter the size of array"<<endl; cin>>n;
	int arr[n];
	
	cout<<"Enter the"<<n<<"elements of array with spaces."<<endl;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	int st = 0;
	int end = n-1;
	while (st<end){
		int temp = arr[st];
		arr[st] = arr[end];
		arr[end] = temp;
		st++; end--;
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
