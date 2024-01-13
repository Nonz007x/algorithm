#include <bits/stdc++.h>
#include <string>

using namespace std;
string convertArrayToString(int arr[], int n)
{
    stringstream ss("");
    for (int i = 0; i < n; i++) 
    {
        ss << arr[i];
    }
    return ss.str();
}
void buildMaxHeap(int arr[], int n){
	for(int i = 1;i<n;i++){
		int j =i;
		while(arr[j] > arr[(j-1)/2]){
			swap(arr[j], arr[(j-1) / 2]);
			j= (j-1)/2;
		}
	}
}
void heapSort(int arr[], int n){
	buildMaxHeap(arr,n);
	for(int i =n-1;i>0;i--){
		swap(arr[0], arr[i]);
		int j = 0, index;
		do
		{
			index = (2 * j + 1);
			if(arr[index] < arr[index + 1] &&
				index < (i-1))
				index++;
			if(arr[j] < arr[index] && index < i)
				swap(arr[j], arr[index]);
				
			j = index;
		}while(index < i);
	}
}
int main(){
	int n,i=0;
	cin >> n;
	int *ar = new int [n];
	int *br = new int [n];
	while(i < n){
		cin >> ar[i];
		i++;
	}
	heapSort(ar,n);
	string ans = "";
    ans = convertArrayToString(ar,n);
    cout << ans;
    int idm = 0;
    int Max = 0;
    int temp = 0;
    int temp1 = 0;
//    check max same number
	bool f[n]={false};
	int aa[10] = {0};
	n = ans.length();
    for(int i =0;i<n;i++){
    	if(ans[i] == ans[i+1]){
    		aa[ans[i] - '0']++;
    		f[i] = true;
//    		cout <<"Gay 1";
		}else if(i+1 == n+1 ){
			aa[ans[i+1]-'0']++;
			f[i] = true;
//			cout<< "Gay 2";
		}else if(i < n){
			if(ans[i-1] == ans[i]){
				aa[ans[i] - '0']++;
				f[i] = true;
//				cout<< "Gay third";
			}
			else if(ans[i-1] != ans[i] && aa[ans[i] - '0'] == 0){
				aa[ans[i] - '0']++;
				f[i] = true;
//				cout <<"Gay last";
			}
		}else{
			aa[ans[i] - '0']++;
			f[i] = true;
		}
	}
//	for(int i=0;i<10;i++){
//		cout << aa[i] << " ";
//	}
	//find max
	bool *samebigdick = new bool[10]{false};
	
	Max = aa[0];
	for(int i =0;i<10;i++){
		if(aa[i] > Max){
			Max = aa[i];
			for(int j = 0;j<i;j++){
				samebigdick[j] = false;
			}
			samebigdick[i] = true;
		}else if(aa[i] == Max){
			samebigdick[i] = true;
		}
	}
	cout << endl;
	for(int i =0;i<10;i++){
		if(samebigdick[i]){
			cout << i << " ";
		}
	}
	cout << endl;
	for(int i =1;i<n+1;i++){
		if(ans[i-1] == ans[i]){
			continue;
		}else{
			cout << ans[i-1];
		}
	}
	delete []ar;
	delete []br;
	return 0;
}
