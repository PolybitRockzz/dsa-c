
#include <stdio.h>

void selectionAsc(int a[], int n){
	int i,j,min_idx,temp;
	for(i=0;i<n-1;i++){
		min_idx = i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[min_idx]) min_idx = j;
		}
		temp = a[i];
		a[i] = a[min_idx];
		a[min_idx] = temp;
	}
}

void selectionDesc(int a[], int n){
	int i,j,max_idx,temp;
	for(i=0;i<n-1;i++){
		max_idx = i;
		for(j=i+1;j<n;j++){
			if(a[j] > a[max_idx]) max_idx = j;
		}
		temp = a[i];
		a[i] = a[max_idx];
		a[max_idx] = temp;
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
	selectionAsc(a,n);
	printf("Ascending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	selectionDesc(b,n);
	printf("Descending order: ");
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}

