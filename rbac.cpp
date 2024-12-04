#include "rbac.h"

// Check if user has access to a specific permission
bool has_permission(sql::Connection* db, const std::string& role, const std::string& permission) {
    sql::PreparedStatement* stmt = db->prepareStatement(
        "SELECT rp.role_id FROM roles r "
        "JOIN role_permissions rp ON r.id = rp.role_id "
        "JOIN permissions p ON rp.permission_id = p.id "
        "WHERE r.role_name = ? AND p.permission_name = ?"
    );
    stmt->setString(1, role);
    stmt->setString(2, permission);

    sql::ResultSet* res = stmt->executeQuery();
    bool allowed = res->next();
    delete res;
    delete stmt;
    return allowed;
}
