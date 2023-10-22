#include<iostream>
using namespace std;

int main()
{
    int fact(int);
    int num;
    cin >> num;
    cout << "the factorial of " << num << " 5is " << fact(num) << endl;

    return 0;
}

int fact(int n)
{
    if(n==0 || n==1)
    return 1;
    else
    return (n*fact(n-1));
}