#include <iostream>
#include <string>
using namespace std;

class Chef {
protected:
    string chefName;
    
public:
    Chef(string name) : chefName(name) {
        cout << "Chef " << chefName << " konstruktori" << endl;
    }
    
    ~Chef() {
        cout << "Chef " << chefName << " destruktori" << endl;
    }
    
    string getName() {
        return chefName;
    }
    
    int makeSalad(int ingredients) {
        int portions = ingredients / 5;
        cout << "Chef " << chefName << " with " << ingredients << " items can make salad " << portions << " portions" << endl;
        return portions;
    }
    int makeSoup(int ingredients) {
        int portions = ingredients / 3;
        cout << "Chef " << chefName << " with " << ingredients << " items can make soup " << portions << " portions" << endl;
        return portions;
    }
};

class ItalianChef : public Chef {
private:
    string password = "pizza";
    int flour;
    int water;
    
    int makePizza() {
    int pizzas;
    if (flour / 5 < water / 5) {
        pizzas = flour / 5;
    } else {
        pizzas = water / 5;
    }
    cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas" << endl;
    return pizzas;
    }
    
public:
    ItalianChef(string name) : Chef(name) {
        cout << "ItalianChef " << chefName << " konstruktori" << endl;
    }
    
    ~ItalianChef() {
        cout << "ItalianChef " << chefName << " destruktori" << endl;
    }
    
    bool askSecret(string pw, int f, int w) {
        flour = f;
        water = w;
        
        if (pw == password) {
            cout << "Password ok" << endl;
            makePizza();
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Chef gordon("Gordon");
    gordon.makeSalad(11);
    gordon.makeSoup(14);
    cout << endl;
    

    ItalianChef mario("Mario");
    mario.makeSalad(9);
    mario.askSecret("pizza", 12, 12);
    cout << endl;
    
    return 0;
}