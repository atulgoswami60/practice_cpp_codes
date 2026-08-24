#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cout<<"Enter the size of array"<<endl; cin>>n;
	int arr[n];
	
	cout<<"Enter the"<<n<<"elements of array with spaces."<<endl;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	int Sum = 0;
	
	int Max = arr[0];
	int Min = arr[0];
	for(int i =0; i<n; i++){
		Sum += arr[i];
		if(arr[i] >= Max){
			Max = arr[i];
		}
		if(arr[i] <= Min){
			Min = arr[i];
		}
	}
	float avg = (float)Sum/n;
	cout<<"Maximum element is "<<Max<<endl;
	cout<<"Minimum element is "<<Min<<endl;
	cout<<"Average of the array is "<<avg<<endl;
	
	
	
	return 0;
}
