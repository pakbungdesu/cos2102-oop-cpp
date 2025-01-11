

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

class Student : public Person {
private:
    char stdid[20];
    char university[20];
    Subject* subjList;
    int len;


public:
    Student() : Person() {
        strcpy_s(this->stdid, sizeof(this->stdid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(char* id) : Person() {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(Subject* subjArr, int len) : Person() {
        strcpy_s(this->stdid, sizeof(this->stdid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni) : Person() {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), uni);
        this->subjList = nullptr;
        this->len = 0;
    }

    Student(char* id, Subject* subjArr, int len) : Person() {
        strcpy_s(this->stdid, sizeof(this->stdid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni, Subject* subjArr, int len) : Person() {
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

    void addSubj(Subject new_sub) {
        int new_len = this->len + 1;
        Subject* newSubj = new Subject[new_len];
        for (int i = 0; i < this->len; i++) {
            newSubj[i] = this->subjList[i];
        }
        newSubj[this->len] = new_sub;

        delete[] this->subjList;
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

    void showStd() {
        (*this).showPerson();
        cout << "Student id: " << this->stdid << endl;
        cout << "University: " << this->university << endl;

        if (this->subjList != nullptr) {
            cout << "Subjects enrolled" << endl;
            showAllSubj();
        }
    }
};

// ------------------------------------------ 

class Teacher : public Person {
private:
    char tid[20];
    char university[20];
    Subject* subjList;
    int len;

public:
    Teacher() : Person() {
        strcpy_s(this->tid, sizeof(this->tid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(char* id) : Person() {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(char* id, char* uni) : Person() {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), uni);
        this->subjList = nullptr;
        this->len = 0;
    }

    Teacher(Subject* subjArr, int len) : Person() {
        strcpy_s(this->tid, sizeof(this->tid), (char*)"no_id");
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, Subject* subjArr, int len) : Person() {
        strcpy_s(this->tid, sizeof(this->tid), id);
        strcpy_s(this->university, sizeof(this->university), (char*)"no_uni");

        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, char* uni, Subject* subjArr, int len) : Person() {
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

    void setUni(char* uni) {
        strcpy_s(this->university, sizeof(this->university), uni);
    }

    void setAllTeach(Subject* subjArr, int len) {
        this->subjList = new Subject[len];
        this->len = len;

        for (int i = 0; i < len; i++) {
            this->subjList[i] = subjArr[i];
        }
    }

    void addTeach(Subject new_sub) {
        int new_len = this->len + 1;
        Subject* newSubj = new Subject[new_len];
        for (int i = 0; i < this->len; i++) {
            newSubj[i] = this->subjList[i];
        }
        newSubj[this->len] = new_sub;

        delete[] this->subjList;
        this->subjList = newSubj;
        this->len = new_len;
    }

    char* getTeachId() {
        return this->tid;
    }

    char* getUni() {
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


void testPerson()
{
    // Address Class --------------------------------------
    // constructor
    Address add1((char*)"13/9", (char*)"A", (char*)"B", (char*)"C", (char*)"12150"), add2, add3((char*)"Z"),
        add4((char*)"M", (char*)"N"), add5((char*)"X", (char*)"Y", (char*)"Z");

    // set
    add2.setNum((char*)"12/25");
    add2.setSubDist((char*)"X");
    add2.setDist((char*)"Y");
    add2.setProv((char*)"Z");
    add2.setCode((char*)"12130");

    // get, show
    cout << "\nadd2 info." << endl;
    add2.show();

    cout << "\nadd3 info." << endl;
    add3.show();

    cout << "\nadd4 info." << endl;
    cout << "House number: " << add4.getHouseNum() << endl;
    cout << "Sub-district: " << add4.getSubDist() << endl;
    cout << "District: " << add4.getDist() << endl;
    cout << "Province: " << add4.getProv() << endl;
    cout << "Postal code: " << add4.getCode() << endl;

    cout << "\nadd5 info." << endl;
    cout << "House number: " << add5.getHouseNum() << endl;
    cout << "Sub-district: " << add5.getSubDist() << endl;
    cout << "District: " << add5.getDist() << endl;
    cout << "Province: " << add5.getProv() << endl;
    cout << "Postal code: " << add5.getCode() << endl;

    // Date Class --------------------------------------
    // constructor
    Date date1(11, 3, 2000), date2, date3(25), date4(14, 2);

    // set
    date2.setDate(15);
    date2.setMonth(3);
    date2.setYear(2000);

    // get, show
    cout << "\ndate2 info." << endl;
    date2.show();

    cout << "\ndate3 info." << endl;
    date3.show();

    cout << "\ndate4 info." << endl;
    cout << "Date: " << date4.getDate() << endl;
    cout << "Month: " << date4.getMonth() << endl;
    cout << "Year: " << date4.getYear() << endl;

    // Subject Class --------------------------------------
    // constructor
    Subject sub1, sub2((char*)"XXX"), sub3((char*)"COS2102", (char*)"Object-Oriented Programming");

    // get
    cout << "\nsub1 info." << endl;
    cout << "Subject id: " << sub1.getSubjId() << endl;
    cout << "Subject name: " << sub1.getSubjName() << endl;

    // set
    sub1.setAll((char*)"COS2105", (char*)"Theory of Computation");
    sub2.setSubjId((char*)"COS2101");
    sub2.setSubjName((char*)"Procedural Programming");

    // show
    Subject* my_subject = new Subject[3];
    my_subject[0] = sub1;
    my_subject[1] = sub2;
    my_subject[2] = sub3;

    cout << "\nSubjects info." << endl;
    for (int i = 0; i < 3; i++) {
        my_subject[i].showSubj();
    }

    // Student Class --------------------------------------
    // constructor
    Student s1, s2((char*)"6605555000"), s3(my_subject, 3), s4((char*)"XXX", (char*)"RU"),
        s5((char*)"XXX", my_subject, 3), s6((char*)"XXX", (char*)"RU", my_subject, 3),
        s7((char*)"657000123", (char*)"RU", my_subject, 3, (char*)"Asuka", (char*)"L.", date1, add1),
        s8((char*)"657000255", (char*)"RU", my_subject, 3, (char*)"Rei", (char*)"A.", date2, add2);

    // set
    s1.setFName((char*)"Pimnara");
    s1.setLName((char*)"S.");
    s1.setBD1(date1);
    s1.setAdd1(add1);
    s1.setStdId((char*)"6605500021");
    s1.setUni((char*)"RU");
    s1.setAllSubj(my_subject, 3);

    s2.setFLName((char*)"Aki", (char*)"H.");
    s2.setBD2(3, 8, 1976);
    s2.setAdd2((char*)"19/76", (char*)"S", (char*)"T", (char*)"U", (char*)"19760");
    s2.setUni((char*)"RU");
    s2.addSubj(my_subject[1]);

    s3.setFLName((char*)"Denji", (char*)"H.");
    s3.setBD1(date2);
    s3.setAdd1(add2);
    s3.setStdId((char*)"6705550997");

    s4.setFLName((char*)"Naruto", (char*)"U.");
    s4.setBD1(date3);
    s4.setAdd1(add3);
    s4.setStdId((char*)"6605500000");
    s4.addSubj(my_subject[0]);
    s4.addSubj(my_subject[2]);

    s5.setFLName((char*)"Sasuke", (char*)"U.");
    s5.setBD1(date4);
    s5.setAdd1(add4);
    s5.setStdId((char*)"6605577000");
    s5.addSubj(my_subject[1]);

    s6.setFLName((char*)"Sakura", (char*)"H.");
    s6.setBD2(25, 12, 1970);
    s6.setAdd1(add5);

    // get, show
    cout << "\ns1 info." << endl;
    s1.showPerson();
    cout << "Student id: " << s1.getStdId() << endl;
    cout << "University: " << s1.getUni() << endl;
    cout << "Subjects enrolled" << endl;
    for (int i = 0; i < s1.getNumSubj(); i++) {
        s1.getSubj(i).showSubj();
    }


    Student* my_std = new Student[7];
    my_std[0] = s2;
    my_std[1] = s3;
    my_std[2] = s4;
    my_std[3] = s5;
    my_std[4] = s6;
    my_std[5] = s7;
    my_std[6] = s8;

    cout << "\nStudents info." << endl;
    for (int i = 0; i < 7; i++) {
        cout << "\ns" << i + 2 << " info." << endl;
        my_std[i].showStd();
    }

    // Student Class --------------------------------------
    // constructor
    Subject subj1((char*)"COS2112", (char*)"Swift"), subj2((char*)"COS4106", (char*)"Ethics"),
        subj3((char*)"COS2108", (char*)"Organization and Architectures"),
        subj4((char*)"COS2204", (char*)"Web Programming"),
        subj5((char*)"COS2104", (char*)"Assembly Language"),
        subj6((char*)"COS1101", (char*)"Introduction to Computer"),
        subj7((char*)"COS3101", (char*)"Numerical Method"),
        subj8((char*)"4104", (char*)"Seminar");


    Subject* subjSathit = new Subject[2];
    subjSathit[0] = sub1;
    subjSathit[1] = subj2;

    Subject* subjCha = new Subject[2];
    subjCha[0] = subj3;
    subjCha[1] = subj4;

    Subject* subjPra = new Subject[2];
    subjPra[0] = sub2;
    subjPra[1] = subj5;

    Subject* subSar = new Subject[2];
    subSar[0] = subj6;
    subSar[1] = subj7;

    Teacher t1, t2((char*)"110550012"), t3(subjCha, 2), t4((char*)"110570023", (char*)"RU"),
        t5((char*)"110550019", subjPra, 2), t6((char*)"110551234", (char*)"RU", subSar, 2),
        t7((char*)"110552555", (char*)"RU", my_subject, 3, (char*)"Gojo", (char*)"S.", date3, add3),
        t8((char*)"110552777", (char*)"RU", my_subject, 3, (char*)"Kakashi", (char*)"H.", date4, add4);

    // set
    t1.setFName((char*)"Pawalai");
    t1.setLName((char*)"K.");
    t1.setBD1(date1);
    t1.setAdd1(add1);
    t1.setTeachId((char*)"110555512");
    t1.setUni((char*)"RU");
    t1.addTeach(sub3);
    t1.addTeach(subj1);

    t2.setFLName((char*)"Sathit", (char*)"N.");
    t2.setBD1(date2);
    t2.setAdd1(add2);
    t2.setUni((char*)"RU");
    t2.setAllTeach(subjSathit, 2);

    t3.setFLName((char*)"Chatree", (char*)"N.");
    t3.setBD1(date3);
    t3.setAdd1(add3);
    t1.setTeachId((char*)"110557710");
    t3.setUni((char*)"RU");

    t4.setFLName((char*)"Urai", (char*)"T.");
    t4.setBD1(date4);
    t4.setAdd1(add4);
    t4.addTeach(sub2);

    t5.setFLName((char*)"Prayat", (char*)"L.");
    t5.setBD2(5, 12, 1975);
    t5.setAdd2((char*)"Q", (char*)"R", (char*)"S", (char*)"T", (char*)"12350");
    t5.setUni((char*)"RU");

    t6.setFLName((char*)"Sarawut", (char*)"M.");
    t6.setBD2(15, 4, 1989);
    t6.setAdd2((char*)"U", (char*)"V", (char*)"W", (char*)"X", (char*)"11530");

    // get
    cout << "\nt1 info." << endl;
    t1.showPerson();
    cout << "Teacher id: " << t1.getTeachId() << endl;
    cout << "University: " << s1.getUni() << endl;
    cout << "Subject teached" << endl;
    for (int i = 0; i < t1.getNumTeach(); i++) {
        t1.getTeach(i).showSubj();
    }

    // show
    Teacher* my_teacher = new Teacher[7];
    my_teacher[0] = t2;
    my_teacher[1] = t3;
    my_teacher[2] = t4;
    my_teacher[3] = t5;
    my_teacher[4] = t6;
    my_teacher[5] = t7;
    my_teacher[6] = t8;

    for (int i = 0; i < 7; i++) {
        cout << "\nt" << i + 2 << " info." << endl;
        my_teacher[i].showTeach();
    }

    delete[] my_subject;
    delete[] my_std;
    delete[] my_teacher;
    delete[] subjSathit;
    delete[] subSar;
    delete[] subjPra;
    delete[] subjCha;
}
