    #include<iostream>
    using namespace std;
    #define SIZE 500
    int multiply(int x, int f[], int digits);
    void factorial(int n)
    {
        int f[SIZE];
        f[0] = 1;
        int digits = 1;
        for (int x=2; x<=n; x++)
        {
            digits = multiply(x, f, digits);
        }
        cout<<n<<"! = ";
        for (int i=digits-1; i>=0; i--)
        cout << f[i];
    }
    int multiply(int x, int f[], int digits)
    {
        int carry = 0;
        for (int i=0; i<digits; i++)
        {
            int prod = f[i] * x + carry;
            f[i] = prod % 10;
            carry  = prod/10;
        }
        while (carry)
        {
            f[digits] = carry%10;
            carry = carry/10;
            digits++;
        }
        return digits;
    }
    int main()
    {
        int n;
        cout<<"Please enter a number : ";
        cin>>n;
        factorial(n);
        return 0;
    }
