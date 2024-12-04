#include "auth.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

// Hash password with SHA256
std::string hash_password(const std::string& pwd) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)pwd.c_str(), pwd.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// Validate user login
bool validate_user(sql::Connection* db, const std::string& u, const std::string& p) {
    std::string hashed_pwd = hash_password(p);
    sql::PreparedStatement* stmt = db->prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?");
    stmt->setString(1, u);
    stmt->setString(2, hashed_pwd);

    sql::ResultSet* res = stmt->executeQuery();
    bool valid = res->next();
    delete res;
    delete stmt;
    return valid;
}
