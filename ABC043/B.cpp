#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	string finalString = "";
	
	for(char c : s)
	{
		switch(c)
		{
			case '1':
				finalString.push_back('1');
				break;
			case '0':
				finalString.push_back('0');
				break;
			default:
				if(finalString.length() != 0 )
				{
					finalString.pop_back();
				}
				break;
		}
	}
	
	cout << finalString;
	

    return 0;
}
