


#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>

long minnum(long a, long b) {
	if (a < b) return a;
	else return b;
}
bool justnum(long a, long b,long n,long m,long k) {
	long left = (n - a) * (m - b);
	return left<=k;
}

long solution(long a, long b, long n, long m, long k) {

	//if (!justnum(a, b, n, m, k)) {
	//	return minnum(solution(a + 1, b, n, m, k), solution(a, b + 1, n, m, k));
	//}
	//else return a+b;
	while (!justnum(a, b, n, m, k)) {
		if (n - a < m - b) 
			while (!justnum(a, b, n, m, k)) a++;
		else {
			while (!justnum(a, b, n, m, k)) b++;
		}
	}
	return a + b;
}


int main() {
	long n, m, k;
	
	cin >> n;
	cin >> m;
	cin >> k;
	cout << solution(0, 0,n,m,k) << endl;
	return 0;

}
