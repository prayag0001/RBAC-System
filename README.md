# RBAC-System
A lightweight and secure Role-Based Access Control system built with C++, MySQL, and JWT. Features include user authentication, role management, and fine-grained permission handling for modern applications. 🚀
🌟 Features
User Authentication: Secure login with hashed passwords (SHA-256).
Role Management: Assign roles to users for structured access.
Permission Control: Define and manage granular access to resources.
JWT Integration: Token-based authentication for session management.
📁 Project Structure
graphql
Copy code
project/
├── src/
│   ├── main.cpp         # Entry point
│   ├── database.cpp     # MySQL connection and queries
│   ├── routes.cpp       # API endpoints (login, registration)
│   ├── auth.cpp         # Authentication logic
│   ├── rbac.cpp         # Role-Based Access Control logic
│   └── utils.cpp        # Utility functions (JWT, token generation)
├── include/
│   ├── database.h       # Database logic header
│   ├── auth.h           # Authentication header
│   ├── rbac.h           # RBAC logic header
│   ├── utils.h          # Utility functions header
├── CMakeLists.txt       # Build configuration
└── README.md            # Documentation
⚙️ Setup
Install Prerequisites:

MySQL Server
MySQL Connector/C++
OpenSSL
CMake
Database Configuration:

Create the rbac_system database and tables.
Use the provided schema to set up the users, roles, permissions, and role_permissions tables.
Build the Project:

bash
Copy code
mkdir build && cd build
cmake ..
make
Run the Application: Execute the generated binary to start the RBAC system.

🛠️ Technologies Used
Language: C++
Database: MySQL
Security: JWT for authentication, OpenSSL for hashing
✨ How It Works
User Registration: Store user credentials with hashed passwords.
Authentication: Validate login credentials and generate JWT tokens.
Access Control:
Verify roles and permissions using database queries.
Grant or deny access to resources based on permissions.
📌 Why Choose This Project?
Scalable: Easily extendable for complex role and permission hierarchies.
Secure: Implements industry-standard authentication and access control mechanisms.
Lightweight: Designed for performance and simplicity.
🤝 Contributing
Feel free to fork the repository, submit pull requests, or report issues! 😊

⭐ If you like the project, give it a star! 🌟
