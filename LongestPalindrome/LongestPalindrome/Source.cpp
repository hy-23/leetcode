#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
string longestPalindrome(string s) {
	string ans = "";
	for (auto i = 0; i < s.size(); i++) { // s = "Bangnal";
		auto right = i;
		auto left = i;
		bool found = true;
		for (; left < s.size(); left++) {
			auto answer_len = ans.size();
			auto remain_len = s.size() - right;
			if (answer_len >= remain_len) {
				return ans;
			}
			auto dst = left - right; // right = 1; left = 5
			auto j = 0;
			auto local_r = right;
			auto local_l = left;
			while (j < dst) {
				if (s[local_r] != s[local_l]) {
					found = false;
					break;
				}
				else {
					j = j + 2;
					local_r++;
					local_l--;
					found = true;
				}
			}
			if (found == true) {
				string temp = s.substr(right, dst + 1);
				auto palind_len = temp.size();
				if (ans.size() < palind_len) {
					ans = temp;
				}
			}
		}
	}
	return ans;
}

int main() {
	string ans = longestPalindrome("alksmeraaremdeewana");
	cout << ans << endl;
	return 0;
}