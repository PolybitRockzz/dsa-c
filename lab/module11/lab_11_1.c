#include <stdio.h>

void insertionAsc(int a[], int n){
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

void insertionDesc(int a[], int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j] < key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main(){
	int n,i;
	printf("Enter no.of elements: ");
	if(scanf("%d", &n)!=1) return 0;
	int a[n], b[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	for(i=0;i<n;i++) b[i]=a[i];
	insertionAsc(a,n);
	printf("Ascending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	insertionDesc(b,n);
	printf("Descending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}

