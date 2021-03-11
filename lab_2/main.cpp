#include <iostream>
#include <math.h>
#include <random>
#include <chrono>
#include <cassert>
#include <stdlib.h>
#include <ctime>

using namespace std;


class Point2D {
    private:
    float x,y;

    public:
    Point2D(float sx=0, float sy=0): x{sx}, y{sy} {}

    void setX( float new_x ) {
        x = new_x;
    }

    void setY( float new_y ) {
        y = new_y;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }
};

class Circle {
private:
    Point2D m_point;
    float m_radius;
public:
    Circle( float s_x = 0, float s_y = 0, float r = 1 ) {
        Point2D p( s_x, s_y );
        m_point = p;
        m_radius = r;
    }

    Circle( const Point2D & s_p, float r = 1 ) {
        Point2D p( s_p.getX(), s_p.getY() );
        m_point = p;
        m_radius = r;
    }

    bool is_inside( const Point2D& p ) {
        float distance = sqrt( pow( p.getX() - m_point.getX(), 2 ) + pow( p.getY() - m_point.getY(), 2 ) );

        return distance < m_radius;
    }
};

class SmartArray {
private:
    int * m_arr;
    int m_length = 0;
public:
    SmartArray( int arr_length ) {
        int arr[ arr_length ];

        cout << "Tablica utworzona! Sk³adniki: ";
        for ( int i = 0; i < arr_length; i++ ) {
            arr[i] = rand();
            cout << arr[i] << ", ";
        }
        cout << endl;

        m_arr = arr;
        m_length = arr_length;
    }

    SmartArray( const SmartArray & other_arr ) {
        m_arr = other_arr.getAll();

        cout << "Tablica skopiowana! Sk³adniki: ";
        for ( int i = 0; i < other_arr.getSize(); i++ ) {
            cout << m_arr[i] << ", ";
        }
        cout << endl;
    }

    int * getAll() const {
        return m_arr;
    }

    int getSize() const {
        return m_length;
    }
};

float ulmans_pi_approximation( int precision ) {
    if ( precision <= 0 ) return 0;

    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution{-1.0,1.0};

    float circle_radius = 1;

    Circle circle( 0, 0, circle_radius );

    float square_area = 2 * 2;
    int n_inside = 0, n_all = precision;

    Point2D probe( 0, 0 );
    for( int i = 0; i < precision; i++ ) {
        float r_x = distribution( gen ), r_y = distribution(gen);
        probe.setX( r_x );
        probe.setY( r_y );

        if ( circle.is_inside( probe ) ) {
            n_inside++;
        }
    }

    float circle_area = (float) n_inside / (float) n_all * square_area;

    return (float)( circle_area / pow( circle_radius, 2 ) );
}

int main()
{
    setlocale( LC_ALL,"pl_PL" );
    setlocale( LC_ALL, "polish");
    srand((unsigned) time(0));
    //Point2D point( 10, 5 );

    /*
    cout << point.getX() << " " << point.getY() << endl;
    point.setX(15);
    cout << point.getX() << " " << point.getY() << endl << endl;
    */

    //Circle c1( 10, 5, 10 );
    //Circle c2( point, 12 );

    //cout << c1.is_inside( point ) << endl;

    //Point2D other_point( 21, 5 );
    //cout << c1.is_inside( other_point ) << endl;


    cout << "Dla 10e2 prób pi wynosi: " << ulmans_pi_approximation( 100 ) << endl;
    cout << "Dla 10e3 prób pi wynosi: " << ulmans_pi_approximation( 1000 ) << endl;
    cout << "Dla 10e4 prób pi wynosi: " << ulmans_pi_approximation( 10000 ) << endl;
    cout << "Dla 10e5 prób pi wynosi: " << ulmans_pi_approximation( 100000 ) << endl;
    cout << "Dla 10e6 prób pi wynosi: " << ulmans_pi_approximation( 1000000 ) << endl;

/*
    SmartArray arr( 10 );
    SmartArray arr_clone( arr );
*/
    return 0;
}
