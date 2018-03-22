//#include <iostream>
//#include <stack>
//#include <list>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::stack;
//
//template <typename T>
//void invertBase(stack <T> &s, int m) {
//
//	stack <T> b, o;
//	
//	int i = s.size();
//	while (i != m) {
//		b.push(s.top());
//		s.pop();
//		i--;
//	}
//	
//	while (b.size() > 0) {
//		o.push(b.top());
//		b.pop();
//	}
//
//	while (s.size() > 0) {
//		o.push(s.top());
//		s.pop();
//	}
//	
//	s.swap(o);
//}
//
//void solveCase(int n) {
//
//	int m;
//	cin >> m;
//
//	stack <int> s;
//	int aux;
//
//	for (int i = 0; i < n; i++) {
//		cin >> aux;
//		s.push(aux);
//	}
//
//
//	invertBase(s, m);
//
//	while (s.size() > 0) {
//		cout << s.top() << " ";
//		s.pop();
//	}
//
//	cout << endl;
//}
//
//int main() {
//	int n;
//
//	cin >> n;
//	while (n != -1) {
//		solveCase(n);
//		cin >> n;
//	}
//
//	return 0;
//}