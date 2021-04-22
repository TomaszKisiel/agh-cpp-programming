#include <iostream>
#include <vector>
#include <stdexcept>
#include <math.h>
#include "person.hpp"
#include "student.hpp"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::stoi;
using std::invalid_argument;
using std::out_of_range;
using std::string;

void first_part_tasks() {
	Person adam( "Adam", "Nowak", "12345678901" );
	Student jan( "Jan", "Kowalski", "1234567902", "123001", "elektronika" );

	cout << adam.toString() << endl;
	cout << jan.toString() << endl;

	vector<Person> people = {
		Student( "Tomasz", "Budyn", "12345678903", "123002", "budowlanka" ),
		Student( "Przemyslaw", "Hutnik", "12345678904", "123003", "hutnictwo" ),
		Student( "Slawek", "Gornik", "12345678905", "123004", "gornictow" )
	};

	cout << endl;
	for ( const auto o : people ) {
		cout << o.toString() << endl;
	}

	vector<Person*> people_w = {
		new Student( "Tomasz", "Budyn", "12345678903", "123002", "budowlanka" ),
		new Student( "Przemyslaw", "Hutnik", "12345678904", "123003", "hutnictwo" ),
		new Student( "Slawek", "Gornik", "12345678905", "123004", "gornictow" )
	};

	cout << endl;
	for ( const auto o : people_w ) {
		cout << static_cast<Student*>(o)->toString() << endl;
	}
}

void solve_quadratic_equation( int a, int b, int c, float * res ) {
	if ( a == 0 ) throw "Cannot divide by zero.";

	float delta = ( b*b - 4 * a * c );
	if ( delta < 0 ) throw "Equation has no real solution.";

	float x0 = ( -b + sqrt( delta ) ) / ( 2 * a );
	float x1 = ( -b - sqrt( delta ) ) / ( 2 * a );

	res[0] = x0;
	res[1] = x1;
}

void task_six() {
	float a,b,c;
	cout << "PODAJ WSPOLCZYNNIKI: ";
	cin >> a >> b >> c;

	float results[2];
	try {
		solve_quadratic_equation( a, b, c, results );

		cout << "x0 = " << results[0] << ", x1 = " << results[1] << endl;
	} catch( const char * e ) {
		cout << e << endl;
	}
}

void task_seven() {
	string in;
	cin >> in;

	int num_dec;

	try {
		num_dec = stoi( in );
	} catch(invalid_argument& e){
		cout << "Invalid argument given." << endl;
		return;
	} catch(out_of_range& e){
		cout << "Givene value is out of the range." << endl;
		return;
	}

	// std::stringstream stream;
	// stream <<std::hex << num_dec << endl;
	// string num_hex( stream.str() );
	//
	// cout << num_hex << endl;
}

void task_eight() {

}

int main() {
	first_part_tasks();
	// task_six();
	//task_seven();
	// task_eight();
    return 0;
}
