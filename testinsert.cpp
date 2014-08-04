#include <iostream>
#include "sqlite3cpp.h"

using namespace std;

static const std::string SqlCreate =
"BEGIN TRANSACTION;\n"
"CREATE TABLE Contacts (\n"
    "id INTEGER PRIMARY KEY AUTOINCREMENT,\n"
    "name char (128) NOT NULL,\n"
    "phone char(67) NULL\n"
");\n"
"COMMIT;\n";

int main(int argc, char* argv[])
{
  try 
  {
    sqlite3cpp::database db("test.db", SqlCreate);

    {
      db.execute("INSERT INTO contacts (name, phone) VALUES ('AAAA', '1234')");
    }

    {
      sqlite3cpp::transaction xct(db);

      sqlite3cpp::command cmd(db, "INSERT INTO contacts (name, phone) VALUES (?, ?)");

      cmd.bind(1, "BBBB");
      cmd.bind(2, "1234");
      cmd.execute();

      cmd.reset();

      cmd << "CCCC" << "1234";

      cmd.execute();
      xct.commit();
    }

    {
      sqlite3cpp::transaction xct(db, true);

      sqlite3cpp::command cmd(db, "INSERT INTO contacts (name, phone) VALUES (:name, :name)");

      cmd.bind(":name", "DDDD");

      cmd.execute();
      
      cout << "TEST OK" << endl;
    }
  }
  catch (exception& ex) {
    cout << ex.what() << endl;
  }

}
