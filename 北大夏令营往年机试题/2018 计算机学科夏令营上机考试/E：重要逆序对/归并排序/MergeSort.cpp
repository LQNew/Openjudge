#include <iostream>
using namespace std;
int N;
int a[20000];
// Function to Merge Arrays L and R into A.
// leftCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	// i - to mark the index of left sub_array (L)
	// j - to mark the index of right sub_array (R)
	// k - to mark the index of merged sub_array (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) { //两个分别排好序的数组进行比对，决定新的数组如何插入
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount)  A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void MergeSort(int *A,int n) {
	int mid,i,*L,*R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing.

	mid = n/2;  // find the mid index.

	// create left and right sub_arrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = new int[mid];
	R = new int[n - mid];

	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left sub_array
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right sub_array

	MergeSort(L,mid);  // sorting the left sub_array
	MergeSort(R,n-mid);  // sorting the right sub_array
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	// the delete operations is very important
	delete [] R;
	delete [] L;
}

int main() {
	while(cin>>N){
        if(N==0) break;
        for(int i=0;i<N;i++) cin>>a[i];
        MergeSort(a,N);
        for(int i=0;i<N;i++) cout<<a[i]<<' ';
        cout<<endl;
    }
	return 0;
}
