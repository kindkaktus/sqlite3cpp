#include <string>
#include <iostream>
#include "sqlite3cpp.h"

static const std::string SqlCreate =
"BEGIN TRANSACTION;\n"
"CREATE TABLE Contacts (\n"
    "id INTEGER PRIMARY KEY AUTOINCREMENT,\n"
    "name char (128) NOT NULL,\n"
    "phone char(67) NULL\n"
");\n"
"INSERT INTO \"Contacts\" VALUES(1,'Andy','064001');\n"
"INSERT INTO \"Contacts\" VALUES(2,'Verka','064002');\n"
"INSERT INTO \"Contacts\" VALUES(3,'roma','064003');\n"
"COMMIT;\n";


using namespace std;

int main(int argc, char* argv[])
{
  try 
  {
      sqlite3cpp::database db("test.db", SqlCreate);
      sqlite3cpp::query qry(db, "SELECT id, name, phone FROM contacts");

      for (sqlite3cpp::query::iterator i = qry.begin(); i != qry.end(); ++i) 
      {
	    for (int j = 1; j <= qry.column_count(); ++j) 
	      cout << (*i).get<char const*>(j) << "\t";

	      cout << endl;
      }
      cout << endl;

      for (sqlite3cpp::query::iterator i = qry.begin(); i != qry.end(); ++i) 
      {
        int id;
        std::string name, phone;
        (*i) >> /*sqlite3cpp::ignore*/id >> name >> phone;
        cout << id << "\t" << name << "\t" << phone << endl;
      }
      cout << "TEST OK" << endl;
  }
  catch (exception& ex) {
    cout << ex.what() << endl;
  }
}
