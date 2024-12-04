#include <iostream>
#include <string>
#include "database.h"
#include "auth.h"
#include "rbac.h"
#include "utils.h"

void print_menu() {
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Check Permission\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    // Establish database connection
    sql::Connection* db = connect_db(rbac_system);
    
    int choice;
    std::string username, password, role, permission;

    while (true) {
        print_menu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left behind by std::cin

        switch (choice) {
            case 1: {
                // Register user
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                std::cout << "Enter role: ";
                std::getline(std::cin, role);
                
                register_user(db, username, password, role);
                std::cout << "User registered successfully.\n";
                break;
            }
            case 2: {
                // Login user
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                login_user(db, username, password);
                break;
            }
            case 3: {
                // Check permission
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter permission to check: ";
                std::getline(std::cin, permission);

                sql::PreparedStatement* stmt = db->prepareStatement("SELECT role FROM users WHERE username = ?");
                stmt->setString(1, username);
                sql::ResultSet* res = stmt->executeQuery();
                
                if (res->next()) {
                    std::string role = res->getString("role");
                    if (has_permission(db, role, permission)) {
                        std::cout << "User has permission: " << permission << "\n";
                    } else {
                        std::cout << "User does not have permission: " << permission << "\n";
                    }
                } else {
                    std::cout << "User not found.\n";
                }
                
                delete res;
                delete stmt;
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                delete db;  // Close the connection
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
