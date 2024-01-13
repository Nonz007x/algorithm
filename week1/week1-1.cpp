#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x){
                cout<<i<<" "<<j;
                i=n;
                break;
            }
            else if(i==n-1&&j==n-1){
                cout<<-1;
            }
        }
    }
    return 0;
}