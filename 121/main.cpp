#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#include <typeinfo>
#include <set>
#include <algorithm>
#include <list>
using namespace std; 
class Solution {
public:
	string s;
	Solution(string s) {
		this->s = s;
	}
	Solution(){}
	
	
};
 template<typename T>
void printList(vector<T> &num) {
	for (int i = 0;i < num.size();i++) {
		cout << num[i] << " ";
	}
	cout << endl;
}
vector<int> Sum(vector<int>& a, vector<int>& b) {
	if (a.size() > b.size()) {
		
		for (int i = b.size() - 1;i >= 0;i--) {
			if (a[a.size() - b.size()+i] + b[i] < 10) {
				a[a.size() - b.size() + i] = a[a.size()- b.size() + i] + b[i];
			}
			else if (a[a.size() - b.size() + i] + b[i] > 10){
				a[a.size() - b.size() + i] = (a[a.size() - b.size() + i] + b[i]) % 10;
				a[a.size() - 1 - b.size() + i] = a[a.size() - 1 - b.size() + i] + 1;
				if (a[a.size() - 1 - b.size() + i] == 10 && (a.size() - 1 - b.size() + i) != 0) {
					a[a.size() - 1 - b.size() + i] = 0;
					a[a.size() - 2 - b.size() + i] += 1;

				}
			}
			
			else {
				a[a.size() - b.size() + i] = 0;
				a[a.size() - 1 - b.size() + i] = a[a.size() - 1 - b.size() + i] + 1;

				if (a[a.size() - b.size() + i] == 10 && (a.size() - 1 - b.size() + i) != 0) {
					a[a.size() - b.size() + i] = 0;
					a[a.size() - 1 - b.size() + i] += 1;

				}
			}
		}
		for (int i = a.size()-1;i >=1;i--) {
			if (a[i] >= 10) {
				a[i] = a[i] % 10;
				a[i - 1] += 1;
			}
		}
		if (a[0] >= 10) {
			a.insert(a.begin(), 1);
			a[1] = a[1] % 10;
		}
		return a;
	}
	else if(a.size() < b.size()) {
		
		for (int i = a.size() - 1;i >= 0;i--) {
			
			if (a[i] + b[b.size() - a.size() + i] < 10) {
				b[b.size() - a.size() + i] = a[i] + b[b.size() - a.size() + i];
			}
			else if (a[i] + b[b.size() - a.size() + i] > 10){
				b[b.size() - a.size() + i] = (a[i] + b[b.size() - a.size() + i]) % 10;
				b[b.size() - 1 - a.size() + i] = b[b.size() - 1 - a.size() + i] + 1;
				if (b[b.size() - 1 - a.size() + i] == 10 && (b.size() - 1 - a.size() + i) != 0) {
					b[b.size() - 1 - a.size() + i] = 0;
					b[b.size() - 2 - a.size() + i] += 1;

				}
			}
			else {
				b[b.size() - a.size() + i] = 0;
				b[b.size() - 1 - a.size() + i] = b[b.size() - 1 - a.size() + i] + 1;

				if (b[b.size() - 1 - a.size() + i] == 10 && (b.size() - 1 - a.size() + i)!=0 ) {
					b[b.size() - 1 - a.size() + i] = 0;
					b[b.size() - 2 - a.size() + i] += 1;

				}
			}
		}
		for (int i = b.size() - 1;i >= 1;i--) {
			if (b[i] >= 10) {
				b[i] = b[i] % 10;
				b[i - 1] += 1;
			}
		}
		if (b[0] >= 10) {
			b.insert(b.begin(), 1);
			b[1] = b[1] % 10;
		}
		return b;
	}
	else {
		if (a[0] + b[0] >= 10) {
			a.insert(a.begin(), 0);
			b.insert(b.begin(), 0);
		}
		for (int i = b.size() - 1;i >= 0;i--) {
			
			if (a[i] + b[i] < 10) {
				//cout << a[i] + b[i] << "||| ";
				a[i] = a[i] + b[i];
				//cout << i << " (!!!!!10) " << a[i] << endl;
			}
			else if (a[i] + b[i] == 10) {
				//cout << a[i] + b[i] << "|||| ";
				a[i] = 0;
				a[i - 1] = a[i - 1] + 1;
				
				if(a[i-1]==10){
					a[i - 1] = 0;
					a[i - 2] += 1;

				}
				//cout << "  " << i << " (==10 ) " << a[i] << "  " << i - 1 << " (==10 ) " << a[i - 1] << endl;
			}
			else {
				//cout << a[i] + b[i] << "|| ";
				a[i] = (a[i] + b[i]) % 10;
				a[i-1] = a[i-1] + 1;
				if (a[i-1] == 10) {
					a[i - 1] = 0;
					a[i - 2] += 1;

				}
				//cout << "  " << i << " (>>10 ) " << a[i] << "  " << i - 1 << " (>>10 ) " << a[i - 1] << endl;
			}
			
		}
		return a;
	}
	
}
int main(int argc, char* argv[]) {
	cout << "Put a first arrey: ";
	string s1;
	getline(cin, s1);
	string s2;
	cout << "Put a second arrey: ";
	getline(cin, s2);
	stringstream ss(s1);
	int x;
	vector<int> num1;
	vector<int> num2;
	while (ss >> x) {
		num1.push_back(x);
	}
	stringstream aa(s2);
	int y;
	while (aa >> y) {
		num2.push_back(y);
	}
	printList(num1);
	printList(num2);
	vector<int> res=Sum(num1, num2);
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << " ";
	}
	

	return 0;

}