#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3* db;
    if (sqlite3_open("dnd_data.db", &db)) {
        std::cerr << "Nepodarilo sa otvoriť databázu\n";
        return 1;
    }
    std::cout << "Databáza otvorená!\n";
    sqlite3_close(db);
    return 0;
}

