#include <iostream>
#include <string>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::iterator;

bool solveCase(){

	char x;
	if(!(cin >> x))
		return false;

	int k;
	cin >> k;

	if(x == 'N'){
		set <int> intSet;
		int num;
		cin >> num;
		while(num != -1)
		{
			intSet.insert(num);
			cin >> num;
		}

		while(intSet.size() != k)
			intSet.erase(intSet.begin());

		for(set <int>::iterator i = intSet.begin(); i != intSet.end();)
			cout << *i++ << " ";
	}

	else if(x == 'P'){
		set <string> strSet;
		string str;
		cin >> str;
		while(str != "FIN")
		{
			strSet.insert(str);
			cin >> str;
		}

		while(strSet.size() != k)
			strSet.erase(strSet.begin());

		for(set <string>::iterator j = strSet.begin(); j != strSet.end();)
			cout << *j++ << " ";
	}	
	cout << endl;
	return true;
}

int main(){
	
	while(solveCase());
	return 0;
}