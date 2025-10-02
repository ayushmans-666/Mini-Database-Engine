#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// Record 
class Record {
public:
    vector<string> fields;
    Record() {}
    Record(const vector<string> &f){ fields = f; }

    string serialize(){
        string s;
        for(size_t i=0;i<fields.size();i++){
            s += fields[i];
            if(i!=fields.size()-1) s+=",";
        }
        return s;
    }

    static Record deserialize(const string &line){
        vector<string> f;
        stringstream ss(line);
        string field;
        while(getline(ss, field, ',')) f.push_back(field);
        return Record(f);
    }

    void display(){
        for(auto &f: fields) cout << f << "\t";
        cout << endl;
    }
};

// Table
class Table {
public:
    string name;
    vector<string> columns;
    vector<Record> records;

    Table() {}
    Table(const string &n, const vector<string> &cols){
        name = n;
        columns = cols;
    }

    void insertRecord(const Record &r){
        if(r.fields.size() != columns.size()){
            cout<<"Error: Column count mismatch!"<<endl;
            return;
        }
        records.push_back(r);
    }

    void displayRecords(){
        for(auto &col: columns) cout << col << "\t";
        cout << endl;
        for(auto &r: records) r.display();
    }

    void saveToFile(){
        ofstream file(name+".txt");
        for(auto &r: records) file << r.serialize() << endl;
        file.close();
    }

    void loadFromFile(){
        ifstream file(name+".txt");
        string line;
        records.clear();
        while(getline(file,line)){
            records.push_back(Record::deserialize(line));
        }
        file.close();
    }
};

// Database
class Database {
public:
    map<string, Table> tables;

    void createTable(const string &name, const vector<string> &columns){
        Table t(name, columns);
        tables[name] = t;
        cout<<"Table "<<name<<" created successfully.\n";
    }

    void insertIntoTable(const string &name, const Record &r){
        if(tables.find(name)==tables.end()){
            cout<<"Table "<<name<<" does not exist!\n";
            return;
        }
        tables[name].insertRecord(r);
    }

    void displayTable(const string &name){
        if(tables.find(name)==tables.end()){
            cout<<"Table "<<name<<" does not exist!\n";
            return;
        }
        tables[name].displayRecords();
    }

    void saveAll(){
        for(auto &p: tables) p.second.saveToFile();
    }

    void loadAll(){
        for(auto &p: tables){
            ifstream f(p.first+".txt");
            if(f.good()) p.second.loadFromFile();
        }
    }
};

// Main 
int main(){
    Database db;
    db.loadAll();

    int choice;
    while(true){
        cout<<"\n==== Mini Database Engine ====\n";
        cout<<"1. Create Table\n2. Insert Record\n3. Display Table\n4. Save & Exit\n";
        cout<<"Enter choice: "; cin>>choice;
        cin.ignore();

        if(choice==1){
            string tname; int colCount;
            cout<<"Table name: "; getline(cin,tname);
            cout<<"Number of columns: "; cin>>colCount; cin.ignore();
            vector<string> cols(colCount);
            for(int i=0;i<colCount;i++){
                cout<<"Column "<<i+1<<" name: "; getline(cin, cols[i]);
            }
            db.createTable(tname, cols);
        }
        else if(choice==2){
            string tname; cout<<"Table name: "; getline(cin, tname);
            if(db.tables.find(tname)==db.tables.end()){ cout<<"Table does not exist.\n"; continue; }
            vector<string> vals(db.tables[tname].columns.size());
            for(size_t i=0;i<vals.size();i++){
                cout<<"Enter "<<db.tables[tname].columns[i]<<": ";
                getline(cin, vals[i]);
            }
            db.insertIntoTable(tname, Record(vals));
        }
        else if(choice==3){
            string tname; cout<<"Table name: "; getline(cin, tname);
            db.displayTable(tname);
        }
        else if(choice==4){
            db.saveAll();
            cout<<"Data saved. Exiting...\n";
            break;
        }
        else cout<<"Invalid choice!\n";
    }
}
