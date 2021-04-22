#include <iostream>

using namespace std;

class Complex {
    float real;
	float imag;

public:
	Complex( float, float );
	float getReal( void ) const;
	void setReal( float );
	float getImag( void ) const;
	void setImag( float );

	Complex operator + ( Complex );
	Complex& operator ++ ( int );
	Complex& operator = ( const Complex& );
	bool operator == ( const Complex );
	friend ostream& operator << ( ostream& out, const Complex& c );
	friend istream& operator >> ( istream& in, Complex& c );
};

Complex::Complex( float r = 0, float i = 0 ) {
	real = r;
	imag = i;
}

Complex Complex::operator + ( Complex that ) {
	return Complex( this->getReal() + that.getReal(), this->getImag() + that.getImag() );
}

Complex& Complex::operator ++ ( int i ) {
	this->setReal( this->getReal() + 1 );
	this->setImag( this->getImag() + 1 );
}

Complex& Complex::operator = ( const Complex& rhs ) {
	if( this != &rhs ) {
		this->setReal( rhs.getReal() );
		this->setImag( rhs.getImag() );
	}
	return * this;
}

ostream& operator << ( ostream & out, const Complex &c )  {
	out << c.getReal() << std::showpos << c.getImag() << "i";
	out << std::noshowpos;
	return out;
}

istream& operator >> ( istream & in, Complex &c )  {
	float r;
	float i;

	in >> r;
	in >> i;

	c.setReal( r );
	c.setImag( i );

	return in;
}

bool Complex::operator == ( Complex that ) {
	return this->getReal() == that.getReal() && this->getImag() == that.getImag();
}

float Complex::getReal() const {
	return real;
}

void Complex::setReal( float r ) {
	real = r;
}

float Complex::getImag() const {
	return imag;
}

void Complex::setImag( float i ) {
	imag = i;
}



void task_one() {
	Complex c1(10,5);
    Complex c2(10,5);

	Complex sum = c1 + c2;
    cout << sum.getReal() << " " << sum.getImag() << endl;

    sum++;
    cout << sum.getReal() << " " << sum.getImag() << endl;

    bool eq_1 = c1 == c2;
    bool eq_2 = c1 == sum;

	cout << eq_1 << endl;
    cout << eq_2 << endl;

    cout << sum << endl;

    Complex c3;
    cin >> c3;
    cout << c3 << endl;

    c1 = c3;
    cout << c1 << endl;
}

void rec_reverse( string text ) {
	if ( text.length() == 0 ) return;

	cout << text.back();
    text.pop_back();

	rec_reverse( text );
}

void task_two() {
	cout << "Wpisz zdanie: ";
	string text;
	getline( cin, text);
	rec_reverse( text );
}

int main() {

	task_one();
    // task_two();

    return 0;
}
