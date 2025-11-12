# Annayatra (अन्नयात्रा) - Indian Food Ordering & Delivery System

A command-line C application that simulates an online Indian food ordering platform with user registration, restaurant browsing, cart management, and order processing.

## Features

- User registration and login system
- Indian restaurant browsing with authentic menus
- Dynamic shopping cart with memory management
- Order placement with billing in Rupees (₹) and delivery time estimation
- Personalized greetings, quotes, and special offers after successful orders
- Persistent data storage using binary files and text logs

## Project Structure

```
.
├── main.c                  # Main application entry point
├── food_ordering_system.h  # Header file with data structures and declarations
├── user_management.c       # User registration and authentication
├── restaurant_management.c # Restaurant and menu handling
├── cart_management.c       # Shopping cart functionality
├── order_processing.c      # Order processing and storage
├── Makefile                # Build automation
└── README.md               # This file
```

## Requirements

- GCC compiler (MinGW on Windows)
- C99 standard support

## Compilation

### Using Makefile (Recommended)
```bash
make
```

### Direct Compilation
```bash
gcc -Wall -Wextra -std=c99 -o food_ordering_system main.c user_management.c restaurant_management.c cart_management.c order_processing.c
```

## Running the Program

### Using Makefile
```bash
make run
```

### Direct Execution
```bash
./food_ordering_system.exe
```

## Usage

1. **Register** - Create a new user account
2. **Login** - Access the system with existing credentials
3. **Browse Restaurants** - View available restaurants and their menus
4. **Add Items to Cart** - Select menu items and quantities
5. **View Cart** - Review selected items and total cost
6. **Checkout** - Place order and receive delivery estimate
7. **Logout** - End session

## Data Storage

- `users.dat` - Binary file storing registered user information
- `orders.dat` - Binary file storing order history
- `order_log.txt` - Text file with human-readable order logs

## Technical Implementation

- **Data Structures**: Users, Restaurants, Menu Items, Cart Items, and Orders
- **Dynamic Memory**: realloc for expanding cart capacity
- **File Handling**: Binary files for efficient data storage, text files for readable logs
- **Input Validation**: Robust input handling with error checking
- **Modular Design**: Separation of concerns across multiple source files
- **Localization**: Indian cuisine with prices in Rupees (₹)
- **Personalization**: Randomized greetings, quotes, and special offers for each customer

## Academic Requirements Met

This project satisfies all requirements for the Computer Programming course:
- Use of structures for organized data management
- Dynamic memory allocation with realloc
- File handling in both binary and text modes
- String manipulation with strcmp, strcpy
- Implementation of filtering/search functionality
- Time logic for delivery estimation
- Indian localization with regional languages and currency