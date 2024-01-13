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
int Partition(int ar[],int l,int r){
	int p = ar[l];
	int i  = l;
	int j = r + 1;
	do{
		do{
			i=i+1;
		}while(ar[i] < p);
		do{
			j=j-1;
		}while(ar[j]>p);
		swap(ar[i],ar[j]);
	}while(i < j);
	swap(ar[i],ar[j]);
	swap(ar[l],ar[j]);
	return j;
}
void quickSort(int ar[],int l,int r){
	int s=0;
	if(l < r){
		s=Partition(ar,l,r);
		quickSort(ar,l,s-1);
		quickSort(ar,s+1,r);
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
	quickSort(ar,0,n-1);
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
	//find max
	bool *samebigdick = new bool[10]{false};
	int mark=0;
	Max = aa[0];
	for(int i =0;i<10;i++){
		if(aa[i] > Max){
			Max = aa[i];
			mark = i;
			samebigdick[i] = true;
		}else if(aa[i] == Max){
			samebigdick[i] = true;
		}
	}
	cout << endl;
	for(int i =mark;i<10;i++){
		if(samebigdick[i]){
			cout << i << " ";
		}
	}
	cout << endl;
	for(int i =1;i<n+1;i++){
		if(ans[i-1] != ans[i]){
			cout << ans[i-1];
		}
	}
	delete []ar;
	delete []br;
	return 0;
}
