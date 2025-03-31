


#include <iostream>
using namespace std;

class Fabric {
    int color;
public:
    Fabric(int c) {
        if (c >= 1 && c <= 4) {
            color = c;
        }
        else {
            color = 1;
        }
    }

    int getColor() {
        return color;
    }

    virtual string getDetail() {
        if (color == 1) {
            return "white";
        }
        else if (color == 2) {
            return "green";
        }
        else if (color == 3) {
            return "brown";
        }
        else {
            return "grey";
        }
    }
    virtual void show() = 0;
};

class Cotton : public Fabric {
    int type;
public:
    Cotton(int t, int c) : Fabric(c) {
        if (t >= 1 && t <= 3) {
            type = t;
        }
        else {
            type = 1;
        }
    }

    int getType() {
        return type;
    }

    string getDetail() {
        if (type == 1) {
            return "thickest";
        }
        else if (type == 2) {
            return "medium";
        }
        else {
            return "light";
        }
    }

    void show() {
        cout << "Cotton type: " << getDetail() << endl;
        cout << "Color: " << Fabric::getDetail() << endl;
    }
};

class Linen : public Fabric {
    int grade;
public:
    Linen(int g, int c) : Fabric(c) {
        if (g >= 1 && g <= 3) {
            grade = g;
        }
        else {
            grade = 1;
        }
    }

    int getGrade() {
        return grade;
    }

    string getDetail() {
        if (grade == 1) {
            return "best";
        }
        else if (grade == 2) {
            return "good";
        }
        else {
            return "fair";
        }
    }

    void show() {
        cout << "Linen grade: " << getDetail() << endl;
        cout << "Color: " << Fabric::getDetail() << endl;
    }
};

class Polyester : public Fabric {
    int type;
public:
    Polyester(int t, int c) : Fabric(c) {
        if (t >= 1 && t <= 2) {
            type = t;
        }
        else {
            type = 1;
        }
    }

    int getType() {
        return type;
    }

    string getDetail() {
        if (type == 1) {
            return "micro";
        }
        else {
            return "not micro";
        }
    }

    void show() {
        cout << "Polyester grade: " << getDetail() << endl;
        cout << "Color: " << Fabric::getDetail() << endl;
    }
};

class ClothItem {
    double price;
    Fabric** fabric;
    int num;
public:
    ClothItem() {
        setPrice(100);
        fabric = nullptr;
        num = 0;
    }

    ClothItem(double p, int n) {
        setPrice(p);
        setNum(n);
    }

    virtual ~ClothItem() {
        if (fabric != nullptr) {
            delete[] fabric;
            fabric = nullptr;
        }
    }

    void setPrice(double p) {
        if (p < 0) {
            price = 100;
        }
        else {
            price = p;
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
        if (fabric != nullptr) {
            delete[] fabric;
            fabric = nullptr;
        }
        fabric = new Fabric * [num];
    }

    void setFabric(int id, Fabric* fb) {
        fabric[id] = fb;
    }

    Fabric* getFabric(int id) {
        return fabric[id];
    }

    int getNum() {
        return num;
    }

    double getPrice() {
        return price;
    }

    Fabric* operator[] (int i) {
        return fabric[i];
    }

    void showClothItem() {
        cout << "Price: " << price << endl;
        cout << "Num: " << num << endl;
        for (int i = 0; i < num; i++) {
            cout << "Fabric " << i + 1 << endl;
            fabric[i]->show();
        }
    }

    virtual void show() = 0;
};

class Hat : public ClothItem {
    int uv;
    int type;
public:
    Hat() : ClothItem(80, 0) {
        uv = 2;
        type = 2;
    }

    Hat(int u, int t, double p, int n) : ClothItem(p, n) {
        setUV(u);
        setType(t);
    }

    ~Hat() {}

    void setUV(int u) {
        if (u >= 1 && u <= 2) {
            uv = u;
        }
        else {
            uv = 2;
        }
    }

    void setType(int t) {
        if (t >= 1 && t <= 3) {
            type = t;
        }
        else {
            type = 2;
        }
    }

    int getUV() {
        return uv;
    }

    int getType() {
        return type;
    }

    void show() {
        cout << "UV: " << uv << endl;
        cout << "Type: " << type << endl;
        showClothItem();
    }
};

class Bag : public ClothItem {
    int type;
    static int num;
public:
    Bag() : ClothItem(99, 0) {
        type = 3;
        num++;
    }

    Bag(int t, double p, int n) : ClothItem(p, n) {
        setType(t);
        num++;
    }

    ~Bag() {
        num--;
    }

    void setType(int t) {
        if (t >= 1 && t <= 3) {
            type = t;
        }
        else {
            type = 3;
        }
    }

    int getType() {
        return type;
    }

    static int count() {
        return num;
    }

    virtual void show() = 0;
};

int Bag::num;

class HandBag : public Bag {
    int strap;
public:
    HandBag() : Bag(1, 199, 0) {
        strap = 1;
    }

    HandBag(int st, int t, double p, int n) : Bag(t, p, n) {
        setStrap(st);
    }

    void setStrap(int st) {
        if (st >= 1 && st <= 2) {
            strap = st;
        }
        else {
            strap = 1;
        }
    }

    int getStrap() {
        return strap;
    }

    ~HandBag() {}

    void show() {
        cout << "Type: " << getType() << endl;
        cout << "Strap: " << strap << endl;
        showClothItem();
    }
};

class Backpack : public Bag {
    int frame;
    ClothItem** keep;
    int num;

public:
    Backpack() : Bag(2, 299, 0) {
        frame = 2;
        keep = nullptr;
        num = 0;
    }

    Backpack(int f, int n1, int t, double p, int n2) : Bag(t, p, n2) {
        setFrame(f);
        setNum(n1);
    }

    ~Backpack() {
        if (keep != nullptr) {
            delete[] keep;
            keep = nullptr;
        }
    }

    Backpack(Backpack& bp) : Bag(bp.getType(), bp.getPrice(), bp.ClothItem::getNum()) {
        // Backpack, keep
        frame = bp.frame;
        num = bp.num;
        keep = new ClothItem * [num];

        for (int i = 0; i < num; i++) {
            keep[i] = bp.keep[i];
        }

        // ClothItem, fabric
        int numFabric = bp.ClothItem::getNum();
        for (int i = 0; i < numFabric; i++) {
            setFabric(i, bp.ClothItem::getFabric(i));
        }
    }

    ClothItem* operator[] (int id) {
        return keep[id];
    }

    ClothItem* getKeep(int id) {
        return keep[id];
    }

    int getFrame() {
        return frame;
    }

    int getNum() {
        return num;
    }

    void setKeep(int id, ClothItem* item) {
        keep[id] = item;
    }

    void setFrame(int f) {
        if (f >= 1 && f <= 2) {
            frame = f;
        }
        else {
            frame = 2;
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
        if (keep != nullptr) {
            delete[] keep;
            keep = nullptr;
        }
        keep = new ClothItem * [num];
    }

    // func overloading
    void set(int n) {
        Bag::setType(n);
    }

    void set(int n, int f) {
        Bag::setType(n);
        setFrame(f);
    }

    void set(double p) {
        ClothItem::setPrice(p);
    }

    void showBackpack() {
        cout << "Frame: " << frame << endl;
        cout << "Num: " << num << endl;
        showClothItem();
        for (int i = 0; i < num; i++) {
            cout << "Keep " << i + 1 << endl;
            keep[i]->showClothItem();
        }
    }

    void show() {
        cout << "Type: " << getType() << endl;
        showBackpack();
    }

    bool operator == (Backpack& bp) {
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < bp.num; j++) {

                int numFabricThis = keep[i]->getNum();
                int numFabricThat = bp.keep[j]->getNum();

                for (int k = 0; k < numFabricThis; k++) {
                    for (int l = 0; l < numFabricThat; l++) {

                        if (keep[i]->getFabric(k)->getColor() == bp.keep[j]->getFabric(l)->getColor()) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

ostream& operator<<(ostream& os, ClothItem& item) {
    item.show();
    return os;
}

int main()
{
    Fabric* fabric[9] = { new Cotton(1, 1), new Cotton(2, 2), new Cotton(3, 3),
        new Linen(1, 1), new Linen(2, 2), new Linen(3, 3),
        new Polyester(1, 2), new Polyester(2, 4), new Polyester(1, 3) };

    cout << "----- Fabrics -----" << endl;
    for (int i = 0; i < 9; i++) {
        fabric[i]->show();
    }

    HandBag* handbag1 = new HandBag(2, 3, 400, 2);
    handbag1->setFabric(0, fabric[2]);
    handbag1->setFabric(1, fabric[6]);

    Hat* hat1 = new Hat(1, 1, 750, 1);
    hat1->setFabric(0, fabric[3]);

    Hat* hat2 = new Hat(2, 3, 300, 1);
    hat2->setFabric(0, fabric[7]);

    Backpack* backpack1 = new Backpack(1, 2, 2, 1500, 1);
    backpack1->setFabric(0, fabric[0]);
    backpack1->setKeep(0, handbag1);
    backpack1->setKeep(1, hat1);

    ClothItem* items[4] = { handbag1, hat1, hat2, backpack1 };

    cout << "----- Items -----" << endl;
    for (int i = 0; i < 4; i++) {
        cout << *items[i] << endl;
    }

    cout << "----- Add p1 -----" << endl;
    Polyester p1(1, 1);
    hat1->setNum(2);
    hat1->setFabric(0, fabric[3]);
    hat1->setFabric(1, &p1);
    cout << *hat1 << endl;

    cout << "----- [] -----" << endl;
    int countWhite = 0;
    for (int i = 0; i < 4; i++) {
        int numKeeps = items[i]->getNum();
        for (int j = 0; j < numKeeps; j++) {
            if ((*items[i])[j]->getColor() == 1) {
                countWhite++;
            }
        }
    }
    cout << "White: " << countWhite << endl;
    Backpack* backpack2 = new Backpack(*backpack1);

    cout << "----- backpack2 copy -----" << endl;
    backpack2->show();

    backpack2->ClothItem::setNum(3);
    backpack2->setFabric(0, fabric[1]);
    backpack2->setFabric(1, fabric[4]);
    backpack2->setFabric(2, fabric[8]);

    backpack2->setNum(2);
    backpack2->setKeep(0, backpack1);
    backpack2->setKeep(1, hat2);

    cout << "----- backpack2 new -----" << endl;
    cout << *backpack2 << endl;

    // keep bp1
    int countMicro = 0;
    for (int i = 0; i < backpack1->getNum(); i++) {
        int thisKeep = backpack1->getKeep(i)->getNum();

        for (int j = 0; j < thisKeep; j++) {
            if (backpack1->getKeep(i)->getFabric(j)->getDetail() == "micro") {
                countMicro++;
            }
        }
    }

    cout << "Micro in backpack1: " << countMicro << endl;

    // keep bp2, exclude bp1
    double total = 0;
    for (int i = 1; i < backpack2->getNum(); i++) {
        int thisKeep = backpack2->getKeep(i)->getNum();

        for (int j = 0; j < thisKeep; j++) {
            total += backpack2->getKeep(i)->getPrice();
        }
    }

    cout << "Total keeps backpack2, ex. backpack1: " << total << endl;

    backpack1->ClothItem::setNum(2);
    backpack1->setFabric(0, fabric[0]);
    backpack1->setFabric(1, fabric[5]);

    if (backpack1 == backpack2) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    backpack1->showClothItem();
    backpack2->showClothItem();

    cout << "----- function overloading -----" << endl;
    backpack1->set(1270.0);
    backpack1->set(1);
    backpack2->set(1, 2);
    cout << *backpack1 << endl;
    cout << *backpack2 << endl;

    delete handbag1, hat1, hat2, backpack1, backpack2;

    for (int i = 0; i < 9; i++) {
        delete fabric[i];
    }
}

