#include "food_ordering_system.h"

// Function to load restaurants and menus
void loadRestaurants() {
    // For simplicity, we'll hardcode some sample restaurants
    // In a real application, this would be loaded from a file
    
    // Restaurant 1
    restaurants[0].restaurantId = 1;
    strcpy(restaurants[0].restaurantName, "Taj Mahal Palace");
    restaurants[0].numItems = 4;
    
    restaurants[0].menu[0].itemId = 1;
    strcpy(restaurants[0].menu[0].itemName, "Butter Chicken");
    restaurants[0].menu[0].price = 350.00;
    restaurants[0].menu[0].availability = 1;
    
    restaurants[0].menu[1].itemId = 2;
    strcpy(restaurants[0].menu[1].itemName, "Biryani");
    restaurants[0].menu[1].price = 280.00;
    restaurants[0].menu[1].availability = 1;
    
    restaurants[0].menu[2].itemId = 3;
    strcpy(restaurants[0].menu[2].itemName, "Paneer Tikka");
    restaurants[0].menu[2].price = 220.00;
    restaurants[0].menu[2].availability = 1;
    
    restaurants[0].menu[3].itemId = 4;
    strcpy(restaurants[0].menu[3].itemName, "Naan Bread");
    restaurants[0].menu[3].price = 40.00;
    restaurants[0].menu[3].availability = 1;
    
    // Restaurant 2
    restaurants[1].restaurantId = 2;
    strcpy(restaurants[1].restaurantName, "Spice Garden");
    restaurants[1].numItems = 4;
    
    restaurants[1].menu[0].itemId = 1;
    strcpy(restaurants[1].menu[0].itemName, "Masala Dosa");
    restaurants[1].menu[0].price = 180.00;
    restaurants[1].menu[0].availability = 1;
    
    restaurants[1].menu[1].itemId = 2;
    strcpy(restaurants[1].menu[1].itemName, "Chole Bhature");
    restaurants[1].menu[1].price = 200.00;
    restaurants[1].menu[1].availability = 1;
    
    restaurants[1].menu[2].itemId = 3;
    strcpy(restaurants[1].menu[2].itemName, "Dal Makhani");
    restaurants[1].menu[2].price = 190.00;
    restaurants[1].menu[2].availability = 1;
    
    restaurants[1].menu[3].itemId = 4;
    strcpy(restaurants[1].menu[3].itemName, "Gulab Jamun");
    restaurants[1].menu[3].price = 120.00;
    restaurants[1].menu[3].availability = 1;
    
    // Restaurant 3
    restaurants[2].restaurantId = 3;
    strcpy(restaurants[2].restaurantName, "Bombay Street Food");
    restaurants[2].numItems = 4;
    
    restaurants[2].menu[0].itemId = 1;
    strcpy(restaurants[2].menu[0].itemName, "Vada Pav");
    restaurants[2].menu[0].price = 80.00;
    restaurants[2].menu[0].availability = 1;
    
    restaurants[2].menu[1].itemId = 2;
    strcpy(restaurants[2].menu[1].itemName, "Pav Bhaji");
    restaurants[2].menu[1].price = 150.00;
    restaurants[2].menu[1].availability = 1;
    
    restaurants[2].menu[2].itemId = 3;
    strcpy(restaurants[2].menu[2].itemName, "Samosa");
    restaurants[2].menu[2].price = 50.00;
    restaurants[2].menu[2].availability = 1;
    
    restaurants[2].menu[3].itemId = 4;
    strcpy(restaurants[2].menu[3].itemName, "Mango Lassi");
    restaurants[2].menu[3].price = 90.00;
    restaurants[2].menu[3].availability = 1;
    
    numRestaurants = 3;
}

// Function to display all restaurants
void displayRestaurants() {
    printf("\n===== AVAILABLE RESTAURANTS =====\n");
    for(int i = 0; i < numRestaurants; i++) {
        printf("%d. %s\n", restaurants[i].restaurantId, restaurants[i].restaurantName);
    }
    
    int choice;
    printf("Select a restaurant (0 to go back): ");
    if(scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    
    if(choice > 0 && choice <= numRestaurants) {
        displayMenu(choice);
    } else if(choice != 0) {
        printf("Invalid choice!\n");
    }
}

// Function to display menu of a specific restaurant
void displayMenu(int restaurantId) {
    int index = restaurantId - 1;
    
    if(index < 0 || index >= numRestaurants) {
        printf("Invalid restaurant ID!\n");
        return;
    }
    
    printf("\n===== MENU FOR %s =====\n", restaurants[index].restaurantName);
    for(int i = 0; i < restaurants[index].numItems; i++) {
        if(restaurants[index].menu[i].availability) {
            printf("%d. %s - ₹%.2f\n", 
                   restaurants[index].menu[i].itemId,
                   restaurants[index].menu[i].itemName,
                   restaurants[index].menu[i].price);
        }
    }
    
    int itemId, quantity;
    printf("Enter item ID to add to cart (0 to go back): ");
    scanf("%d", &itemId);
    
    if(itemId > 0) {
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        if(quantity > 0) {
            addToCart(restaurantId, itemId, quantity);
        } else {
            printf("Invalid quantity!\n");
        }
    }
}