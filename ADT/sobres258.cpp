//#include <iostream>
//#include <list>
//
//using std::pair;
//using std::list;
//using std::cin;
//using std::cout;
//using std::endl;
//
//
//void solveCase(int n, int k) {
//
//	int N = n - k + 1;
//
//	list <pair <int, int> > sobres(k);
//	sobres.clear();
//
//	int aux, i = 0;
//
//	while (i < k) {
//		cin >> aux;
//
//		if(i == 0) 
//			sobres.push_back(pair <int, int>(aux, k + i++));
//		else {
//			if (!sobres.empty() && aux > sobres.back().first){
//				while(!sobres.empty() && aux > sobres.back().first)
//					sobres.pop_back();	
//				sobres.push_back(pair <int, int>(aux, k + i++));
//			}
//			else
//				sobres.push_back(pair <int, int>(aux, k + i++));
//		}
//	}
//
//	int displayed = 0;
//	while(displayed < N) {
//		
//		if(displayed == N - 1)
//			cout << sobres.front().first;
//		else
//			cout << sobres.front().first << " ";
//		
//		displayed++;
//
//		if (i == sobres.front().second)
//			sobres.pop_front();
//
//		if (displayed != N) {
//			cin >> aux;
//
//			if (!sobres.empty() && aux > sobres.back().first){
//				while(!sobres.empty() && aux > sobres.back().first)
//					sobres.pop_back();	
//				sobres.push_back(pair <int, int>(aux, k + i++));
//			}
//			else
//				sobres.push_back(pair <int, int>(aux, k + i++));
//		} 
//	}
//}
//
//int main() {
//
//	int n, k;
//	cin >> n >> k;
//
//	while (n != 0) {
//		solveCase(n, k);
//		cout << endl;
//		cin >> n >> k;
//	}
//
//	return 0;
//}
