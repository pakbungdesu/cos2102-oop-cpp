

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
        return date;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    void show() {
        cout << "Date: " << this->date << endl;
        cout << "Month: " << this->month << endl;
        cout << "Year: " << this->year << endl;
    }

    friend istream& operator>>(istream& is, Date& date);

};

ostream& operator<<(ostream& os, Date& date) {
    date.show();
    return os;
}

istream& operator>>(istream& is, Date& date) {
    cout << "Enter date: "; is >> date.date;
    cout << "Enter month: "; is >> date.month;
    cout << "Enter year: "; is >> date.year;
    return is;
}

// ------------------------------------------ 

class Address {
private:
    char* houseNum;
    char* district;
    char* province;
    char* code;

public:
    Address() {
        houseNum = nullptr;
        district = nullptr;
        province = nullptr;
        code = nullptr;
        setAll((char*)"no_num", (char*)"no_dist", (char*)"no_prov", (char*)"no_code");
    }

    Address(char* pv, char* cd) {
        houseNum = nullptr;
        district = nullptr;
        province = nullptr;
        code = nullptr;
        setAll((char*)"no_num", (char*)"no_dist", pv, cd);
    }

    Address(char* hn, char* dist, char* pv, char* cd) {
        houseNum = nullptr;
        district = nullptr;
        province = nullptr;
        code = nullptr;
        setAll(hn, dist, pv, cd);
    }

    // Copy constructor
    Address(const Address& other) {
        houseNum = nullptr;
        district = nullptr;
        province = nullptr;
        code = nullptr;
        setAll(other.houseNum, other.district, other.province, other.code);
    }

    // Assignment operator
    Address& operator=(const Address& other) {
        if (this != &other) {
            setAll(other.houseNum, other.district, other.province, other.code);
        }
        return *this;
    }

    ~Address() {
        delete[] houseNum;
        delete[] district;
        delete[] province;
        delete[] code;
    }

    void setNum(char* num) {
        if (houseNum) {
            delete[] houseNum;
        }
        houseNum = new char[strlen(num) + 1];
        strcpy_s(houseNum, strlen(num) + 1, num);
    }


    void setDist(char* dist) {
        if (district) {
            delete[] district;
        }
        district = new char[strlen(dist) + 1];
        strcpy_s(district, strlen(dist) + 1, dist);
    }

    void setProv(char* pv) {
        if (province) {
            delete[] province;
        }
        province = new char[strlen(pv) + 1];
        strcpy_s(province, strlen(pv) + 1, pv);
    }

    void setCode(char* cd) {
        if (code) {
            delete[] code;
        }
        code = new char[strlen(cd) + 1];
        strcpy_s(code, strlen(cd) + 1, cd);
    }

    void setAll(char* num, char* dist, char* pv, char* cd) {
        setNum(num);
        setDist(dist);
        setProv(pv);
        setCode(cd);
    }

    char* getHouseNum() {
        return houseNum;
    }

    char* getDist() {
        return district;
    }

    char* getProv() {
        return province;
    }

    char* getCode() {
        return code;
    }

    void show() {
        cout << "House number: " << houseNum << endl;
        cout << "District: " << district << endl;
        cout << "Province: " << province << endl;
        cout << "Postal code: " << code << endl;
    }

    friend istream& operator>>(istream& is, Address& loc);
};


ostream& operator<< (ostream& os, Address& loc) {
    loc.show();
    return os;
}

istream& operator>> (istream& is, Address& loc) {
    char buffer[50];

    cout << "Enter House number: "; is >> buffer; loc.setNum(buffer);
    cout << "Enter District: "; is >> buffer; loc.setDist(buffer);
    cout << "Enter Province: "; is >> buffer; loc.setProv(buffer);
    cout << "Enter Postal code: "; is >> buffer; loc.setCode(buffer);

    return is;
}

// ------------------------------------------ 

class Person {
private:
    char* fname;
    char* lname;
    Date birthdate;
    Address address;

public:
    Person() {
        fname = nullptr;
        lname = nullptr;
        setFLName((char*)"no_fname", (char*)"no_lname");
    }

    Person(char* fn, Address loc) {
        fname = nullptr;
        lname = nullptr;
        setFLName(fn, (char*)"no_lname");
        address = loc;
    }

    Person(char* fn, char* ln, Date date, Address loc) {
        fname = nullptr;
        lname = nullptr;
        setFLName(fn, ln);
        birthdate = date;
        address = loc;
    }

    // Copy constructor
    Person(const Person& other) {
        fname = nullptr;
        lname = nullptr;
        setFLName(other.fname, other.lname);

        birthdate = other.birthdate;
        address = other.address;
    }

    // Assignment operator
    Person& operator=(const Person& other) {
        if (this != &other) {
            setFLName(other.fname, other.lname);

            birthdate = other.birthdate;
            address = other.address;
        }
        return *this;
    }

    virtual ~Person() {
        delete[] fname;
        delete[] lname;
    }

    void setFName(char* fn) {
        if (fname) {
            delete[] fname;
        }
        fname = new char[strlen(fn) + 1];
        strcpy_s(fname, strlen(fn) + 1, fn);

    }

    void setLName(char* ln) {
        if (lname) {
            delete[] lname;
        }
        lname = new char[strlen(ln) + 1];
        strcpy_s(lname, strlen(ln) + 1, ln);

    }

    void setFLName(char* fn, char* ln) {
        setFName(fn);
        setLName(ln);
    }

    void setBD1(Date date) {
        birthdate = date;
    }

    void setBD2(int date, int month, int year) {
        birthdate.setAll(date, month, year);
    }

    void setBirthDate(int date) {
        birthdate.setDate(date);
    }

    void setBirthMonth(int month) {
        birthdate.setMonth(month);
    }

    void setBirthYear(int year) {
        birthdate.setYear(year);
    }

    void setAdd1(Address loc) {
        address = loc;
    }

    void setAdd2(char* num, char* dist, char* pv, char* code) {
        address.setAll(num, dist, pv, code);
    }

    void setNumData(char* num) {
        address.setNum(num);
    }

    void setDistData(char* dist) {
        address.setDist(dist);
    }

    void setProvData(char* pv) {
        address.setProv(pv);
    }

    Address getAddress() {
        return address;
    }

    Date getBD() {
        return birthdate;
    }

    char* getFName() {
        return fname;
    }

    char* getLName() {
        return lname;
    }

    char* getNumData() {
        return address.getHouseNum();
    }

    char* getDistData() {
        return address.getDist();
    }

    char* getProvData() {
        return address.getProv();
    }

    char* getCodeData() {
        return address.getCode();
    }

    void showAdd() {
        address.show();
    }

    void showBD() {
        birthdate.show();
    }

    void showPerson() {
        cout << "FName: " << fname << endl;
        cout << "LName: " << lname << endl;
        address.show();
        birthdate.show();
    }

    virtual ostream& print(ostream& os) {
        showPerson();
        return os;
    }

    virtual istream& input(istream& is) {
        Address add1;
        Date date1;
        char buffer[50];

        cin >> date1; setBD1(date1);
        cin >> add1; setAdd1(add1);
        cout << "Enter FName: "; cin >> buffer; setFName(buffer);
        cout << "Enter LName: "; cin >> buffer; setLName(buffer);
        return is;
    }
};


// ------------------------------------------ 

class Subject {
private:
    char* subjId;
    char* subjName;

public:
    Subject() {
        subjId = nullptr;
        subjName = nullptr;
        setAll((char*)"no_id", (char*)"no_name");
    }

    Subject(char* name) {
        subjId = nullptr;
        subjName = nullptr;
        setAll((char*)"no_id", name);
    }

    Subject(char* id, char* name) {
        subjId = nullptr;
        subjName = nullptr;
        setAll(id, name);
    }

    ~Subject() {
        delete[] subjId;
        delete[] subjName;
    }

    // Copy constructor
    Subject(const Subject& other) {
        subjId = nullptr;
        subjName = nullptr;
        setAll(other.subjId, other.subjName);
    }

    // Assignment operator
    Subject& operator=(const Subject& other) {
        if (this != &other) {
            setAll(other.subjId, other.subjName);
        }
        return *this;
    }

    void setSubjId(char* id) {
        if (subjId) {
            delete[] subjId;
        }
        subjId = new char[strlen(id) + 1];
        strcpy_s(subjId, strlen(id) + 1, id);

    }

    void setSubjName(char* name) {
        if (subjName) {
            delete[] subjName;
        }
        subjName = new char[strlen(name) + 1];
        strcpy_s(subjName, strlen(name) + 1, name);

    }

    void setAll(char* id, char* name) {
        setSubjId(id);
        setSubjName(name);
    }

    char* getSubjId() {
        return subjId;
    }

    char* getSubjName() {
        return subjName;
    }

    void showSubj() {
        cout << "Subject id: " << subjId << endl;
        cout << "Subject name: " << subjName << endl;
    }

    friend istream& operator>>(istream& is, Subject& sub);
};

ostream& operator<<(ostream& os, Subject& sub) {
    sub.showSubj();
    return os;
}

istream& operator>>(istream& is, Subject& sub) {
    char buffer[50];
    cout << "Enter subject id: "; is >> buffer; sub.setSubjId(buffer);
    cout << "Enter subject name: "; is >> buffer; sub.setSubjName(buffer);
    return is;
}

// ------------------------------------------ 

class Student : virtual public Person {
private:
    char* stdid;
    char* university;
    Subject* subjList;
    int len;

    void deleteSubj() {
        if (subjList) {
            delete[] subjList;
            subjList = nullptr;
        }
    }

    void allocateSubj(int len) {
        subjList = new Subject[len];
        this->len = len;
    }

public:
    Student() {
        stdid = nullptr;
        university = nullptr;
        setStdId((char*)"no_id");
        setUni((char*)"no_uni");

        subjList = nullptr;
        len = 0;
    }


    Student(char* id, char* uni) {
        stdid = nullptr;
        university = nullptr;

        setStdId(id);
        setUni(uni);

        subjList = nullptr;
        len = 0;
    }

    Student(char* id, char* uni, Subject* subjArr, int len) {
        stdid = nullptr;
        university = nullptr;

        setStdId(id);
        setUni(uni);
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    Student(char* id, char* uni, Subject* subjArr, int len, char* fname, char* lname,
        Date date, Address loc) : Person(fname, lname, date, loc) {
        stdid = nullptr;
        university = nullptr;

        setStdId(id);
        setUni(uni);
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    // Copy constructor
    Student(Student& other) : Person(other) {

        stdid = nullptr;
        university = nullptr;
        setStdId(other.stdid);
        setUni(other.university);

        deleteSubj();
        allocateSubj(other.len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = other.subjList[i];
        }
    }

    // Assignment operator
    Student& operator=(Student& other) {
        if (this != &other) {
            // person
            setFLName(other.getFName(), other.getLName());
            setAdd1(other.getAddress());
            setBD1(other.getBD());

            setStdId(other.stdid);
            setUni(other.university);
            deleteSubj();
            allocateSubj(other.len);

            // copy
            for (int i = 0; i < len; i++) {
                subjList[i] = other.subjList[i];
            }
        }
        return *this;
    }

    void setStdId(char* id) {
        if (stdid) {
            delete[] stdid;
        }
        stdid = new char[strlen(id) + 1];
        strcpy_s(stdid, strlen(id) + 1, id);

    }

    void setUni(char* uni) {
        if (university) {
            delete[] university;
        }
        university = new char[strlen(uni) + 1];
        strcpy_s(university, strlen(uni) + 1, uni);
    }

    void setSubj(int idx, const Subject& subj) {
        if (idx < 0 || idx >= len) {
            cout << "Invalid index" << endl;
            return;
        }
        subjList[idx] = subj;
    }

    void setAllSubj(int len) {
        deleteSubj();
        allocateSubj(len);

        Subject sub;
        for (int i = 0; i < len; i++) {
            cout << "Enter subject " << i + 1 << endl;
            cin >> sub;
            subjList[i] = sub;
        }
    }

    void addSubj(const Subject& new_sub) {
        int new_len = len + 1;
        Subject* newSubj = new Subject[new_len];

        for (int i = 0; i < len; i++) {
            newSubj[i] = subjList[i];
        }

        newSubj[new_len - 1] = new_sub;

        delete[] subjList;
        subjList = newSubj;
        len = new_len;
    }

    Subject* getAllSubj() {
        return subjList;
    }

    char* getStdId() {
        return stdid;
    }

    char* getUni() {
        return university;
    }

    int getNumSubj() {
        return len;
    }

    Subject getSubj(int idx) {
        return subjList[idx];
    }

    int getLen() {
        return len;
    }

    void showAllSubj() {
        for (int i = 0; i < len; i++) {
            subjList[i].showSubj();
        }
    }

    void showStd() {
        cout << "Student id: " << stdid << endl;
        cout << "University: " << university << endl;

        if (subjList != nullptr) {
            cout << "Subjects enrolled" << endl;
            showAllSubj();
        }
    }

    virtual ~Student() {
        delete[] stdid;
        delete[] university;
        deleteSubj();
    }

    ostream& print(ostream& os) {
        showStd();
        return os;
    }

    istream& input(istream& is) {
        char buffer[50];
        Subject sub;

        Person::input(is);
        cout << "Enter student id: "; is >> buffer; setStdId(buffer);
        cout << "Enter university: "; is >> buffer; setUni(buffer);
        cout << "Enter number of subjects: "; is >> len;

        allocateSubj(len);

        for (int i = 0; i < len; i++) {
            cout << "Enter subject " << i + 1 << endl;
            cin >> sub;
            setSubj(i, sub);
        }
        return is;
    }
};

// ------------------------------------------ 

class Teacher : virtual public Person {
private:
    char* tid;
    char* university;
    Subject* subjList;
    int len;

    void deleteSubj() {
        if (subjList) {
            delete[] subjList;
            subjList = nullptr;
        }
    }

    void allocateSubj(int len) {
        subjList = new Subject[len];
        this->len = len;
    }

public:
    Teacher() {
        tid = nullptr;
        university = nullptr;
        setTeachId((char*)"no_id");
        setTeachUni((char*)"no_uni");
        subjList = nullptr;
        len = 0;
    }

    Teacher(char* id, char* uni) {
        tid = nullptr;
        university = nullptr;
        setTeachId(id);
        setTeachUni(uni);
        subjList = nullptr;
        len = 0;
    }

    Teacher(char* id, char* uni, Subject* subjArr, int len) {
        tid = nullptr;
        university = nullptr;
        setTeachId(id);
        setTeachUni(uni);
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    Teacher(Subject* subjArr, int len) {
        tid = nullptr;
        university = nullptr;
        setTeachId((char*)"no_id");
        setTeachUni((char*)"no_uni");
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    Teacher(Subject* subjArr, int len, char* fname, char* lname,
        Date date, Address address) : Person(fname, lname, date, address) {
        tid = nullptr;
        university = nullptr;
        setTeachId((char*)"no_id");
        setTeachUni((char*)"no_uni");
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    Teacher(char* id, char* uni, Subject* subjArr, int len, char* fname, char* lname,
        Date date, Address address) : Person(fname, lname, date, address) {
        tid = nullptr;
        university = nullptr;
        setTeachId(id);
        setTeachUni(uni);
        allocateSubj(len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = subjArr[i];
        }
    }

    Teacher(Teacher& other) : Person(other) {
        tid = nullptr;
        university = nullptr;

        setTeachId(other.tid);
        setTeachUni(other.university);
        deleteSubj();
        allocateSubj(other.len);

        // copy
        for (int i = 0; i < len; i++) {
            subjList[i] = other.subjList[i];
        }
    }

    Teacher& operator=(Teacher& other) {
        if (this != &other) {
            // person
            setAdd1(other.getAddress());
            setBD1(other.getBD());
            setFLName(other.getFName(), other.getLName());

            setTeachId(other.tid);
            setTeachUni(other.university);
            deleteSubj();
            allocateSubj(other.len);

            // copy
            for (int i = 0; i < len; i++) {
                subjList[i] = other.subjList[i];
            }
        }
        return *this;
    }

    virtual ~Teacher() {
        delete[] tid;
        delete[] university;
        deleteSubj();
    }

    void setTeachId(char* id) {
        if (tid) {
            delete[] tid;
        }
        tid = new char[strlen(id) + 1];
        strcpy_s(tid, strlen(id) + 1, id);
    }

    void setTeachUni(char* uni) {
        if (university) {
            delete[] university;
        }
        university = new char[strlen(uni) + 1];
        strcpy_s(university, strlen(uni) + 1, uni);
    }

    void setSubj(int idx, const Subject& subj) {
        if (idx < 0 || idx >= len) {
            cout << "Invalid index" << endl;
            return;
        }
        subjList[idx] = subj;
    }

    void setAllTeach(int len) {
        deleteSubj();
        allocateSubj(len);

        Subject sub;
        for (int i = 0; i < len; i++) {
            cout << "Enter subject " << i + 1 << endl;
            cin >> sub;
            subjList[i] = sub;
        }
    }

    void addTeach(const Subject& new_sub) {
        int new_len = len + 1;
        Subject* newSubj = new Subject[new_len];

        for (int i = 0; i < len; i++) {
            newSubj[i] = subjList[i];
        }

        newSubj[new_len - 1] = new_sub;

        delete[] subjList;
        subjList = newSubj;
        len = new_len;
    }

    int getLen() {
        return len;
    }

    char* getTeachId() {
        return tid;
    }

    char* getTeachUni() {
        return university;
    }

    int getNumTeach() {
        return len;
    }

    Subject* getAllSubj() {
        return subjList;
    }

    Subject getTeach(int idx) {
        return subjList[idx];
    }

    void showAllTeach() {
        for (int i = 0; i < this->len; i++) {
            subjList[i].showSubj();
        }
    }

    void showTeach() {
        cout << "Teacher id: " << this->tid << endl;
        cout << "University: " << this->university << endl;

        if (subjList != nullptr) {
            cout << "Subjects teached" << endl;
            showAllTeach();
        }
    }

    ostream& print(ostream& os) {
        showTeach();
        return os;
    }

    istream& input(istream& is) {
        char buffer[50];
        Subject sub;

        Person::input(is);
        cout << "Enter teacher id: "; is >> buffer; setTeachId(buffer);
        cout << "Enter university: "; is >> buffer; setTeachUni(buffer);

        cout << "Enter len: "; is >> len;
        setAllTeach(len);
        return is;
    }
};

// ------------------------------------------ 

class TeachingAssistant : public Teacher, public Student {
private:
    char* taid;
    char* university;

public:
    TeachingAssistant() {
        taid = nullptr;
        university = nullptr;
        setTAid((char*)"no_id");
        setTAuni((char*)"no_uni");
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni) :
        Student(stdId, stdUni) {

        taid = nullptr;
        university = nullptr;
        setTAid(tId);
        setTAuni(tUni);
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni,
        Subject* subjArr1, int len1, Subject* subjArr2, int len2) :
        Teacher(subjArr1, len1), Student(stdId, stdUni, subjArr2, len2) {

        taid = nullptr;
        university = nullptr;
        setTAid(tId);
        setTAuni(tUni);
    }

    TeachingAssistant(char* tId, char* tUni, char* stdId, char* stdUni,
        Subject* subjArr1, int len1, Subject* subjArr2,
        int len2, char* fname, char* lname, Date date, Address add) :
        Teacher(subjArr1, len1, fname, lname, date, add),
        Student(stdId, stdUni, subjArr2, len2, fname, lname, date, add) {

        taid = nullptr;
        university = nullptr;
        setTAid(tId);
        setTAuni(tUni);
    }

    TeachingAssistant(TeachingAssistant& other) : Person(other), Student(other), Teacher(other)
    {
        taid = nullptr;
        university = nullptr;
        setTAid(other.taid);
        setTAuni(other.university);
    }

    TeachingAssistant& operator=(TeachingAssistant& other) {
        if (this != &other) {
            //person
            setAdd1(other.getAddress());
            setBD1(other.getBD());
            setFLName(other.getFName(), other.getLName());

            //student
            setStdId(other.getStdId());
            setUni(other.getUni());

            //teacher
            setTeachId(other.getTeachId());
            setTeachUni(other.getTeachUni());

            taid = nullptr;
            university = nullptr;
            setTAid(other.taid);
            setTAuni(other.university);
        }
        return *this;
    }

    virtual ~TeachingAssistant() {
        delete[] taid;
        delete[] university;
    }

    void setTAid(char* tId) {
        if (taid) {
            delete[] taid;
        }
        taid = new char[strlen(tId) + 1];
        strcpy_s(taid, strlen(tId) + 1, tId);
        setTeachId(taid);
    }

    void setTAuni(char* tUni) {
        if (university) {
            delete[] university;
        }
        university = new char[strlen(tUni) + 1];
        strcpy_s(university, strlen(tUni) + 1, tUni);
        setTeachUni(university);
    }

    char* getTAid() {
        return taid;
    }

    char* getTAuni() {
        return university;
    }

    void showTA() {
        showPerson();
        showStd();
        showTeach();
    }

    ostream& print(ostream& os) {
        showTA();
        return os;
    }

    istream& input(istream& is) {
        char buffer[50];
        Subject sub;
        int len;

        Person::input(is);
        cout << "Enter student id: "; is >> buffer; setStdId(buffer);
        cout << "Enter university: "; is >> buffer; setUni(buffer);
        cout << "Enter len of subjects enrolled: "; is >> len;
        setAllSubj(len);

        cout << "Enter TA id: "; is >> buffer; setTAid(buffer);
        cout << "Enter university: "; is >> buffer; setTAuni(buffer);
        cout << "Enter len of teaching subjects: "; is >> len;
        setAllTeach(len);
        return is;
    }
};


ostream& operator<<(ostream& os, Person& person) {
    person.print(os);
    return os;
}

istream& operator>>(istream& is, Person& person) {
    person.input(is);
    return is;
}

void test10_1()
{
    // Test date
    cout << "\nTest date" << endl;
    Date date1;
    cin >> date1;
    cout << date1;

    // Test address
    cout << "\nTest address" << endl;
    Address add1;
    cin >> add1;
    cout << add1;

    // Test subject
    cout << "\nTest subject" << endl;
    Subject sub1;
    cin >> sub1;
    cout << sub1;

    // Test person
    cout << "\nTest person" << endl;
    Person p1;
    cin >> p1;
    cout << p1;

    // Test student
    cout << "\nTest student" << endl;
    Student std1;
    cin >> std1;
    cout << std1;

    // Test teacher
    cout << "\nTest teacher value" << endl;
    Teacher t1;
    cin >> t1;
    cout << t1;

    // Test TA
    cout << "\nTest TA value" << endl;
    TeachingAssistant ta1;
    cin >> ta1;
    cout << ta1;

    // Check
    cout << "\nCheck tid: " << ta1.getTeachId() << endl;
    cout << "Check taid: " << ta1.getTAid() << endl;
    (*ta1.getTeachId() == *ta1.getTAid()) ? cout << "Same" : cout << "Different";
    cout << endl;

    cout << "\nCheck teacher uni: " << ta1.getTeachUni() << endl;
    cout << "Check ta uni: " << ta1.getTAuni() << endl;
    (*ta1.getTeachUni() == *ta1.getTAuni()) ? cout << "Same" : cout << "Different";
    cout << endl;
}

