//	;+-------------------------------------------+
//	;|     Analysis of Algorithms (Assignment 01)
//	;|   ========================================
//	;|   Task 02
//	;|   Maximum Crossing Sub Array
//	;|   ========================================
//	;|   Created by: Abdul Samad
//	;|   Submitted to: Sir Samyan
//	;|   ========================================
//	;+-------------------------------------------+

#include <iostream>
#include <climits>
#include <cstdlib> 
#include <ctime> 
#include <fstream>

using namespace std;
int leftSum = -9999;
int rightSum = -9999;
int crossSum = -9999;
int Sum = 0;

int max(int a,int b)
{
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int max(int a, int b, int c)
{
	return max(max(a,b),c);
}

int findMaximumSubarrayCrossing(int *A, int low, int mid, int high)
{
//	left sum 
	int sum= 0 ;
	int left_sum = INT_MIN;
	for(int i = mid; i >= low; i--)
	{
		sum += A[i];
		if(sum >= left_sum)
			left_sum = sum;
	}
	
//	right sum 
	
	sum = 0;
	int right_sum=INT_MIN;
	for(int i = mid+1; i <= high; i++)
	{
		sum += A[i];
		if(sum >= right_sum)
			right_sum = sum;
	}
	
//	 adding left and right sum to get the maximum sum across middle element;
	return left_sum + right_sum;
}

int findMaximumSubarray(int *A,int low,int high)
{
	if(low == high)
		return A[low];   		// base case 
	else
	{
		int mid = (low + high) / 2;     							// if more than one element is present in  the subarray , then the array is further divided 
		leftSum = findMaximumSubarray(A, low, mid);         		// calculate sum on the LHS of middle element
		rightSum  =findMaximumSubarray(A, mid+1, high);		      	// calculate sum on the RHS of middle element
 		crossSum = findMaximumSubarrayCrossing(A, low, mid, high);	// calculate sum crossing middle element LHS-mid_RHS
		return max(leftSum, rightSum, crossSum);					// finally return the maximum sum;
	}
			
	return 0;	
}

// random number generator
void RandomArray(int array[], int size){
	srand((unsigned)time(0));      //should give different values after every execution
     
    for(int i=0; i<size; i++){ 
        array[i] = rand() % size; 
 } 
}    

int main()
{
	clock_t start, end;
    double cpu_time_used;
	int n = 5000;
	int *A = new int[n];
	RandomArray(A, n);
	int low = 0;
	int high = n-1;
	start = clock();
	findMaximumSubarray(A,low,high);
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Time taken is: " << cpu_time_used << " s"<< endl;
	
	// storing data of array in a csv file
	ofstream myfile;
 	myfile.open("dataMaxSubArray.csv", ios :: app);
  	if (myfile.is_open()){
  		for(int count = 0; count < n; count ++){
	        myfile << A[count] << " " << endl ;
	    }
    myfile.close();
    }
    else cout << "Unable to open file"; 
	
	return 0;
}
