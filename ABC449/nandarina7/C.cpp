#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, l, r;
	cin >> n >> l >> r;
	string input;
	cin >> input;

	vector<vector<int>> table(input.size()+1, vector<int>(26, 0));
	for(int i=1; i<=input.size(); ++i) {
		table[i][input[i-1] - 'a']++;
		for(int j=0; j<26; ++j) {
			table[i][j] += table[i-1][j];
			//cout << table[i][j] << ' ';
		}
		//cout << endl;
	}

	long answer = 0;
	for(int i=1; i<=input.size()-l; ++i) {
		//cout << table[r-1][input[i-1]-'a'] - table[l-1][input[i-1]-'a'] << '\n';
		int new_r = min(i+r, (int)input.size()), new_l = i+l;
		//cout << new_l << ' ' << new_r << '\n';
		answer += (table[new_r][input[i-1]-'a'] - table[new_l-1][input[i-1]-'a']);
	}

	cout << answer;
	return 0;
}