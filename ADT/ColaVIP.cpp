//#include <queue>
//#include <iostream>
//#include <string>
//using std::cin;
//using std::cout;
//using std::endl;
//using std::queue;
//
//void solveCase() {
//
//	int P, E, A;		//P = prioridades   E = llegadas/salidas	A = aforo
//
//	cin >> P >> E >> A;
//
//	queue <int> *v = new queue <int>[P];
//	char sign;
//	int p, id, pplInside = 0, j = 0;
//	bool isEmpty = true;
//	
//	for (int i = 0; i < E; ++i) {
//		cin >> sign;
//		if (sign == '-') {
//			pplInside--;
//			if (pplInside != A) {	//si cabe alguien
//				isEmpty = true;
//				j = 0;
//				while (isEmpty && j < P) {
//					if (!v[j].empty())
//						isEmpty = false;	// y hay gente en alguna cola
//					else
//						j++;
//				}
//				if (!isEmpty) {
//					pplInside++;
//					v[j].pop();
//				}
//			}
//		}
//		else {
//			cin >> p >> id;
//			if (pplInside == A)	//si la cantidad de gente dentro es = al alforo, a la puta cola
//				v[p].push(id);
//			else
//				pplInside++;
//		}
//	}
//
//	isEmpty = true;
//	j = 0;
//	while (isEmpty && j < P) {
//		if (!v[j].empty())
//			isEmpty = false;	// si hay gente en alguna cola
//		else
//			j++;
//	}
//	j = 0;
//	if (isEmpty)
//		cout << "NADIE";		
//	else 
//		while (j < P) {
//			while (!v[j].empty()) {
//				cout << v[j].front() << " ";
//				v[j].pop();
//			}
//			j++;
//		}
//	
//	cout << endl;
//}
//
//int main() {
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//		solveCase();
//
//	return 0;
//}