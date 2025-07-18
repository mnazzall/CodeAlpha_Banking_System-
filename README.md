# CodeAlpha_Banking_System


A simple console-based banking system written in C++. This project allows customers to register, login, manage their bank account, and view transaction history.

---

##  Features:

-  **Customer Registration & Login**
  - Stores customer data with account number and password.
  - Login verification using saved credentials.

-  **Account Management**
  - Deposit and withdraw money.
  - View account balance and details.

-  **Transaction History**
  - Saves each deposit and withdrawal in a transaction file.
  - Allows users to view full transaction history.

-  **File Storage**
  - `user.txt` — Stores user registration data in the format: `name:account_number:password`
  - `balance_<account_number>.txt` — Stores current balance
  - `history_<account_number>.txt` — Stores transaction records

---

##  How It Works:

### 1. Registration
- User enters a name, account number, and password.
- The system checks for duplicates and registers the user if unique.

### 2. Login
- User provides their name, account number, and password.
- System verifies credentials before granting access.

### 3. After Login
- Choose from the following options:
  - Deposit funds
  - Withdraw funds
  - View account details
  - View transaction history

---

##  File Structure:

- `Banking System.cpp` — Core application logic
- `user.txt` — Stores customer credentials
- `balance_<accNo>.txt` — Balance per account
- `history_<accNo>.txt` — Transaction history per account

---

##  Security Note:

> This system is for **learning purposes only**. Real-world systems require:
- Secure password storage (hashing, salting)
- Encrypted data files or databases
- Input validation and error handling
- Authentication and session management

---

