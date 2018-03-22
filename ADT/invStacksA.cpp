//#include <iostream>
//#include <stack>
//#include <list>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::list;
//using std::stack;
//
//template <typename T>
//void invertBase(stack <T> &s, int m) {
//	list <T> l;
//
//	while (s.size() > 0) {	// 1 2 3 in list
//		l.push_back(s.top());
//		s.pop();
//	}
//	int i = 0;
//	while(i < m){
//		l.push_back(l.front());
//		l.pop_front();
//		i++;
//	}
//	int aux = l.size();
//	while (i < aux) {
//		s.push(l.front());
//		l.pop_front();
//		i++;
//	}
//
//	while (l.size() > 0) {
//		s.push(l.back());
//		l.pop_back();
//	}
//}
//
//void solveCase(int n) {
//
//	int m;
//	cin >> m;
//
//	stack <int> s;
//	list <int> l;
//	int aux;
//	for (int i = 0; i < n; i++) {
//		cin >> aux;
//		l.push_front(aux);
//	}
//
//	for (int i = 0; i < n; i++) {
//		s.push(l.front());
//		l.pop_front();
//	}
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