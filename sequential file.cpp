#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct stud {
    int roll;
    char name[10];
    char div;
    char add[10];
} rec;

class student {
public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout;
    fout.open("stud.dat", ios::out | ios::binary);

    do {
        cout << "\n\tEnter Roll No of Student: ";
        cin >> rec.roll;
        cout << "\n\tEnter Name of Student: ";
        cin >> rec.name;
        cout << "\n\tEnter Division of Student: ";
        cin >> rec.div;
        cout << "\n\tEnter Address of Student: ";
        cin >> rec.add;

        fout.write((char*)&rec, sizeof(stud)) << flush;

        cout << "\n\tDo You Want to Add More Records? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    fout.close();
}

void student::display() {
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    fin.seekg(0, ios::beg);

    cout << "\n\tThe Contents of the File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";

    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll != -1) {
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
        }
    }

    fin.close();
}

int student::search() {
    int r, i = 0;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    fin.seekg(0, ios::beg);

    cout << "\n\tEnter Roll No to Search: ";
    cin >> r;

    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            fin.close();
            return i;
        }
        i++;
    }

    fin.close();
    return -1; // changed to -1 to indicate "not found"
}

void student::Delete() {
    int pos = search();
    if (pos == -1) {
        cout << "\n\tRecord Not Found";
        return;
    }

    fstream f;
    f.open("stud.dat", ios::in | ios::out | ios::binary);
    int offset = pos * sizeof(stud);
    f.seekp(offset);

    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");

    f.write((char*)&rec, sizeof(stud));
    f.close();

    cout << "\n\tRecord Deleted";
}

int main() {
    student obj;
    int ch, key;
    char ans;

    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.Delete();
                break;
            case 4:
                key = obj.search();
                if (key == -1)
                    cout << "\n\tRecord not found.";
                break;
            case 5:
                return 0;
        }

        cout << "\n\t..... Do You Want to Continue in Main Menu? (Y/N): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}
