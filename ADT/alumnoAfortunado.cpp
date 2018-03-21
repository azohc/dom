//#include <queue>
//#include <iostream>
//using namespace std;
//
//void solveCase(int n, int m) {
//
//	queue<int> q;
//
//	for (int i = 1; i <= n; i++)
//		q.push(i);
//	
//	int i = 1;
//	while (q.size() > 1) {
//		if (i % m != 0)
//			q.push(q.front());
//		q.pop();
//		i++;
//	}
//
//	cout << q.front() << endl;
//}
//
//int main() {
//
//	int a, b;
//
//	cin >> a >> b;
//	
//	while (a != 0 || b != 0)
//	{
//		solveCase(a, b);
//		cin >> a >> b;
//	}
//
//
//	return 0;
//}