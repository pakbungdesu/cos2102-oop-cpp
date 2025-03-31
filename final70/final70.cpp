

#include <iostream>
using namespace std;

class Food {
    int grade;
public:
    Food(int g) {
        setGrade(g);
    }

    void setGrade(int g) {
        if (g >= 1 && g <= 2) {
            grade = g;
        }
        else {
            grade = 1;
        }
    }

    int getGade() {
        return grade;
    }

    virtual string getType() = 0;

    virtual void show() {
        cout << "Grade: " << grade << endl;
    }
};

class Meat : public Food {
    int type;
public:
    Meat(int t, int g) : Food(g) {
        setType(t);
    }

    void setType(int t) {
        if (t >= 1 && t <= 3) {
            type = t;
        }
        else {
            type = 1;
        }
    }

    string getType() {
        if (type == 1) {
            return "Meat";
        }
        else if (type == 2) {
            return "Pork";
        }
        else {
            return "Sheep";
        }
    }

    void show() {
        Food::show();
        cout << "Type: " << getType() << endl;
    }

};

class Seafood : public Food {
    int type;
public:
    Seafood(int t, int g) : Food(g) {
        setType(t);
    }

    void setType(int t) {
        if (t >= 1 && t <= 4) {
            type = t;
        }
        else {
            type = 1;
        }
    }

    string getType() {
        if (type == 1) {
            return "Shrimp";
        }
        else if (type == 2) {
            return "Octopus";
        }
        else if (type == 3) {
            return "Seashell";
        }
        else {
            return "Fish";
        }
    }

    void show() {
        Food::show();
        cout << "Type: " << getType() << endl;
    }
};

class Poultry : public Food {
    int type;
public:
    Poultry(int t, int g) : Food(g) {
        setType(t);
    }

    void setType(int t) {
        if (t >= 1 && t <= 2) {
            type = t;
        }
        else {
            type = 1;
        }
    }

    string getType() {
        if (type == 1) {
            return "Chicken";
        }
        else {
            return "Duck";
        }
    }

    void show() {
        Food::show();
        cout << "Type: " << getType() << endl;
    }
};

ostream& operator<<(ostream& os, Food& food) {
    food.show();
    return os;
}

class Dish {
    static int count;
    double price;
    Food** food;
    int num;
public:
    Dish() {
        count++;
        price = 60;
        food = nullptr;
        num = 0;
    }

    Dish(double p, int n) {
        count++;
        setPrice(p);
        setNum(n);
    }

    Dish(Dish& dish) {
        count++;
        price = dish.price;
        num = dish.num;
        food = new Food * [num];

        for (int i = 0; i < num; i++) {
            food[i] = dish.food[i];
        }
    }

    virtual ~Dish() {
        count--;
        if (food != nullptr) {
            delete[] food;
            food = nullptr;
        }
    }

    void setNum(int n) {
        if (n <= 0) {
            n = 1;
        }
        if (n == num) {
            return;
        }
        num = n;
        if (food != nullptr) {
            delete[] food;
            food = nullptr;
        }
        food = new Food * [num]();
    }

    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
        else {
            price = 0;
        }
    }

    void setFood(int id, Food* f) {
        food[id] = f;
    }

    double getPrice() {
        return price;
    }

    Food* getFood(int id) {
        return food[id];
    }

    int getNum() {
        return num;
    }

    static int getCount() {
        return count;
    }

    void showDish() {
        cout << "Price: " << price << endl;
        cout << "Num: " << num << endl;
        for (int i = 0; i < num; i++) {
            food[i]->show();
        }
    }

    virtual void show() = 0;
};

int Dish::count;

class Khaopad : virtual public Dish {
    int size;
public:
    Khaopad() : Dish(55, 0) {
        size = 1;
    }

    Khaopad(int sz, double p, int n) : Dish(p, n) {
        setSize(sz);
    }

    Khaopad(Khaopad& kp) : Dish(kp.getPrice(), kp.getNum()) {
        size = kp.size;
        // set food
        for (int i = 0; i < kp.getNum(); i++) {
            setFood(i, kp.getFood(i));
        }
    }

    ~Khaopad() {}

    void setSize(int sz) {
        if (sz >= 1 && sz <= 2) {
            size = sz;
        }
        else {
            size = 1;
        }
    }

    int getSize() {
        return size;
    }

    void show() {
        cout << "Size: " << size << endl;
        Dish::showDish();
    }
};

class Potaek : virtual public Dish {
    int spicy;
public:
    Potaek() :Dish(350, 0) {
        spicy = 2;
    }

    Potaek(int sp, double p, int n) : Dish(p, n) {
        setSpicy(sp);
    }

    ~Potaek() {}

    Potaek(Potaek& pt) : Dish(pt.getPrice(), pt.getNum()) {
        spicy = pt.spicy;
        // set food
        for (int i = 0; i < pt.getNum(); i++) {
            setFood(i, pt.getFood(i));
        }
    }

    void setSpicy(int sp) {
        if (sp >= 1 && sp <= 2) {
            spicy = sp;
        }
        else {
            spicy = 2;
        }
    }

    int getSpicy() {
        return spicy;
    }

    void show() {
        cout << "Spicy: " << spicy << endl;
        Dish::showDish();
    }
};

class KhaopadPotaek : public Khaopad, public Potaek {
    bool special;
public:
    KhaopadPotaek() : Khaopad(1, 150, 0) {
        special = false;
        setSpicy(1);
    }

    KhaopadPotaek(bool spe, int sz, double prc, int n, int spi)
        : Dish(prc, n), Khaopad(sz, prc, n), Potaek(spi, prc, n) {
        special = spe;
        setSpicy(spi);
    }

    ~KhaopadPotaek() {}

    KhaopadPotaek(KhaopadPotaek& kpt) : Khaopad(kpt.getSize(), kpt.getPrice(), kpt.getNum()) {
        special = kpt.special;
        setSpicy(kpt.getSpicy());
        // set food
        for (int i = 0; i < kpt.getNum(); i++) {
            setFood(i, kpt.getFood(i));
        }
    }

    void setSpecial(bool spe) {
        special = spe;
    }

    bool getSpecial() {
        return special;
    }

    void set(double prc) {
        setPrice(prc);
    }

    void set(bool spe) {
        special = spe;
    }

    void set(int sz, int spi) {
        setSize(sz);
        setSpicy(spi);
    }

    void show() {
        cout << "Size: " << getSize() << endl;
        cout << "Spicy: " << getSpicy() << endl;
        cout << "Special: " << special << endl;
        Dish::showDish();
    }
};

ostream& operator<<(ostream& os, Dish& dish) {
    dish.show();
    return os;
}

class Pinto {
    Dish** dish;
    int num;
public:
    Pinto() {
        dish = nullptr;
        num = 0;
    }

    Pinto(int n) {
        setNum(n);
    }

    ~Pinto() {
        if (dish != nullptr) {
            delete[] dish;
            dish = nullptr;
        }
    }

    double getPrice() {
        double res = 0;
        for (int i = 0; i < num; i++) {
            res += dish[i]->getPrice();
        }
        return res;
    }

    bool operator> (Pinto& pin) {
        return getPrice() > pin.getPrice();
    }

    void setDish(int id, Dish* dsh) {
        dish[id] = dsh;
    }

    void setNum(int n) {
        if (n <= 0) {
            n = 1;
        }
        if (n == num) {
            return;
        }
        num = n;
        if (dish != nullptr) {
            delete[] dish;
            dish = nullptr;
        }
        dish = new Dish * [num];
    }

    int getNum() {
        return num;
    }

    Dish* getDish(int id) {
        return dish[id];
    }
};

class Box {
    Pinto** pinto;
    int num;
public:
    Box() {
        pinto = nullptr;
        num = 0;
    }

    Box(int n) {
        setNum(n);
    }

    ~Box() {
        if (pinto != nullptr) {
            delete[] pinto;
            pinto = nullptr;
        }
    }

    double getPrice() {
        double res = 0;
        for (int i = 0; i < num; i++) {
            res += pinto[i]->getPrice();
        }
        return res;
    }

    int getNum() {
        return num;
    }

    Pinto* getPinto(int id) {
        return pinto[id];
    }

    void setPinto(int id, Pinto* pin) {
        pinto[id] = pin;
    }

    void setNum(int n) {
        if (n <= 0) {
            n = 1;
        }
        if (n == num) {
            return;
        }
        num = n;
        if (pinto != nullptr) {
            delete[] pinto;
            pinto = nullptr;
        }
        pinto = new Pinto * [num];
    }

    void show() {
        cout << "Total pinto: " << num << endl;
        for (int i = 0; i < num; i++) {
            cout << "Pinto " << i + 1 << endl;

            int totaldish = pinto[i]->getNum();
            for (int j = 0; j < totaldish; j++) {
                cout << "Dish " << j + 1 << endl;
                cout << *(pinto[i]->getDish(j));
            }

        }
    }
};

int main()
{
    Food* food[8] = { new Meat(1, 2), new Meat(2, 2), new Seafood(1, 1), new Seafood(2, 1),
    new Seafood(3, 1), new Seafood(4, 2), new Poultry(1, 1), new Poultry(2, 1) };

    for (int i = 0; i < 8; i++) {
        food[i]->show();
    }

    Khaopad* khaopadMukai = new Khaopad(1, 80, 2);
    khaopadMukai->setFood(0, food[1]);
    khaopadMukai->setFood(1, food[6]);

    Potaek* potaek = new Potaek(2, 220, 1);
    potaek->setFood(0, food[5]);

    Khaopad* khaopadBeef = new Khaopad(2, 150, 1);
    khaopadBeef->setFood(0, food[0]);

    KhaopadPotaek* khaopadPotaek = new KhaopadPotaek(false, 1, 160, 3, 1);
    khaopadPotaek->setFood(0, food[2]);
    khaopadPotaek->setFood(1, food[3]);
    khaopadPotaek->setFood(2, food[4]);

    cout << "----- operator << -----" << endl;
    cout << *khaopadMukai << endl;
    cout << *potaek << endl;
    cout << *khaopadBeef << endl;
    cout << *khaopadPotaek << endl;

    Pinto* pinto[2] = { new Pinto(2), new Pinto(2) };
    pinto[0]->setDish(0, khaopadMukai);
    pinto[0]->setDish(1, potaek);

    pinto[1]->setDish(0, khaopadBeef);
    pinto[1]->setDish(1, khaopadPotaek);

    cout << "----- pinto -----" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Pinto " << i + 1 << endl;
        int pindish = pinto[i]->getNum();

        for (int j = 0; j < pindish; j++) {
            pinto[i]->getDish(j)->show();
        }
    }

    cout << endl << "----- box -----" << endl;
    Box* box = new Box(2);
    box->setPinto(0, pinto[0]);
    box->setPinto(1, pinto[1]);
    box->show();

    cout << "1. Total box price: " << box->getPrice() << endl;

    double total = 0;
    for (int i = 0; i < box->getNum(); i++) {
        int thispin = box->getPinto(i)->getNum();

        for (int j = 0; j < thispin; j++) {
            total += box->getPinto(i)->getDish(j)->getPrice();
        }
    }

    cout << "2. Total box price: " << total << endl;

    khaopadPotaek->set(1, 1);
    khaopadPotaek->set(true);
    khaopadPotaek->set(127.5);
    cout << "----- overloading -----" << endl;
    cout << *khaopadPotaek << endl;

    Khaopad* khaopadPedyang = new Khaopad(2, 190, 1);
    khaopadPedyang->setFood(0, food[7]);

    Khaopad* myKhaopad(khaopadPedyang);
    cout << "----- khaopadPedyang -----" << endl;
    cout << *khaopadPedyang << endl;
    cout << "----- myKhaopad -----" << endl;
    cout << *myKhaopad << endl;

    delete khaopadPedyang, myKhaopad;

    cout << "----- type in box -----" << endl;
    int countGrade = 0;
    for (int i = 0; i < box->getNum(); i++) {
        int thispin = box->getPinto(i)->getNum();

        for (int j = 0; j < thispin; j++) {
            int thisdish = box->getPinto(i)->getDish(j)->getNum();

            for (int k = 0; k < thisdish; k++) {
                if (box->getPinto(i)->getDish(j)->getFood(k)->getGade() == 1) {
                    countGrade++;
                }
                cout << "Type: " << box->getPinto(i)->getDish(j)->getFood(k)->getType() << endl;
            }
        }
    }
    cout << "Std. grade: " << countGrade << endl;

    // delete
    for (int i = 0; i < 8; i++) {
        delete food[i];
    }

    for (int i = 0; i < 2; i++) {
        delete pinto[i];
    }

    delete khaopadMukai, potaek, khaopadBeef, khaopadPotaek, box;
}
