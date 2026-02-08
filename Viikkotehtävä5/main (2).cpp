#include <iostream>
#include <string>
using namespace std;

class Seuraaja {
    
private:
    string nimi;
    
public:
    Seuraaja* next;
    
    Seuraaja(string n) : nimi(n), next(nullptr) {
        cout << "Luodaan seuraaja " << nimi << endl;
    }
    
    string getNimi() {
        return nimi;
    }
    
    void paivitys(string viesti) {
        cout << "Seuraaja " << nimi << " sai viestin " << viesti << endl;
    }
};

class Notifikaattori {
    
private:
    Seuraaja* seuraajat;
    
public:
    Notifikaattori() : seuraajat(nullptr) {
        cout << "Luodaan notifikaattori" << endl;
    }
    
    void lisaa(Seuraaja* s) {
        cout << "Notifikaattori lisää seuraajan " << s->getNimi() << endl;
        s->next = seuraajat;
        seuraajat = s;
    }
    
    void poista(Seuraaja* s) {
        cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << endl;
        
        if (seuraajat == nullptr) return;
        
        if (seuraajat == s) {
            seuraajat = seuraajat->next;
            return;
        }
        
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen->next != nullptr) {
            if (nykyinen->next == s) {
                nykyinen->next = s->next;
                return;
            }
            nykyinen = nykyinen->next;
        }
    }
    
    void tulosta() {
        cout << "Notifikaattorin seuraajat:" << endl;
        
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            cout << "Seuraaja " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }
    
    void postita(string viesti) {
        cout << "Notifikaattori postaa viestin " << viesti << endl;
        
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
};

int main() {
    Notifikaattori n;
    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Tämä on viesti 1");

    n.poista(&b);

    n.postita("Tämä on viesti 2");

    return 0;
}