

#include <iostream>
using namespace std;

class Appliance {
    double price;
public:
    Appliance() {
        price = 99;
    }

    Appliance(double p) {
        setPrice(p);
    }

    virtual ~Appliance() {}
    virtual string getType() = 0;

    double getPrice() {
        return price;
    }

    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
        else {
            price = 0;
        }
    }
};

class Fan : public Appliance {
    int type;
public:
    Fan() : Appliance(800) {
        type = 1;
    }

    Fan(int t, double p) : Appliance(p) {
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
        string res;
        if (type == 1) {
            res = "Table Fan";
        }
        else if (type == 2) {
            res = "Floor Fan";
        }
        else {
            res = "Ventilating Fan";
        }
        return res;
    }
};

class AirConditioner : public Appliance {
    int type;
public:
    AirConditioner() : Appliance(25000) {
        type = 1;
    }

    AirConditioner(int t, double p) : Appliance(p) {
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
        return (type == 1) ? "Wall AirCon" : "Floor AirCon";
    }
};

class Refrigerator : public Appliance {
    int type;
    static int count;
public:
    Refrigerator() : Appliance(12000) {
        count++;
        type = 2;
    }

    Refrigerator(int t, double p) : Appliance(p) {
        count++;
        setType(t);
    }

    ~Refrigerator() {
        count--;
    }

    void setType(int t) {
        if (t >= 1 && t <= 3) {
            type = t;
        }
        else {
            type = 2;
        }
    }

    string getType() {
        string res;
        if (type == 1) {
            res = "Small Refrig.";
        }
        else if (type == 2) {
            res = "One Door Refrig.";
        }
        else {
            res = "Two Door Refrig.";
        }
        return res;
    }

};

int Refrigerator::count;

class Room {
    Appliance** ap;
    int num;

    void deleteAp() {
        if (ap != nullptr) {
            delete[] ap;
            ap = nullptr;
        }
    }


public:

    virtual void setType(int) = 0;
    virtual string getType() = 0;

    Room() {
        ap = nullptr;
        num = 0;
    }

    Room(int n) {
        num = n;
        ap = new Appliance * [num];
        for (int i = 0; i < num; i++) {
            ap[i] = nullptr;
        }
    }


    ~Room() {
        deleteAp();
    }

    void setNum(int n) {
        if (num == n) return;
        deleteAp();

        if (n <= 0) {
            num = 0;
            ap = nullptr;
        }
        else {
            num = n;
            ap = new Appliance * [num];
        }
    }

    void setAp(int idx, Appliance* a) {
        ap[idx] = a;
    }

    int getNum() {
        return num;
    }

    Appliance* getAp(int idx) {
        return ap[idx];
    }

    virtual void show() {
        for (int i = 0; i < num; i++) {
            cout << "Type: " << ap[i]->getType() << endl;
            cout << "Price: " << ap[i]->getPrice() << endl;
        }
    }
};

class Bedroom : public Room {
    int type;
public:
    Bedroom() {
        type = 3;
    }

    Bedroom(int t) {
        setType(t);
    }

    void setType(int t) {
        if (t >= 1 && t <= 4) {
            type = t;
        }
        else {
            type = 3;
        }
    }

    string getType() {
        string res;
        if (type == 1) {
            res = "Twin size";
        }
        else if (type == 2) {
            res = "Double size";
        }
        else if (type == 3) {
            res = "King size";
        }
        else {
            res = "Single size";
        }
        return res;
    }

    void show() {
        cout << "Bedroom Type: " << getType() << endl;
        cout << "--- Appliance ---" << endl;
        Room::show();
    }
};

class Kitchen : public Room {
    int type;
public:

    Kitchen() {
        type = 2;
    }

    Kitchen(int t) {
        setType(t);
    }

    void setType(int t) {
        if (t >= 1 && t <= 2) {
            type = 1;
        }
        else {
            type = 2;
        }
    }

    string getType() {
        return (type == 1) ? "Thai Kitchen" : "Western Kitchen";
    }

    void show() {
        cout << "Kitchen Type: " << getType() << endl;
        cout << "--- Appliance ---" << endl;
        Room::show();
    }
};

ostream& operator<<(ostream& os, Room& room) {
    room.show();
    return os;
}

class Address {
    int id;
    string province;
public:
    Address() {
        id = 1;
        province = "Bangkok";
    }

    Address(int i, string pv) {
        id = i;
        province = pv;
    }

    int getId() {
        return id;
    }

    string getProvince() {
        return province;
    }

    void setId(int i) {
        id = i;
    }

    void setProvince(string pv) {
        province = pv;
    }
};

class Building {
    Room** room;
    int num;
    Address* add;

    void deleteRoom() {
        if (room != nullptr) {
            delete[] room;
        }
    }
public:
    Building() {
        room = nullptr;
        num = 0;
        add = nullptr;
    }

    ~Building() {
        deleteRoom();
    }

    int getNum() {
        return num;
    }

    Room* getRoom(int idx) {
        return room[idx];
    }

    Address* getAddress() {
        return add;
    }

    void setRoom(int idx, Room* r) {
        room[idx] = r;
    }

    void setAddress(Address* a) {
        add = a;
    }

    void setNum(int n) {
        if (num == n) return;
        deleteRoom();

        if (n <= 0) {
            num = 0;
            room = nullptr;
        }
        else {
            num = n;
            room = new Room * [num];
        }
    }

    Building(Building& db) {
        num = db.num;
        add = db.add;
        room = new Room * [num];
        for (int i = 0; i < num; i++) {
            room[i] = db.room[i];
        }
    }


    void addOneRoom(Room* r) {
        Room** temp = new Room * [num + 1];
        for (int i = 0; i < num; i++) {
            temp[i] = room[i];
        }
        temp[num] = r;
        num++;
        deleteRoom();
        room = temp;
    }

    double operator!() {
        double res = 0;
        for (int i = 0; i < num; i++) {
            int numRoom = room[i]->getNum();
            for (int j = 0; j < numRoom; j++) {
                Appliance* ap = room[i]->getAp(j);
                if (ap != nullptr) {
                    res += ap->getPrice();
                }
            }
        }
        return res;
    }


    int getTableFanNum() {
        int res = 0;
        for (int i = 0; i < num; i++) {
            int numRoom = room[i]->getNum();
            for (int j = 0; j < numRoom; j++) {
                if (room[i]->getAp(j)->getType() == "Table Fan") {
                    res += 1;
                }
            }
        }
        return res;
    }

};


int main()
{
    Fan fan[5] = { Fan(1, 700), Fan(1, 800), Fan(2, 1200), Fan(2, 1300), Fan(3, 1400) };
    for (int i = 0; i < 5; i++) {
        cout << "Type: " << fan[i].getType() << endl;
        cout << "Price: " << fan[i].getPrice() << endl;
    }

    AirConditioner* air[3] = { new AirConditioner(1, 16000), new AirConditioner(1, 17500),
        new AirConditioner(2, 28000) };

    for (int i = 0; i < 3; i++) {
        cout << "Type: " << air[i]->getType() << endl;
        cout << "Price: " << air[i]->getPrice() << endl;
    }

    Refrigerator r1(1, 6000), r2(2, 11000);
    cout << "Type: " << r1.getType() << endl;
    cout << "Price: " << r1.getPrice() << endl;

    cout << "Type: " << r2.getType() << endl;
    cout << "Price: " << r2.getPrice() << endl;

    Bedroom m1(4);
    Room* myRoom[3] = { new Bedroom(4), new Bedroom(2), new Kitchen(1) };
    myRoom[0]->setNum(2);
    myRoom[0]->setAp(0, &fan[0]);
    myRoom[0]->setAp(1, air[0]);

    myRoom[1]->setNum(3);
    myRoom[1]->setAp(0, &fan[1]);
    myRoom[1]->setAp(1, air[1]);
    myRoom[1]->setAp(2, &r1);

    myRoom[2]->setNum(2);
    myRoom[2]->setAp(0, &fan[2]);
    myRoom[2]->setAp(1, &r2);

    cout << "--- myroom ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (*myRoom[i]) << endl;
    }

    Address a[4] = { Address(), Address(2, "Krabi"), Address(3, "Phuket"), Address(4, "Chiang Mai") };
    Building b1;
    b1.setAddress(&a[0]);
    b1.addOneRoom(myRoom[0]);

    cout << "--- b1 ---" << endl;
    cout << "--- Address ---" << endl;
    cout << "Id: " << b1.getAddress()->getId() << endl;
    cout << "Province: " << b1.getAddress()->getProvince() << endl;
    int numRoom = b1.getNum();
    for (int i = 0; i < numRoom; i++) {
        b1.getRoom(i)->show();
    }

    cout << "--- addOneRoom b1 ---" << endl;
    b1.addOneRoom(myRoom[2]);
    numRoom = b1.getNum();
    for (int i = 0; i < numRoom; i++) {
        b1.getRoom(i)->show();
    }

    Building b2;
    b2.setAddress(&a[2]);
    b2.addOneRoom(myRoom[1]);
    Building* myBuilding[2] = { &b1, &b2 };

    bool found = false;
    for (int i = 0; i < 2; i++) {
        if (myBuilding[i]->getAddress()->getId() == 2) {
            found = true;
            break;
        }
    }

    if (found) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }

    double total = 0;
    for (int i = 0; i < 2; i++) {
        // total += !(*myBuilding[i]);

        int bRoom = myBuilding[i]->getNum();
        for (int j = 0; j < bRoom; j++) {

            Room* rooms = myBuilding[i]->getRoom(j);
            int rRoom = rooms->getNum();

            for (int k = 0; k < rRoom; k++) {
                Appliance* ap = rooms->getAp(k);
                if (ap != nullptr) {
                    total += ap->getPrice();
                }
            }
        }
    }
    cout << "Total price: " << total << endl;

    for (int i = 0; i < 3; i++) {
        delete air[i];
    }

    for (int i = 0; i < 3; i++) {
        delete myRoom[i];
    }
}
