
#include <stdio.h>

void swap(int *x,int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

int partition(int a[], int low, int high){
	int pivot = a[high];
	int i = low-1;
	int j;
	for(j=low;j<high;j++){
		if(a[j] <= pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return i+1;
}

void quickSort(int a[], int low, int high){
	if(low < high){
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main(){
	int n,i;
	printf("Enter no.of elements: ");
	if(scanf("%d", &n)!=1) return 0;
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	quickSort(a,0,n-1);
	printf("Ascending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}

