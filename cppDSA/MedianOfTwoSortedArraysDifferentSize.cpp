//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
    double answer;
    int m = array1.size();
    int n = array2.size();
    int size = ((m+n)/2) +1;
    vector<int> temp_array(size);
    
    // i is the pointer to integer vector temp_array 
    // j is the pointer to integer vector array1
    // k is the pointer to integer vector array2
    // only process the loop till we get to the median element 
    for(int i=0, j=0, k=0; i<size; i++)
    {
        // If array2 has reached its end
        if(k>n-1)
        {
            temp_array[i]= array1[j];
            j++;
        }

        // If array1 has reached its end
        else if (j>m-1)
        {
            temp_array[i]= array2[k];
            k++;
        }

        // If no array has reached its end pick the smaller element 
        else if(array1[j] <= array2[k])
        {
            temp_array[i]= array1[j];
            j++;
        }
        else if(array1[j] > array2[k] )
        {
            temp_array[i]= array2[k];
            k++;
        }
    }

    // If m+n is even median is average of middle 2 elements
    if((m+n)%2 == 0)
        answer = (((double)(temp_array[size-1] + temp_array[size-2]))/2);

    // If m+n is odd median is middle elements
    else 
        answer = temp_array[size-1];
    
    return answer;
}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
