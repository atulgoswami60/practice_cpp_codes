#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word){
	int start, end;
	start = 0; end = word.length() - 1;
	
	while (start < end){
		if(word[start] != word[end]){
			return 0;
		}else{
			start++;
			end--;
		}
	}
	return 1;
}

int main(){
	string word;
	cout<<"Enter the word: "; cin>>word;
	
	if (isPalindrome(word)){
		cout<<"Palindrome"<<endl;
	}else{
		cout<<"Not a Palindrome"<<endl;
	}
}
