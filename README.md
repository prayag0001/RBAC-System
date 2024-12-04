# 🚀 **RBAC-System**  
A lightweight and secure **Role-Based Access Control** system built with **C++**, **MySQL**, and **JWT**.  
Features include **user authentication**, **role management**, and **fine-grained permission handling** for modern applications. 🔐

---

## 🌟 **Features**  
- 🔑 **User Authentication**: Secure login with hashed passwords (SHA-256).  
- 👥 **Role Management**: Assign roles to users for structured access.  
- 🔒 **Permission Control**: Define and manage granular access to resources.  
- 🎫 **JWT Integration**: Token-based authentication for session management.  

---

## 📁 **Project Structure**   
project/ <br/>
├── src/ <br/>
│ ├── main.cpp # 🏁 Entry point <br/>
│ ├── database.cpp # 🗄️ MySQL connection and queries <br/>
│ ├── routes.cpp # 🛣️ API endpoints (login, registration) <br/>
│ ├── auth.cpp # 🔐 Authentication logic <br/>
│ ├── rbac.cpp # 🛡️ Role-Based Access Control logic <br/>
│ └── utils.cpp # ⚙️ Utility functions (JWT, token generation) <br/>
├── include/ <br/>
│ ├── database.h # 🔧 Database logic header <br/>
│ ├── auth.h # 🧩 Authentication header <br/>
│ ├── rbac.h # 🔐 RBAC logic header <br/>
│ ├── utils.h # 🔄 Utility functions header <br/>
├── CMakeLists.txt # 🔨 Build configuration <br/>
└── README.md # 📖 Documentation <br/>

---

## ⚙️ Setup  

### 1. Install Prerequisites:  
- **MySQL Server**  
- **MySQL Connector/C++**  
- **OpenSSL**  
- **CMake**  

### 2. Database Configuration:  
- Create the `rbac_system` database and tables.  
- Use the provided schema to set up the `users`, `roles`, `permissions`, and `role_permissions` tables.  

### 3. Build the Project:  
```bash
mkdir build && cd build  
cmake ..  
make
```
## 🛠️  Technologies Used 
- Language: C++
- Database: MySQL
- Security: JWT for authentication, OpenSSL for hashing
## ✨  How It Works 
- 📝 User Registration: Store user credentials with hashed passwords.
- 🔑 Authentication: Validate login credentials and generate JWT tokens.
## 🛡️  Access Control: 
- 🔍 Verify roles and permissions using database queries.
- ✅ Grant or deny access to resources based on permissions.
## 📌 Why Choose This Project? 
- 🏗️ Scalable: Easily extendable for complex role and permission hierarchies.
- 🔒 Secure: Implements industry-standard authentication and access control mechanisms.
- ⚡ Lightweight: Designed for performance and simplicity.
## 🤝  Contributing 
- Feel free to fork the repository, submit pull requests, or report issues! 😊
* Your contributions are always welcome! * 💡



