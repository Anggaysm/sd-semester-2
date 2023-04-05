#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int *pc,c;
    c = 22;
    cout << "Alamat variable c : "<< &c << endl;
    cout << "Nilai Variable c : "<< c<< endl << endl;
    pc = &c;
    cout << "Alamat variable pc : "<< pc << endl;
    cout << "Nilai Variable pc : "<< *pc<< endl<<endl;
    c = 11;
    cout << "Alamat variable pc : "<< pc << endl;
    cout << "Nilai Variable pc : "<< *pc<< endl<<endl;
    *pc = 2;
    cout << "Alamat variable c : "<< &c << endl;
    cout << "Nilai Variable c : "<< c<< endl;
}
