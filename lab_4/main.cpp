#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

using namespace std;

void print_v( auto vec ) {
	for(auto i : vec) {
		cout << i << endl;
	};
	cout << "--------------------------" << endl;
}

void task_one() {
    vector<string> cart = {  "wino", "buraki", "banany","cukier", "czekolada", "marchew" };
	print_v( cart );

	cout << cart.back() << endl;
	cart.pop_back();
	print_v( cart );

	cart.insert( cart.begin() + 2, "kawa");
	print_v( cart );

	for(int i = 0; i < cart.size(); i++) {
		if ( cart[i] == "cukier" ) {
			cart[i] = "cukierki";
		}
	}
	print_v( cart );

	cart.erase( std::remove( cart.begin(), cart.end(), "czekolada" ), cart.end());
	print_v( cart );

	std::sort (cart.begin(), cart.end() );
	print_v( cart );
}

vector<float> sum_fv( vector<float> a, vector<float> b ) {
	vector<float> res = {};

	if ( a.size() != b.size() ) return res;

	for(int i = 0; i < a.size(); i++) {
		res.insert( res.begin() + i, a[i] + b[i] );
	}

	return res;
}

float random() {
	mt19937 gen( rand() );
	uniform_real_distribution<float> distribution {0,100};
	return distribution(gen);
}

void task_two() {
	vector<float> a = { random(), random(), random() };
	vector<float> b = { random(), random(), random() };
	print_v( a );
	print_v( b );

	vector<float> v = sum_fv( a, b );
	print_v( v );
}

void task_three() {

}

void print_matrix( vector<vector<float>> matrix ) {
	for(auto x : matrix) {
		for(auto y : x) {
			cout << y << "\t";
		};
		cout << endl;
	};
}

vector<vector<float>> sum_matrix (  vector<vector<float>> a,  vector<vector<float>> b ) {
	 vector<vector<float>> res = {};

	 if ( a.size() == 0 ) res;
	 if ( a.size() != b.size() ) res;
	 if ( a[0].size() != b[0].size() ) res;

	 for(int i = 0; i < a.size(); i++) {
 		res.insert( res.begin() + i, sum_fv( a[i], b[i] ) );
 	}

	return res;
}

vector<vector<float>> multiple_matrix (  vector<vector<float>> a,  vector<vector<float>> b ) {
	 vector<vector<float>> res = {};

	 if ( a.size() == 0 ) return res;
	 if ( a[0].size() != b.size() ) return res;

	 for(int i = 0; i < a.size(); i++) {
		 vector<float> row = {};

		 for(int j = 0; j < b[0].size(); j++) {
			 float sum = 0;

			 for(int k = 0; k < b.size(); k++) {
				 sum += a[i][k] * b[k][j];
			 }

			 row.insert( row.begin() + j, sum );
		 }

		 res.insert( res.begin() + i, row );
	 }

	 return res;
}

void task_four() {
	vector<vector<float>> matrix_1 = { { 1, 2, 3}, { 5, 2, 3}, { 1, 2, 3} };
	vector<vector<float>> matrix_2 = { { 3, 7, 7}, { -1, 4, -3}, { -2, -2, -5} };
	vector<vector<float>> matrix_3 = { { 1, 2}, { 5, 2}, { 1, 2} };
	vector<vector<float>> matrix_4 = { { 3, 7, 7}, { -1, 4, -3} };

	vector<vector<float>> sum = sum_matrix( matrix_1, matrix_2 );
	vector<vector<float>> mul = multiple_matrix( matrix_3, matrix_4 );


	print_matrix( matrix_1 );
	cout << "PLUS" << endl;
	print_matrix( matrix_2 );
	cout << "ROWNA SIE" << endl;
	print_matrix( sum );
	cout << endl << endl;
	print_matrix( matrix_3 );
	cout << "RAZY" << endl;
	print_matrix( matrix_4 );
	cout << "ROWNA SIE" << endl;
	print_matrix( mul );
}

void task_five() {
	vector<int> vec = {};

	int num = -1;
	do {
		cin >> num;

		vec.push_back( num );
	} while ( num != -1 );
	vec.pop_back();

	cout << endl;
	print_v( vec );

	auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

	sort(vec.begin(), vec.end());
    last = std::unique(vec.begin(), vec.end());

	vec.erase(last, vec.end());
	print_v( vec );

//	int odds = cout_if( vec.begin(), vec.end(), count_odds);  
}


int main()
{
    // task_one();
	// task_two();
	// task_three();
	// task_four();
	 task_five();
	// task_six();


    return 0;
}
