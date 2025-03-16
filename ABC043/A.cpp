#include <bits/stdc++.h>

using namespace std;

int main() {
	int counter = 0;
	int total = 0;
	int n;
	cin >> n;
	
	for(int i  = 0; i < n; i ++)
	{
		counter ++;
		total += counter;
	}
	
	cout << total;
	

    return 0;
}
