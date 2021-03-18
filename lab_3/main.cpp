#include <iostream>
#include <string>
#include <locale>
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;


void task_one() {
    string text;
    getline(cin,text);

    int counter = 0;
    for ( string::size_type i = 0; ( i = text.find_first_of( "0123456789", i ) ) != string::npos; i++ ){
        counter++;
    }

    cout << "Liczba cyfr w zdaniu: " << counter <<endl;

}

string string_reverse(const string &in) {
    return string(in.rbegin(),in.rend()); ;
}

void task_two() {
    ifstream input("two.txt");
    ofstream output("output.txt", ios::out );

    string line;
    while (getline(input, line)) {
        cout << line << " -> " << string_reverse( line ) << endl;
        output << string_reverse( line );
    }

    output.close();
    input.close();
}

void task_three() {
    string text = "Contgratulations Mrs. <name>, you and Mr. <name> are the lucky recipients of a trip for two to XXXXXX. Your trip top XXX is already scheduled ";

    std::size_t found = text.find("<name>");
    while( found != std::string::npos ) {
        text.replace( found, 6, "Smith");
        found = text.find("<name>");
    }

    text = std::regex_replace(text, std::regex("[X]{1,}"), "Siberia");

    size_t lucky_pos = text.find("lucky");
    if ( lucky_pos != std::string::npos) {
        text.replace( lucky_pos, 5, "unlucky");
    }

    text += "in December";

    cout << text << endl;
}

void task_four() {
    string text_a;
    string text_b;

    getline(cin,text_a);
    getline(cin,text_b);

    bool flag = false;
    for (string::size_type i = 0; i < text_b.size(); i++) {
        string temp = ( text_b + " " ).substr( i, string::npos ) + ( text_b + " " ).substr( 0, i );

        cout << temp << endl;

        if ( ( text_a + " " ).compare( temp ) == 0 ) {
            flag = true;
            break;
        }
    }

    if ( flag ) {
        cout << "S¹ wzajemnym przesuniêciem cyklicznym!";
    } else {
        cout << "Nie s¹ wzajemnym przesuniêciem cyklicznym!";
    }
}

int main()
{
    std::setlocale(LC_ALL, "pl_PL" );
    std::setlocale(LC_ALL, "polish");

    //task_one();
    //task_two();
    //task_three();
    task_four();

    return 0;
}
