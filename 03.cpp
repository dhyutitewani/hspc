#include <bits/stdc++.h>
using namespace std;

int palindrome(const string &s) {
	int n = s.length();
	for (int i = 0; i < n/2; i++)
		if (s[i] != s[n-i-1])
			return 0;
	return 1;
}

void subSequenceCreate(const string &s, int start, vector<pair<string, int>> &result) {
    if (start == s.size()) return result;

    for (int end = start + 1; end <= s.size(); ++end) 
        result.push_back({s.substr(start, end - start), start});

    subSequenceCreate(s, start + 1, result);
}

int main() {
    string s = "aabababaab";

	vector<pair<string, int>> result;
    vector<pair<string, int>> subseq = subSequenceCreate(s, 0, result);
	
    cout << s << endl;

    for (const auto &seq : subseq)
		if (seq.first.length() >= 3)
			if (palindrome(seq.first)) cout << seq.second + 1 << " " << seq.first << endl;

    return 0;
}
