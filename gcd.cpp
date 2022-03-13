#include <iostream>
using namespace std;
int arr[100];
int gcd(int a,int b){
    while(a*b!=0){
        int t = b;
        b = a%b;
        a = t;
    }
    return a+b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>arr[j];
        }
        long long sum = 0;
        for(int j=0;j<a;j++){
            for(int k=j+1;k<a;k++){
                sum += gcd(arr[j],arr[k]);
            }
        }
        cout<<sum<<endl;
    }
}