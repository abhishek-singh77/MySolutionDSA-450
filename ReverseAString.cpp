//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int start= 0;
  int end= str.length()-1;
  while(start<end){
      char temp= str[start];
      str[start]=str[end];
      str[end]= temp;
      start++;
      end--;
  }
  return str;
  
}
