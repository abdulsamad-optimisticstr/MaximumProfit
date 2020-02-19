#include <climits> 
#include <iostream> 
using namespace std; 

int*  maxProfit(int price[], int n) 
{ 
	static int arr[3];	
	int start = 0;
	int end = 0;
	int max = INT_MIN;
	
	for (int i = 0; i < n; i++) { 
		for (int j = i+1; j <= n; j++) {
			if((price[j] - price[i]) > max){
				max = price[j] - price[i];
				start = i;
				end = j;
			}
		}	
	}
	arr[0] = start;
	arr[1] = end;
	arr[2] = max;
	return arr; 
} 

// Driver code 
int main() 
{
	int price[] = { 10, 22, 5, 75, 65, 80, 90, 10100, 12, 100130293 }; 
	int n = sizeof(price) / sizeof(price[0]); 
	int *output = maxProfit(price, n);
	cout <<"Buying Day: " << output[0]  << endl;
	cout <<"Selling Day: " << output[1] << endl;
	cout <<"Maximum Profit: " << output[2] << endl;


	return 0; 
} 
