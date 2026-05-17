# CodeAlpha_Banking_System (C++ OOP)
 This is a clean, console-based banking system built with C++ and Object Oriented Program(OOP).
It lets you create customers, manage accounts and perform real banking actions, all from a simple menu.

## What It Can Do
- Create customers
- Open accounts
- Deposit and withdraw money
- Transfer funds between accounts
- Track and display transaction history
- View acccount balance and details

  ## How It Is Built
  The system uses four core classes:
  - Customer : stores useer details
  - Accounts : handles balance + transactions
  - Transaction : records every activity
  - BankSystem : controls everything
    Each account keeps its own transaction history, so nothing gets lost.

    ## How To Run It
    - Use a C++ Compiler: g++ banking_system.cpp -o bank
    -Run: ./bank
   
      ## Menu Preview
      1. Create Customer
      2. Create Account 
      3. Deposit
      4. Withdraw
      5. Transfer
      6. View Account Details
      7. Exit
     
      ## Limitations
      This project is designed for designed for learning purposes and has some limitations
      - Data is stored in memory (no database or file storage)
      - No authentication/login system
      - No timestamps for transactions
      - No validation for duplicate IDs
     
        ## Possible Improvements
        - Add fike handling or database support
        - Implement user authentication
        - Include date and time for transactions
        - Add input validation and error handling
        - Limit and filter recent transaction
       
          ## Concepts Used
          - Classes and Objects
          - Encapsulation
          - Vectors
          - Basic input/output
          - Modular program design
         
            ## Author
            CHOLA VIRGINIA
