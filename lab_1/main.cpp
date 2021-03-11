#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <string>

void task_one() {
    int a,b,c;

    std::cout << "Podaj wspolczynnik a: ";
    std::cin >> a;

    std::cout << "Podaj wspolczynnik b: ";
    std::cin >> b;

    std::cout << "Podaj wspolczynnik c: ";
    std::cin >> c;

    int delta = b*b - 4*a*c;
    if ( delta < 0 ) {
        std::cout << "Brak rozwiazan rzeczywistych" << std::endl;
        return;
    }

    float x1 = ( -b + sqrt( delta ) ) / ( 2 * a );
    float x2 = ( -b - sqrt( delta ) ) / ( 2 * a );

    std::cout << "Rozwiazania rzeczywiste rownania " << a << "x^2 + " << b << "x + " << c << " to: " << x1 << " oraz " << x2 << "." << std::endl;
}

void task_two() {
    int start_cash, capitalization_amount;
    float interest;

    std::cout << "Podaj kwote poczatkowa: ";
    std::cin >> start_cash;

    std::cout << "Podaj wysokokosc oprocetowania: ";
    std::cin >> interest;

    std::cout << "Podaj ilosc kapitalizacji: ";
    std::cin >> capitalization_amount;

    float end_cash = start_cash;
    for ( int i = 0; i < capitalization_amount; i++ ) {
        end_cash += end_cash * interest / 100;
    }

    std::cout << "Kwota " << start_cash << " po " << capitalization_amount << " kapitalizacjach z oprocentowaniem " << interest << " wynosi " << end_cash << std::endl;
}

void task_three() {
    int tries_left = 5;

    srand(time(NULL));
    int selected_number = rand() % 101;
    while( tries_left > 0 ) {
        std::cout << "Odgadnij liczbe! ";

        int answer;
        std::cin >> answer;
        if ( answer < selected_number ) {
            std::cout << "Niestety, wylosowana liczba jest wieksza." << std::endl;
        } else if ( answer > selected_number ) {
            std::cout << "Niestety, wylosowana liczba jest mniejsza." << std::endl;
        } else {
            std::cout << "BRAWO!!! Odgadles wylosowana liczbe." << std::endl;
            break;
        }

        tries_left -= 1;

        if ( tries_left == 0 ) {
            std::cout << "Niestety, przekroczyles dozwolona liczbe prob." << std::endl;
        }
    }
}

void pass_array_by_pointer( double * arr, int arr_length ) {
    double sum = 0;
    for ( int i = 0; i < arr_length; i++ ) {
        sum += arr[i];
    }

    double avg = sum / arr_length;
    std::cout<< "Srednia arytmetyczna: " << avg << std::endl;

    double under_sqrt_sum = 0;
    for ( int i = 0; i < arr_length; i++ ) {
        under_sqrt_sum += ( arr[i] - avg ) * ( arr[i] - avg );
    }

    double under_sqrt = under_sqrt_sum / arr_length;
    double deviation = sqrt( under_sqrt );

    std::cout<< "Odchylenie standardowe: " << deviation << std::endl;
}

void task_four() {
    int array_length;

    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> array_length;

    srand(time(NULL));

    std::cout << "Przygotowuje tablice z wartosciami: " << std::endl;;
    double values[ array_length ] = { 0 };
    for ( int i = 0; i < array_length; i++ ) {
        values[i] = ( ( double )( rand() % 11 ) - 5 ) / 10;
        std::cout << values[i] << ",\t";
    }
    std::cout << std::endl << std::endl;

    pass_array_by_pointer( values, array_length );
}

void task_five() {
    int num;

    std::cout << "WprowadŸ liczbê do przekonwertowania: ";
    std::cin >> num;

    std::bitset<64> bits( num );

    std::string bits_string = bits.to_string();

    for (std::string::size_type i = 0; i < bits_string.size(); i++) {
        if ( i != 0 && i % 8 == 0 ) std::cout << " ";

        std::cout << bits_string[i];
    }
}

void task_six() {
    int num;

    std::cout << "WprowadŸ liczbe: ";
    std::cin >> num;

    int max_divivder = 1;
    for ( int i = 1; i < num; i++ ) {
        if ( num % i == 0 ) max_divivder = i;
    }

    std::cout << "Najwiêkszy " << num << " dzielnik to " << max_divivder << std::endl;
}

void task_seven() {
    int a,b;
    char opt;

    std::cout << "WprowadŸ liczbe a: ";
    std::cin >> a;

    std::cout << "WprowadŸ liczbe b: ";
    std::cin >> b;

    std::cout << "WprowadŸ operator: ";
    std::cin >> opt;

    switch( opt != 'q' ) {
    case '+':
        std::cout << "Wynik: " << a + b << std::endl;
        break;
    case '-':
        std::cout << "Wynik: " << a - b << std::endl;
        break;
    case '*':
        std::cout << "Wynik: " << a * b << std::endl;
        break;
    case '/':
        std::cout << "Wynik: " << a / b << std::endl;
        break;
    default:
        if ( opt != 'q' ) std::cout << "Nie poprawna operacja!" << std::endl;
        break;
    }
}

int main()
{
    std::setlocale(LC_ALL, "pl_PL" );
    std::setlocale(LC_ALL, "polish");

    char opt;

    while( opt != 'e' ) {
        std::cout << "Ktore zadanie uruchomic? ";
        std::cin >> opt;

        switch ( opt ) {
        case '1':
            task_one();
            break;
        case '2':
            task_two();
            break;

        case '3':
            task_three();
            break;

        case '4':
            task_four();
            break;

        case '5':
            task_five();
            break;

        case '6':
            task_six();
            break;

        case '7':
            task_seven();
            break;
        default:
            if ( opt != 'e' ) std::cout << "Nieznane zadanie!" << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}
