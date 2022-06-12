#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
string longestPalindrome(string s) {
	int len = s.length(), maxlen = 0, pos = 0;
	//bool stop = false;
	string ans;
	if (len == 1)
		return s;
	if (len == 2) {
		if (s[0] == s[1])
			return s;
		ans = s[0];
		return ans;
	}

	// find a 3 word palindrome to start off, and then exten on either
	// side to find a 5 word, 7 word ... palindrome..
	for (int i = 0; i < len; i++) {
		//if (stop) {
			//break;
		//}
		// minor adaptation to even word palindrome like 'maam'.
		if (s[i] == s[i + 1]) // s = kmaam.
		{
			int left = i;
			int right = i + 1;
			while (left >= 0 && right < len)
			{
				if (s[left] != s[right]) {
					/*
				* A string of length 'n' can contain two palindromes,
				* each of length greater than n/2.
				* So, below condition cannot be used to safely terminate
				* to terminate the answer.
				if ((2*maxlen) > len) {
					stop = true; // break the loop.
				}
				*/
					break;
				}
				if (s[left] == s[right]) {
					if (maxlen < right - left + 1) {
						pos = left;
						maxlen = right - left + 1;
					}
					left--;
					right++;
				}
			}

		}
		int left = i - 1;
		int right = i + 1;
		while (left >= 0 && right < len)
		{
			if (s[left] != s[right]) {
				/*
				* A string of length 'n' can contain two palindromes,
				* each of length greater than n/2.
				* So, below condition cannot be used to safely terminate
				* to terminate the answer.
				if ((2*maxlen) > len) {
					stop = true; // break the loop.
				}
				*/
				break;
			}
			if (s[left] == s[right]) {
				if (maxlen < right - left + 1) {
					pos = left;
					maxlen = right - left + 1;
				}
				left--;
				right++;
			}
		}

	}

	ans = s.substr(pos, maxlen);
	if (!ans.size())
		ans.push_back(s[0]);
	return ans;
}

int main() {
	string ans = longestPalindrome("malayalam");
	cout << ans << endl;
	return 0;
}