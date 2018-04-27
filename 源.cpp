#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int findmin3(int a, int b, int c);
int findmin2(int a, int b);
deque<int> solution(int N, vector<int> H, vector<int> J) {
	
	deque<int> temp;
	int j;
	if (H.size() > 2) {
		 j = findmin3(H[0], H[1], H[2]);
	}
	else if (H.size() == 2)
	{
		j = findmin2(H[0], H[1]);
	}
	else if (H.size()==1) {
		j = 1;
	}
	if (H.size() == 0)
		return temp;
	for (int i = 0;i < j;i++) {
		H.pop_back();
	}
	if (J[0] == 0 && j == 1)
		j++;
	if (J[1] == 0 && j == 2)
		j++;
	if (J[2] == 0 && j == 3)
		j++;
	
	
	if (j == 1)
		J[0] -= 1;
	else if (j == 2)
		J[1] -= 1;
	else
		J[2] -= 1;

	
	temp = solution(N - j, H, J);
	temp.push_front(j);
	return temp;
}

int findmin2(int a, int b) {
	if (a < b)
		return 1;
	else
		return 2;
}

int findmin3(int a, int b, int c) {
	int result;
	int temp;
	if (a < b)
	{
		temp = a;
		result = 1;
	}
	else
	{
		temp = b;
		result = 2;
	}
	if (temp > c)
		result = 3;
	return result;
}

int main() {



}