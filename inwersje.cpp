#include<iostream>
#include<algorithm>
using namespace std;
int x = 0;
int merge(int tab[], int left1, int m, int right2, int n){
	
	int pivot = left1;
	int * Tab = new int[n];
	int right1 = m;
	int left2 = m+1;
	int i = left1;
	int licznik = 0;
	
	while(left1<= right1 && left2 <= right2){
		if(tab[left1] < tab[left2]){
			Tab[i] = tab[left1++];
			licznik++;
		}
		else Tab[i] = tab[left2++];
		i++;
	}	
	
	while(left1 <= right1) Tab[i++] = tab[left1++];
	while(left2 <= right2) Tab[i++] = tab[left2++];
	
	for(int i =pivot; i<=right2; i++) tab[i] = Tab[i];
	return licznik;
}

void mergeSort(int tab[], int left, int right, int n){
	
	if(left<right){
		int m =(left + right)/2;
		mergeSort(tab,left,m,n);
		mergeSort(tab,m+1,right,n);
		x+=merge(tab, left, m, right, n);	
	}
	
}


int main(){
	
	int tab[7] = {5,2,4,8,6,3,7};
	mergeSort(tab,0,6,7);
	
	for(int i =0; i<7; i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;
	cout<<x;
	
	return 0;
}

