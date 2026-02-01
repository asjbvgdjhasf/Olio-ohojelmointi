#include <iostream>
#include <string>

using namespace std;

class Pankkitili {
protected:
    string omistaja;
    double saldo;

public:
    Pankkitili(string nimi) {
        omistaja = nimi;
        saldo = 0;
    }

    virtual bool deposit(double summa) {
        if (summa <= 0) {
            return false;
        } else {
            saldo = saldo + summa;
            return true;
        }
    }

    virtual bool withdraw(double summa) {
        if (summa <= 0) {
            return false;
        } else if (summa > saldo) {
            return false;
        } else {
            saldo = saldo - summa;
            return true;
        }
    }

    double getBalance() {
        return saldo;
    }
};

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(string nimi, double raja) : Pankkitili(nimi) {
        luottoRaja = raja;
    }

    bool withdraw(double summa) override {
        if (summa <= 0) {
            return false;
        } else if (saldo - summa < -luottoRaja) {
            return false;
        } else {
            saldo = saldo - summa;
            return true;
        }
    }

    bool deposit(double summa) override {
        if (summa <= 0) {
            return false;
        } else if (saldo + summa > 0) {
            return false;
        } else {
            saldo = saldo + summa;
            return true;
        }
    }
};

class Asiakas {
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(string n, double luotto)
        : kayttotili(n), luottotili(n, luotto) {
        nimi = n;
    }

    void showSaldo() {
        cout << nimi << " käyttötili: " << kayttotili.getBalance() << endl;
        cout << nimi << " luottotili: " << luottotili.getBalance() << endl;
    }

    bool talletus(double summa) {
        return kayttotili.deposit(summa);
    }

    bool nosto(double summa) {
        return kayttotili.withdraw(summa);
    }

    bool luotonNosto(double summa) {
        return luottotili.withdraw(summa);
    }

    bool luotonMaksu(double summa) {
        return luottotili.deposit(summa);
    }

    bool tiliSiirto(double summa, Asiakas& toinen) {
        if (summa <= 0) {
            return false;
        } else if (kayttotili.withdraw(summa)) {
            toinen.kayttotili.deposit(summa);
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Asiakas a1("Matti", 1000);
    Asiakas a2("Teppo", 500);

    a1.talletus(300);
    a1.luotonNosto(200);

    a1.tiliSiirto(100, a2);

    a1.showSaldo();
    cout << endl;
    a2.showSaldo();

    return 0;
}
