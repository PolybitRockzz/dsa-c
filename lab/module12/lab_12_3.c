
#include <stdio.h>

void insertionSort(int a[], int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int binarySearch(int a[], int n, int key){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(a[mid] == key) return 1;
		else if(a[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return 0;
}

int main(){
	int n,i;
	printf("Enter no.of elements: ");
	if(scanf("%d", &n) != 1) return 0;
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	int key;
	printf("Enter element to be searched: ");
	if(scanf("%d", &key) != 1) return 0;
	insertionSort(a,n);
	if(binarySearch(a,n,key)) printf("Element found\n");
	else printf("Element not found\n");
	return 0;
}

