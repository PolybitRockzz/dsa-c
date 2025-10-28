
#include <stdio.h>

void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && a[l] > a[largest]) largest = l;
	if(r < n && a[r] > a[largest]) largest = r;
	if(largest != i){
		int t = a[i];
		a[i] = a[largest];
		a[largest] = t;
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n){
	int i;
	for(i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
	for(i = n-1; i>0; i--){
		int t = a[0];
		a[0] = a[i];
		a[i] = t;
		heapify(a, i, 0);
	}
}

int main(){
	int n,i;
	printf("Enter no.of elements: ");
	if(scanf("%d", &n)!=1) return 0;
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	heapSort(a,n);
	printf("Ascending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}

