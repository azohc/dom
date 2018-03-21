//#include <list>
//#include <iostream>
//
//using std::list;
//using std::cout;
//using std::endl;
//
//std::list<int> mergeLists(list<int> a, list<int> b) {
//	list<int> o;
//	list<int>::const_iterator itA, itB;
//
//	itA = a.cbegin();
//	itB = b.cbegin();
//
//	while (!a.empty() && !b.empty())
//	{
//		if (*itA < *itB)
//		{
//			o.push_back(*itA++);
//			a.pop_front();
//		}
//		else
//		{
//			o.push_back(*itB++);
//			b.pop_front();
//		}
//	}
//
//	if (a.empty())
//		do {
//			o.push_back(*itB++);
//			b.pop_front();
//		} while (!b.empty());
//	else
//		do {
//			o.push_back(*itA++);
//			a.pop_front();
//		} while (!a.empty());
//	
//	return o;
//}
//
//int main() {
//	
//	list <int> a;
//	list <int> b;
//	list <int>::const_iterator iter;
//	list <int>::reverse_iterator iterr;
//
//	for (int i = 0; i < 10; i++)
//	{
//		a.push_back(i + 1);
//		b.push_back(2 * i);
//	}
//
//	cout << "List A: " << endl;
//
//	for (iter = a.cbegin(); iter != a.cend(); iter++)
//		cout << *iter << " ";
//
//	cout << endl << "List B: " << endl;
//	for (iter = b.cbegin(); iter != b.cend(); iter++)
//		cout << *iter << " ";
//
//	list <int> m = mergeLists(a, b);	//using mergeList, which considers order
//	//list <int> m = a		//
//	//m.merge(b);			//using std::list function merge, parameter to this
//	cout << endl << "Merged lists: " << endl;
//	for (iter = m.cbegin(); iter != m.cend(); iter++)
//		cout << *iter << " ";
//
//	return 0;
//}