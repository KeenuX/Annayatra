#ifndef FOOD_ORDERING_SYSTEM_H
#define FOOD_ORDERING_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_ITEMS 100
#define MAX_RESTAURANTS 20
#define MAX_CART_ITEMS 50

// User structure
typedef struct {
    int userId;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char email[MAX_NAME_LENGTH];
} User;

// Menu item structure
typedef struct {
    int itemId;
    char itemName[MAX_NAME_LENGTH];
    float price;
    int availability; // 1 for available, 0 for unavailable
} MenuItem;

// Restaurant structure
typedef struct {
    int restaurantId;
    char restaurantName[MAX_NAME_LENGTH];
    int numItems;
    MenuItem menu[MAX_ITEMS];
} Restaurant;

// Cart item structure
typedef struct {
    int itemId;
    char itemName[MAX_NAME_LENGTH];
    float price;
    int quantity;
} CartItem;

// Order structure
typedef struct {
    int orderId;
    int userId;
    char orderDate[20];
    float totalAmount;
    int numItems;
    CartItem items[MAX_CART_ITEMS];
    int estimatedDeliveryTime; // in minutes
} Order;

// Global variables
extern User currentUser;
extern Restaurant restaurants[MAX_RESTAURANTS];
extern CartItem *cart;
extern int cartCount;
extern int cartCapacity;
extern int numRestaurants;
extern User users[MAX_ITEMS];
extern int userCount;

// Function declarations
void loadRestaurants();
void loadUsers();
void saveUsers();
void saveOrder(Order order);
void displayRestaurants();
void displayMenu(int restaurantId);
void addToCart(int restaurantId, int itemId, int quantity);
void viewCart();
float calculateBill();
int generateDeliveryTime();
void checkout();
void registerUser();
int loginUser();
void saveOrderToLog(Order order);
int getUserId();
void initializeSystem();

#endif