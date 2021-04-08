#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <array>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void task_one() {
	map<string, string> phones;

	string opt;
	cout << "Podaj imie: " << endl;
	cin >> opt;

	while ( opt != "exit" ) {
		if ( phones.count( opt ) > 0 ) {
			cout << "Numer tel: " << phones[ opt ] << endl << endl;
		} else {
			string phone_number;
			cout << "Nie znaleziono numeru tel. Podaj numer tel: ";
			cin >> phone_number;
			cout << endl;

			phones.insert ( phones.begin(), pair<string,string>(opt,phone_number));
		}

		cout << "Podaj imie: " << endl;
		cin >> opt;
	}
}

void task_two() {
	string sentence;
	cout << "Wpisz zdanie: ";
	getline(cin,sentence);

	map<char,int> counter;
	for (string::size_type i = 0; i < sentence.size(); i++) {
		if ( ! isalpha( sentence[i] ) ) continue;

		if ( counter.count( sentence[i] ) > 0 ) {
			counter[ sentence[i] ] += 1;
		} else {
			counter.insert ( counter.begin(), pair<char,int>(sentence[i],1));
		}
    }

    cout << endl;
    for (auto const& x : counter){
        cout << x.first << ":" << x.second << endl;
    }
}

void task_three() {
	vector<string> v;

	string opt;
	cin >> opt;
	while ( opt != "end" ) {
		v.insert( v.begin(), opt );
		cin >> opt;
	}

	map<string,vector<int>> c;
	for ( int i = 0; i < v.size(); i++ ) {
		if ( c.count( v[i] ) > 0 ) {
            c[ v[i] ].insert( c[ v[i] ].begin(), v.size() - i );
		} else {
			c.insert( c.begin(), pair<string,vector<int>>( v[i], { v.size() - i } ) );
		}
	}

	cout << endl << endl;
    for (auto const& x : c){
        cout << x.first << ":";
        for ( auto const& y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void task_four() {
	ifstream file("ips.txt");

	map<string, string> dns;
	map<string, string> reverse_dns;;

	string ip, domain;
	while (file >> ip >> domain) {
		if ( dns.count( ip ) > 0 ) {
			dns[ ip ] = domain;
		} else {
			dns.insert( dns.begin(), pair<string,string>( ip, domain ) );
		}

		if ( reverse_dns.count( domain ) > 0 ) {
			reverse_dns[ domain ] = ip;
		} else {
			reverse_dns.insert( reverse_dns.begin(), pair<string,string>( domain, ip ) );
		}
	}


	string search_phrase;
	cin >> search_phrase;
	if ( dns.count( search_phrase ) > 0 ) {
		cout << dns[ search_phrase ] << endl;
	} else if ( reverse_dns.count( search_phrase ) > 0 ) {
		cout << reverse_dns[ search_phrase ] << endl;
	} else {
		cout << "404 not found" << endl;
	}
}

int main()
{
	//task_one();
	// task_two();
    //task_three();
	task_four();
    return 0;
}
