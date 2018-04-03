#include<iostream>
#include<algorithm>
using namespace std;
int x = 0;
void merge(int tab[], int left1, int m, int right2, int n){
	
	int pivot = left1;
	int * Tab = new int[n];
	int right1 = m;
	int left2 = m+1;
	int i = left1;
	int licznik = 0;
	
	while(left1<= right1 && left2 <= right2){
		if(tab[left1] < tab[left2]){
			Tab[i] = tab[left1++];
			//licznik++;
		}
		else {
			Tab[i] = tab[left2++];
			x+= left1;
		}
		i++;
	}	
	
	while(left1 <= right1) Tab[i++] = tab[left1++];
	while(left2 <= right2) Tab[i++] = tab[left2++];
	
	for(int i =pivot; i<=right2; i++) tab[i] = Tab[i];
}

void mergeSort(int tab[], int left, int right, int n){
	
	if(left<right){
		int m =(left + right)/2;
		mergeSort(tab,left,m,n);
		mergeSort(tab,m+1,right,n);
		merge(tab, left, m, right, n);	
	}
	
}


int main(){
	
	int tab[6] = {1,2,5,3,4,0};
	mergeSort(tab,0,5,6);
	
	for(int i =0; i<6; i++){
		cout<<tab[i]<<" ";
	}
	cout<<endl;
	cout<<x;
	
	return 0;
}

