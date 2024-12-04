#include "database.h"
#include "auth.h"
#include "rbac.h"
#include <iostream>

// Registration endpoint
void register_user(sql::Connection* db, const std::string& u, const std::string& p, const std::string& r) {
    std::string hashed_pwd = hash_password(p);
    sql::PreparedStatement* stmt = db->prepareStatement("INSERT INTO users (username, password, role) VALUES (?, ?, ?)");
    stmt->setString(1, u);
    stmt->setString(2, hashed_pwd);
    stmt->setString(3, r);
    stmt->execute();
    delete stmt;
}

// Login endpoint
void login_user(sql::Connection* db, const std::string& u, const std::string& p) {
    if (validate_user(db, u, p)) {
        sql::PreparedStatement* stmt = db->prepareStatement("SELECT role FROM users WHERE username = ?");
        stmt->setString(1, u);
        sql::ResultSet* res = stmt->executeQuery();
        if (res->next()) {
            std::string role = res->getString("role");
            std::string token = generate_token(u, role);
            std::cout << "Login successful. Token: " << token << std::endl;
        }
        delete res;
        delete stmt;
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }
}
