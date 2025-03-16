#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	double total = 0;
	cin >> N;
	int* integers = new int[N];
	
	for(int i = 0; i < N; i ++)
	{
		cin >> integers[i];
		total += integers[i];
	}
	
	int equalNum = round((double)(total / N));
	int cost = 0;
	
	for(int i = 0 ; i < N; i ++)
	{
		if(integers[i] != equalNum)
		{
			cost += pow((integers[i] - equalNum),2);
		}
	}
	
	cout << cost;

    return 0;
}
