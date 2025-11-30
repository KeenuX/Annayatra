# Annayatra (अन्नयात्रा) - Indian Food Ordering & Delivery System

A command-line C application that simulates an online Indian food ordering platform with user registration, restaurant browsing, cart management, and order processing.

## Features

- **User System**: Secure registration and login functionality.
- **Expanded Menu**: Browse **8 different restaurants** offering diverse cuisines:
    - North Indian
    - South Indian
    - Street Food
    - Italian
    - Chinese
    - Fast Food
    - Desserts
- **Smart Cart**: Dynamic shopping cart with memory management to handle multiple items.
- **Voucher System**: Apply discount codes during checkout to save money.
- **Optimized Delivery**: Realistic delivery time estimation (15-45 minutes).
- **Order Processing**: Detailed billing in **Rs.** with order confirmation.
- **Persistent Storage**: Uses binary files (`.dat`) for data and text files (`.txt`) for logs.

## Voucher Codes

Save on your orders with these valid voucher codes:
- `TASTY20`: **20% OFF**
- `SAVE10`: **10% OFF**
- `FREEMEAL`: **100% OFF** (Free Meal)

## Project Structure

```
.
├── main.c                  # Main application entry point
├── food_ordering_system.h  # Header file with data structures and declarations
├── user_management.c       # User registration and authentication
├── restaurant_management.c # Restaurant and menu handling
├── cart_management.c       # Shopping cart functionality
├── order_processing.c      # Order processing and storage
└── README.md               # This file
```

## Compilation & Running

### Prerequisites
- GCC compiler (MinGW on Windows recommended)

### Compile
Open your terminal/command prompt in the project directory and run:
```bash
gcc main.c user_management.c restaurant_management.c cart_management.c order_processing.c -o food_ordering_system
```

### Run
```bash
.\food_ordering_system.exe
```

## Usage Guide

1.  **Register**: Create a new account.
2.  **Login**: Log in with your credentials.
3.  **Browse**: Select a restaurant and view its menu (6 items per restaurant).
4.  **Order**: Add items to your cart.
5.  **Checkout**: 
    - Review your bill.
    - Enter a **Voucher Code** if you have one.
    - Confirm your order.
6.  **Enjoy**: Receive your estimated delivery time and a special offer for next time!

## Data Storage

- `users.dat`: Stores user credentials (Binary).
- `orders.dat`: Stores order history (Binary).
- `order_log.txt`: Human-readable log of all orders.

## Technical Highlights

- **Modular C Code**: Split across multiple files for better maintainability.
- **Structs & Arrays**: Used for managing complex data like menus and orders.
- **File I/O**: robust handling of binary and text files.
- **Randomization**: Used for delivery times and special offer messages.