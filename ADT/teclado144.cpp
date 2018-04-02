//#include <iostream>
//#include <string>
//#include <list>
//using namespace std;
//
//
//bool solveCase() {
//
//	string s;
//	if (!(getline(cin, s)))
//		return false;
//
//	// - = inicio
//	// + = fin
//	// * = ->
//	// 3 = supr
//
//	list <char> result;								//to store final string
//	list <char>::iterator it = result.begin();		//pseudocursor
//	unsigned i = 0;										//to traverse entire string
//
//	while (i < s.length()){
//		switch (s[i]) {
//		case '-': it = result.begin();
//			break;
//		case '+': it = result.end();
//			break;
//		case '*': if (it != result.end()) it++;
//			break;
//		case '3': if (it != result.end()) it = result.erase(it);
//			break;
//		default: result.insert(it, s[i]);
//			break;
//		}
//		i++;
//	}
//	
//	for (it = result.begin(); it != result.end(); it++)
//		cout << *it;
//	cout << "\n";
//
//
//	return true;
//}
//
//
//int main() {
//
//	while (solveCase());
//
//	return 0;
//}