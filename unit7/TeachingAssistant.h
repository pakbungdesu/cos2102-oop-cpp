#pragma once
#include <iostream>
using namespace std;

class Date {
private:
    int date;
    int month;
    int year;

public:
    Date() {
        this->date = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int date) {
        this->date = date;
        setMonth(0);
        setYear(0);
    }

    Date(int date, int month) {
        this->date = date;
        this->month = month;
        setYear(0);
    }

    Date(int date, int month, int year) {
        setAll(date, month, year);
    }

    ~Date() {}

    void setDate(int date) {
        this->date = date;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setAll(int date, int month, int year) {
        this->date = date;
        this->month = month;
        this->year = year;
    }

    int getDate() {
        return this->date;
    }

    int getMonth() {
        return this->month;
    }

    int getYear() {
        return this->year;
    }

    void show() {
        cout << "Date: " << this->date << endl;
        cout << "Month: " << this->month << endl;
        cout << "Year: " << this->year << endl;
    }
};

// ------------------------------------------ 

class Address {
private:
    char houseNum[10];
    char subDistrict[20];
    char district[20];
    char province[20];
    char code[10];

public:
    Address() {
        setAll((char*)"no_num", (char*)"no_subdist", (char*)"no_dist", (char*)"no_prov", (char*)"no_code");
    }

    Address(char* pv) {
        setAll((char*)"no_num", (char*)"no_subdist", (char*)"no_dist", pv, (char*)"no_code");
    }

    Address(char* dist, char* pv) {
        setAll((char*)"no_num", (char*)"no_subdist", dist, pv, (char*)"no_code");
    }

    Address(char* sub, char* dist, char* pv) {
        setAll((char*)"no_num", sub, dist, pv, (char*)"no_code");
    }

    Address(char* num, char* sub, char* dist, char* pv) {
        setAll(num, sub, dist, pv, (char*)"no_code");
    }

    Address(char* num, char* sub, char* dist, char* pv, char* code) {
        setAll(num, sub, dist, pv, code);
    }

    ~Address() {}

    void setNum(char* num) {
        strcpy_s(this->houseNum, sizeof(this->houseNum), num);
    }

    void setSubDist(char* sub) {
        strcpy_s(this->subDistrict, sizeof(this->subDistrict), sub);
    }

    void setDist(char* dist) {
        strcpy_s(this->district, sizeof(this->district), dist);
    }

    void setProv(char* pv) {
        strcpy_s(this->province, sizeof(this->province), pv);
    }

    void setCode(char* code) {
        strcpy_s(this->code, sizeof(this->code), code);
    }

    void setAll(char* num, char* sub, char* dist, char* pv, char* code) {
        strcpy_s(this->houseNum, sizeof(this->houseNum), num);
        strcpy_s(this->subDistrict, sizeof(this->subDistrict), sub);
        strcpy_s(this->district, sizeof(this->district), dist);
        strcpy_s(this->province, sizeof(this->province), pv);
        strcpy_s(this->code, sizeof(this->code), code);
    }

    char* getHouseNum() {
        return this->houseNum;
    }

    char* getSubDist() {
        return this->subDistrict;
    }

    char* getDist() {
        return this->district;
    }

    char* getProv() {
        return this->province;
    }

    char* getCode() {
        return this->code;
    }

    void show() {
        cout << "House number: " << this->houseNum << endl;
        cout << "Sub-district: " << this->subDistrict << endl;
        cout << "District: " << this->district << endl;
        cout << "Province: " << this->province << endl;
        cout << "Postal code: " << this->code << endl;
    }
};

// ------------------------------------------ 

class Person {
private:
    char fname[20];
    char lname[20];
    Date birthdate;
    Address address;

public:
    Person() {
        strcpy_s(this->fname, sizeof(this->fname), (char*)"no_fname");
        strcpy_s(this->lname, sizeof(this->lname), (char*)"no_lname");
    }

    Person(char* fname) {
        strcpy_s(this->fname, sizeof(this->fname), fname);
        strcpy_s(this->lname, sizeof(this->lname), (char*)"no_lname");
    }

    Person(Date date) {
        setFLName((char*)"no_fname", (char*)"no_lname");
        this->birthdate = date;
    }

    Person(Address location) {
        setFLName((char*)"no_fname", (char*)"no_lname");
        this->address = location;
    }

    Person(char* fname, Date date) {
        setFLName(fname, (char*)"no_lname");
        this->birthdate = date;
    }

    Person(char* fname, Address location) {
        setFLName(fname, (char*)"no_lname");
        this->address = location;
    }

    Person(Date date, Address location) {
        setFLName((char*)"no_fname", (char*)"no_lname");
        this->birthdate = date;
        this->address = location;
    }

    Person(char* fname, char* lname, Date date, Address location) {
        setFLName(fname, lname);
        this->birthdate = date;
        this->address = location;
    }

    ~Person() {}

    void setFName(char* fname) {
        strcpy_s(this->fname, sizeof(this->fname), fname);
    }

    void setLName(char* lname) {
        strcpy_s(this->lname, sizeof(this->lname), lname);
    }

    void setFLName(char* fname, char* lname) {
        strcpy_s(this->fname, sizeof(this->fname), fname);
        strcpy_s(this->lname, sizeof(this->lname), lname);
    }

    void setBD1(Date date) {
        this->birthdate = date;
    }

    void setBD2(int date, int month, int year) {
        this->birthdate.setAll(date, month, year);
    }

    void setBirthDate(int date) {
        this->birthdate.setDate(date);
    }

    void setBirthMonth(int month) {
        this->birthdate.setMonth(month);
    }

    void setBirthYear(int year) {
        this->birthdate.setYear(year);
    }

    void setAdd1(Address address) {
        this->address = address;
    }

    void setAdd2(char* num, char* sub, char* dist, char* pv, char* code) {
        this->address.setAll(num, sub, dist, pv, code);
    }

    void setNumData(char* num) {
        this->address.setNum(num);
    }

    void setSubData(char* sub) {
        this->address.setSubDist(sub);
    }

    void setDistData(char* dist) {
        this->address.setDist(dist);
    }

    void setProvData(char* pv) {
        this->address.setProv(pv);
    }

    char* getFName() {
        return this->fname;
    }

    char* getLName() {
        return this->lname;
    }

    int getBirthDate() {
        return this->birthdate.getDate();
    }

    int getBirthMonth() {
        return this->birthdate.getMonth();
    }

    int getBirthYear() {
        return this->birthdate.getYear();
    }

    char* getNumData() {
        return this->address.getHouseNum();
    }

    char* getSubDistData() {
        return this->address.getSubDist();
    }

    char* getDistData() {
        return this->address.getDist();
    }

    char* getProvData() {
        return this->address.getProv();
    }

    char* getCodeData() {
        return this->address.getCode();
    }


    void showAdd() {
        this->address.show();
    }

    void showBD() {
        this->birthdate.show();
    }

    void showPerson() {
        cout << "FName: " << this->fname << endl;
        cout << "LName: " << this->lname << endl;
        this->address.show();
        this->birthdate.show();
    }
};

// ------------------------------------------ 

class Subject {
private:
    char subjId[20];
    char subjName[40];

public:
    Subject() {
        strcpy_s(this->subjId, sizeof(this->subjId), (char*)"no_id");
        strcpy_s(this->subjName, sizeof(this->subjName), (char*)"no_name");
    }

    Subject(char* name) {
        strcpy_s(this->subjId, sizeof(this->subjId), (char*)"no_id");
        strcpy_s(this->subjName, sizeof(this->subjName), name);
    }

    Subject(char* id, char* name) {
        strcpy_s(this->subjId, sizeof(this->subjId), id);
        strcpy_s(this->subjName, sizeof(this->subjName), name);
    }

    ~Subject() {}

    void setSubjId(char* id) {
        strcpy_s(this->subjId, sizeof(this->subjId), id);
    }

    void setSubjName(char* name) {
        strcpy_s(this->subjName, sizeof(this->subjName), name);
    }

    void setAll(char* id, char* name) {
        strcpy_s(this->subjId, sizeof(this->subjId), id);
        strcpy_s(this->subjName, sizeof(this->subjName), name);
    }

    char* getSubjId() {
        return this->subjId;
    }

    char* getSubjName() {
        return this->subjName;
    }

    void showSubj() {
        cout << "Subject id: " << this->subjId << endl;
        cout << "Subject name: " << this->subjName << endl;
    }
};

// ------------------------------------------ 

class Student : virtual public Person {
private:
    char stdid[20];
    char university[20];
    Subject* subjList;
    int len;


public:
    Student() {
        strcpy_s(this->stdid, sizeof(this->stdid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(char* id) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(Subject* subjArr, int len) {
        strcpy_s(this->stdid, sizeof(this->stdid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), uni);
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(char* id, Subject* subjArr, int len) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni, Subject* subjArr, int len) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), uni);

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni, Subject* subjArr, int len, char* fname, char* lname,
        Date date, Address address) : Person(fname, lname, date, address) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), uni);

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    void setStdId(char* id) {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
    }

    void setUni(char* uni) {
        strcpy_s(this->university, sizeof(this->university), uni);
    }

    void setAllSubj(Subject* subjArr, int len) {
        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    void addSubj(const Subject& new_sub) {
        int new_len = this->len + 1;
        Subject* newSubj = new Subject[new_len];

        for (int i = 0; i < this->len; i++) {
            newSubj[i] = this->subjList[i];
        }

        newSubj[new_len - 1] = new_sub;

        if (this->subjList) {
            delete[] this->subjList;
        }

        this->subjList = newSubj;
        this->len = new_len;
    }



    char* getStdId() {
        return this->stdid;
    }

    char* getUni() {
        return this->university;
    }

    int getNumSubj() {
        return this->len;
    }

    Subject getSubj(int idx) {
        return this->subjList[idx];
    }

    void showAllSubj() {
        for (int i = 0; i < this->len; i++) {
            this->subjList[i].showSubj();
        }
    }

    void showStd1() {
        (*this).showPerson();
        cout << "Student id: " << this->stdid << endl;
        cout << "University: " << this->university << endl;

        if (this->subjList != nullptr) {
            cout << "Subjects enrolled" << endl;
            showAllSubj();
        }
    }

    void showStd2() {
        cout << "Student id: " << this->stdid << endl;
        cout << "University: " << this->university << endl;

        if (this->subjList != nullptr) {
            cout << "Subjects enrolled" << endl;
            showAllSubj();
        }
    }


};

// ------------------------------------------ 

class Teacher : virtual public Person {
private:
    char tid[20];
    char university[20];
    Subject* subjList;
    int len;

public:
    Teacher() {
        strcpy_s(this->tid, sizeof(this->tid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(char* id) {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(char* id, char* uni) {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), uni);
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(Subject* subjArr, int len) {
        strcpy_s(this->tid, sizeof(this->tid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, Subject* subjArr, int len) {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, char* uni, Subject* subjArr, int len) {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), uni);

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, char* uni, Subject* subjArr, int len, char* fname, char* lname,
        Date date, Address address) : Person(fname, lname, date, address) {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), uni);

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    void setTeachId(char* id) {
        strcpy_s(this->tid, sizeof(this->tid), id);
    }

    void setTeachUni(char* uni) {
        strcpy_s(this->university, sizeof(this->university), uni);
    }

    void setAllTeach(Subject* subjArr, int len) {
        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    void addTeach(const Subject& new_sub) {
        int new_len = this->len + 1;
        Subject* newSubj = new Subject[new_len];

        for (int i = 0; i < this->len; i++) {
            newSubj[i] = this->subjList[i];
        }

        newSubj[new_len - 1] = new_sub;

        if (this->subjList) {
            delete[] this->subjList;
        }

        this->subjList = newSubj;
        this->len = new_len;
    }

    char* getTeachId() {
        return this->tid;
    }

    char* getTeachUni() {
        return this->university;
    }

    int getNumTeach() {
        return this->len;
    }

    Subject getTeach(int idx) {
        return this->subjList[idx];
    }

    void showAllTeach() {
        for (int i = 0; i < this->len; i++) {
            this->subjList[i].showSubj();
        }
    }

    void showTeach() {
        (*this).showPerson();
        cout << "Teacher id: " << this->tid << endl;
        cout << "University: " << this->university << endl;

        if (this->subjList != nullptr) {
            cout << "Subjects teached" << endl;
            showAllTeach();
        }
    }

};

class TeachingAssistant : public Teacher, public Student {
private:
    char taid[20];
    char university[20];

public:
    TeachingAssistant() {
        strcpy_s(this->taid, sizeof(this->taid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni) :
        Teacher(tId, tUni), Student(stdId, stdUni) {
        strcpy_s(this->taid, sizeof(this->taid), tId);
        strcpy_s(this->university, sizeof(this->university), tUni);
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni,
        Subject* subjArr1, int len1, Subject* subjArr2, int len2) :
        Teacher(tId, tUni, subjArr1, len1), Student(stdId, stdUni, subjArr2, len2) {

        strcpy_s(this->taid, sizeof(this->taid), tId);
        strcpy_s(this->university, sizeof(this->university), tUni);
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni,
        Subject* subjArr1, int len1, Subject* subjArr2, 
        int len2, char* fname, char* lname, Date date, Address add) :
        Teacher(tId, tUni, subjArr1, len1, fname, lname, date, add),
        Student(stdId, stdUni, subjArr2, len2, fname, lname, date, add) {
        //Person(fname, lname, date, add){

        strcpy_s(this->taid, sizeof(this->taid), tId);
        strcpy_s(this->university, sizeof(this->university), tUni);
    }

    void settId(char* tId) {
        strcpy_s(this->taid, sizeof(this->taid), tId);
        this->setTeachId(tId);
    }

    void settUni(char* tUni) {
        strcpy_s(this->university, sizeof(this->university), tUni);
        this->setTeachUni(tUni);
    }

    char* gettId() {
        return this->taid;
    }

    char* gettUni() {
        return this->university;
    }

    void showTA() {
        cout << "\nTA info." << endl;
        this->showTeach();
        this->showStd2();
    }
};


void testTeachingAssistant()
{
    // Address
    Address add1((char*)"13/9", (char*)"A", (char*)"B", (char*)"C", (char*)"12150"),
        add2((char*)"12/25", (char*)"X", (char*)"Y", (char*)"Z", (char*)"12130");

    // Date
    Date date1(11, 3, 2000), date2(5, 3, 2000), date3(25, 12, 2000), date4(14, 2, 2000);

    // Subject
    Subject sub1((char*)"COS2105", (char*)"Theory of Computation"),
        sub2((char*)"COS2101", (char*)"Procedural Programming"),
        sub3((char*)"COS2102", (char*)"Object-Oriented Programming"),
        sub4((char*)"COS2112", (char*)"Swift"),
        sub5((char*)"COS4106", (char*)"Ethics"),
        sub8((char*)"COS2104", (char*)"Assembly Language"),
        sub9((char*)"COS1101", (char*)"Introduction to Computer"),
        sub10((char*)"COS3101", (char*)"Numerical Method");

    Subject* mys1 = new Subject[3];
    mys1[0] = sub1;
    mys1[1] = sub2;
    mys1[2] = sub3;

    Subject* myt1 = new Subject[2];
    myt1[0] = sub9;
    myt1[1] = sub10;


    Subject* mys2 = new Subject[2];
    mys2[0] = sub1;
    mys2[1] = sub2;


    Subject* myt2 = new Subject[2];
    myt2[0] = sub9;
    myt2[1] = sub10;


    // TA
    // Constructor
    TeachingAssistant ta1((char*)"110555513", (char*)"RU", (char*)"6605500021", (char*)"RU"),
        ta2((char*)"110555513", (char*)"RU", (char*)"660557722", (char*)"RU", myt1, 2, mys1, 3),
        ta3((char*)"110555523", (char*)"RU", (char*)"660557721", 
            (char*)"RU", myt2, 2, mys2, 2, (char*)"Aki", (char*)"H.", date1, add1),
        ta4;
    ta3.showTA();

    // Set
    ta1.setAllSubj(mys2, 2);
    ta1.setAllTeach(myt1, 2);
    ta1.setFLName((char*)"Pimanara", (char*)"S.");
    ta1.setAdd1(add1);
    ta1.setBD1(date1);

    ta4.settId((char*)"110555545");
    ta4.settUni((char*)"CU");
    ta4.setStdId((char*)"660550055");
    ta4.setUni((char*)"RU");
    ta4.setFLName((char*)"Aki", (char*)"H.");
    ta4.setAdd1(add2);
    ta4.setBD1(date2);
    ta4.setAllSubj(myt2, 2);
    ta4.setAllTeach(mys1, 3);

    ta2.setFLName((char*)"Denji", (char*)"H.");
    ta2.setAdd1(add1);
    ta2.setBD1(date1);

    ta3.setFLName((char*)"Power", (char*)"H.");
    ta3.setAdd1(add2);
    ta3.setBD1(date2);

    // Get
    cout << "\nTA info." << endl;
    ta4.showPerson();
    cout << "TA id: " << ta4.gettId() << endl;
    cout << "TA university: " << ta4.gettUni() << endl;
    cout << "Subjects teached" << endl;
    ta4.showAllTeach();
    ta4.showStd2();

    // Show
    TeachingAssistant* myta = new TeachingAssistant[3];
    myta[0] = ta1;
    myta[1] = ta2;
    myta[2] = ta3;

    for (int i = 0; i < 3; i++) {
        myta[i].showTA();
    }

    delete[] myta, myt1, myt2, mys1, mys2;
}
