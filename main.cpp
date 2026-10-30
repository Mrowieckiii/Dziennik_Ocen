#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


struct przedmiot {
    string nazwa;
    double ocena;
};

int main() {
    bool dziala = true;
    int wybor;
    vector<przedmiot>dziennik;
    while (dziala){
        cout << "----Dziennik Ocen----"<<endl;
        cout << "1.Dodaj Ocene i Przedmiot"<<endl;
        cout << "2.Pokaz wszystkie oceny i srednia"<<endl;
        cout << "0.Wyjscie" << endl;
        cout<< "Wybierz opcje (0-2)!" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                przedmiot p;
                cout << "Prosze podac ocene(1-6): " << endl;
                cin >> p.ocena;

                if (cin.fail()) {
                    cout << "Blad!! musisz podac liczbe!, nie tekst" <<endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (p.ocena <= 6 && p.ocena > 0 ) {
                    cout << "Ocena dodana!!!" <<endl;
                    cout << "a teraz prosze dodac przedmiot: " << endl;
                    cin >> p.nazwa;
                    dziennik.push_back(p);
                    cout << "Dodano do dziennika!!"<<endl;
                }else {
                    cout << "Wybierz ocene z przedzialu 1-6!!!" <<endl;
                }
                break;
            }
            case 2: {
                double suma = 0.0;
                if (dziennik.empty()) {
                    cout << "Dziennik jest pusty!! dodaj cos do niego!!" <<endl;
                }else {
                    for (przedmiot p : dziennik) {
                        suma += p.ocena;
                        cout  << " Przedmiot: " << p.nazwa <<  "\n Ocena:  " << p.ocena << endl;
                    }
                    double srednia = suma / dziennik.size();
                    cout << "Srednia: " << srednia << endl;
                }
                break;
            }
            case 0:
                cout <<"Koniec programu!"<<endl;
                dziala = false;
                break;
            default:
                cout << "Nie poprawna liczba!!"<<endl;
                break;
        }

    }
}