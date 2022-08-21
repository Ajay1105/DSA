#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
	char id;
	int dead;
	int profit;
};

bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

// Driver code
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}






























//#include <bits/stdc++.h>
//
//using namespace std;
//
//class job
//{
//    int deadline;
//    set <int> profit;
//public:
//    void setdata(int deadline,int p)
//    {
//        this->deadline = deadline;
//        profit.insert(p);
//    }
//    int getMax(){
//    auto it = profit.end(); it--;
//    return *it;
//    }
//};
//
//void maximumProfit(job j[],int n){
//int maxProfit =0;
//for(int i=0;i<2;i++){
//    maxProfit += j[i].getMax();
//}
//cout << maxProfit<<endl;
//}
//
//int main()
//{   int n=4;
//    job j[4];
//    j[0].setdata(4,70);j[1].setdata(1,80);j[1].setdata(1,100);j[1].setdata(1,40);
//    maximumProfit(j,n);
//    cout << sizeof(j);
//}
