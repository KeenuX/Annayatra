#include "food_ordering_system.h"

// Function to load restaurants and menus
void loadRestaurants() {
    // Restaurant 1: Taj Mahal Palace (North Indian)
    restaurants[0].restaurantId = 1;
    strcpy(restaurants[0].restaurantName, "Taj Mahal Palace");
    restaurants[0].numItems = 6;
    
    restaurants[0].menu[0].itemId = 1; strcpy(restaurants[0].menu[0].itemName, "Butter Chicken"); restaurants[0].menu[0].price = 350.00; restaurants[0].menu[0].availability = 1;
    restaurants[0].menu[1].itemId = 2; strcpy(restaurants[0].menu[1].itemName, "Biryani"); restaurants[0].menu[1].price = 280.00; restaurants[0].menu[1].availability = 1;
    restaurants[0].menu[2].itemId = 3; strcpy(restaurants[0].menu[2].itemName, "Paneer Tikka"); restaurants[0].menu[2].price = 220.00; restaurants[0].menu[2].availability = 1;
    restaurants[0].menu[3].itemId = 4; strcpy(restaurants[0].menu[3].itemName, "Naan Bread"); restaurants[0].menu[3].price = 40.00; restaurants[0].menu[3].availability = 1;
    restaurants[0].menu[4].itemId = 5; strcpy(restaurants[0].menu[4].itemName, "Dal Tadka"); restaurants[0].menu[4].price = 180.00; restaurants[0].menu[4].availability = 1;
    restaurants[0].menu[5].itemId = 6; strcpy(restaurants[0].menu[5].itemName, "Jeera Rice"); restaurants[0].menu[5].price = 150.00; restaurants[0].menu[5].availability = 1;
    
    // Restaurant 2: Spice Garden (South Indian)
    restaurants[1].restaurantId = 2;
    strcpy(restaurants[1].restaurantName, "Spice Garden");
    restaurants[1].numItems = 6;
    
    restaurants[1].menu[0].itemId = 1; strcpy(restaurants[1].menu[0].itemName, "Masala Dosa"); restaurants[1].menu[0].price = 180.00; restaurants[1].menu[0].availability = 1;
    restaurants[1].menu[1].itemId = 2; strcpy(restaurants[1].menu[1].itemName, "Chole Bhature"); restaurants[1].menu[1].price = 200.00; restaurants[1].menu[1].availability = 1;
    restaurants[1].menu[2].itemId = 3; strcpy(restaurants[1].menu[2].itemName, "Dal Makhani"); restaurants[1].menu[2].price = 190.00; restaurants[1].menu[2].availability = 1;
    restaurants[1].menu[3].itemId = 4; strcpy(restaurants[1].menu[3].itemName, "Gulab Jamun"); restaurants[1].menu[3].price = 120.00; restaurants[1].menu[3].availability = 1;
    restaurants[1].menu[4].itemId = 5; strcpy(restaurants[1].menu[4].itemName, "Idli Sambar"); restaurants[1].menu[4].price = 100.00; restaurants[1].menu[4].availability = 1;
    restaurants[1].menu[5].itemId = 6; strcpy(restaurants[1].menu[5].itemName, "Uttapam"); restaurants[1].menu[5].price = 160.00; restaurants[1].menu[5].availability = 1;
    
    // Restaurant 3: Bombay Street Food (Street Food)
    restaurants[2].restaurantId = 3;
    strcpy(restaurants[2].restaurantName, "Bombay Street Food");
    restaurants[2].numItems = 6;
    
    restaurants[2].menu[0].itemId = 1; strcpy(restaurants[2].menu[0].itemName, "Vada Pav"); restaurants[2].menu[0].price = 80.00; restaurants[2].menu[0].availability = 1;
    restaurants[2].menu[1].itemId = 2; strcpy(restaurants[2].menu[1].itemName, "Pav Bhaji"); restaurants[2].menu[1].price = 150.00; restaurants[2].menu[1].availability = 1;
    restaurants[2].menu[2].itemId = 3; strcpy(restaurants[2].menu[2].itemName, "Samosa"); restaurants[2].menu[2].price = 50.00; restaurants[2].menu[2].availability = 1;
    restaurants[2].menu[3].itemId = 4; strcpy(restaurants[2].menu[3].itemName, "Mango Lassi"); restaurants[2].menu[3].price = 90.00; restaurants[2].menu[3].availability = 1;
    restaurants[2].menu[4].itemId = 5; strcpy(restaurants[2].menu[4].itemName, "Bhel Puri"); restaurants[2].menu[4].price = 70.00; restaurants[2].menu[4].availability = 1;
    restaurants[2].menu[5].itemId = 6; strcpy(restaurants[2].menu[5].itemName, "Pani Puri"); restaurants[2].menu[5].price = 60.00; restaurants[2].menu[5].availability = 1;

    // Restaurant 4: Pizza Piazza (Italian)
    restaurants[3].restaurantId = 4;
    strcpy(restaurants[3].restaurantName, "Pizza Piazza");
    restaurants[3].numItems = 6;

    restaurants[3].menu[0].itemId = 1; strcpy(restaurants[3].menu[0].itemName, "Margherita Pizza"); restaurants[3].menu[0].price = 250.00; restaurants[3].menu[0].availability = 1;
    restaurants[3].menu[1].itemId = 2; strcpy(restaurants[3].menu[1].itemName, "Pepperoni Pizza"); restaurants[3].menu[1].price = 350.00; restaurants[3].menu[1].availability = 1;
    restaurants[3].menu[2].itemId = 3; strcpy(restaurants[3].menu[2].itemName, "Pasta Alfredo"); restaurants[3].menu[2].price = 280.00; restaurants[3].menu[2].availability = 1;
    restaurants[3].menu[3].itemId = 4; strcpy(restaurants[3].menu[3].itemName, "Garlic Bread"); restaurants[3].menu[3].price = 120.00; restaurants[3].menu[3].availability = 1;
    restaurants[3].menu[4].itemId = 5; strcpy(restaurants[3].menu[4].itemName, "Lasagna"); restaurants[3].menu[4].price = 320.00; restaurants[3].menu[4].availability = 1;
    restaurants[3].menu[5].itemId = 6; strcpy(restaurants[3].menu[5].itemName, "Tiramisu"); restaurants[3].menu[5].price = 180.00; restaurants[3].menu[5].availability = 1;

    // Restaurant 5: Dragon Wok (Chinese)
    restaurants[4].restaurantId = 5;
    strcpy(restaurants[4].restaurantName, "Dragon Wok");
    restaurants[4].numItems = 6;

    restaurants[4].menu[0].itemId = 1; strcpy(restaurants[4].menu[0].itemName, "Hakka Noodles"); restaurants[4].menu[0].price = 180.00; restaurants[4].menu[0].availability = 1;
    restaurants[4].menu[1].itemId = 2; strcpy(restaurants[4].menu[1].itemName, "Manchurian"); restaurants[4].menu[1].price = 200.00; restaurants[4].menu[1].availability = 1;
    restaurants[4].menu[2].itemId = 3; strcpy(restaurants[4].menu[2].itemName, "Fried Rice"); restaurants[4].menu[2].price = 190.00; restaurants[4].menu[2].availability = 1;
    restaurants[4].menu[3].itemId = 4; strcpy(restaurants[4].menu[3].itemName, "Spring Rolls"); restaurants[4].menu[3].price = 150.00; restaurants[4].menu[3].availability = 1;
    restaurants[4].menu[4].itemId = 5; strcpy(restaurants[4].menu[4].itemName, "Chilli Paneer"); restaurants[4].menu[4].price = 220.00; restaurants[4].menu[4].availability = 1;
    restaurants[4].menu[5].itemId = 6; strcpy(restaurants[4].menu[5].itemName, "Momos"); restaurants[4].menu[5].price = 120.00; restaurants[4].menu[5].availability = 1;

    // Restaurant 6: Burger Barn (Fast Food)
    restaurants[5].restaurantId = 6;
    strcpy(restaurants[5].restaurantName, "Burger Barn");
    restaurants[5].numItems = 6;

    restaurants[5].menu[0].itemId = 1; strcpy(restaurants[5].menu[0].itemName, "Veggie Burger"); restaurants[5].menu[0].price = 120.00; restaurants[5].menu[0].availability = 1;
    restaurants[5].menu[1].itemId = 2; strcpy(restaurants[5].menu[1].itemName, "Chicken Burger"); restaurants[5].menu[1].price = 180.00; restaurants[5].menu[1].availability = 1;
    restaurants[5].menu[2].itemId = 3; strcpy(restaurants[5].menu[2].itemName, "French Fries"); restaurants[5].menu[2].price = 90.00; restaurants[5].menu[2].availability = 1;
    restaurants[5].menu[3].itemId = 4; strcpy(restaurants[5].menu[3].itemName, "Coke"); restaurants[5].menu[3].price = 60.00; restaurants[5].menu[3].availability = 1;
    restaurants[5].menu[4].itemId = 5; strcpy(restaurants[5].menu[4].itemName, "Nuggets"); restaurants[5].menu[4].price = 150.00; restaurants[5].menu[4].availability = 1;
    restaurants[5].menu[5].itemId = 6; strcpy(restaurants[5].menu[5].itemName, "Milkshake"); restaurants[5].menu[5].price = 140.00; restaurants[5].menu[5].availability = 1;

    // Restaurant 7: South Indian Sagar (South Indian)
    restaurants[6].restaurantId = 7;
    strcpy(restaurants[6].restaurantName, "South Indian Sagar");
    restaurants[6].numItems = 6;

    restaurants[6].menu[0].itemId = 1; strcpy(restaurants[6].menu[0].itemName, "Rava Dosa"); restaurants[6].menu[0].price = 160.00; restaurants[6].menu[0].availability = 1;
    restaurants[6].menu[1].itemId = 2; strcpy(restaurants[6].menu[1].itemName, "Medu Vada"); restaurants[6].menu[1].price = 100.00; restaurants[6].menu[1].availability = 1;
    restaurants[6].menu[2].itemId = 3; strcpy(restaurants[6].menu[2].itemName, "Upma"); restaurants[6].menu[2].price = 80.00; restaurants[6].menu[2].availability = 1;
    restaurants[6].menu[3].itemId = 4; strcpy(restaurants[6].menu[3].itemName, "Filter Coffee"); restaurants[6].menu[3].price = 40.00; restaurants[6].menu[3].availability = 1;
    restaurants[6].menu[4].itemId = 5; strcpy(restaurants[6].menu[4].itemName, "Mysore Pak"); restaurants[6].menu[4].price = 90.00; restaurants[6].menu[4].availability = 1;
    restaurants[6].menu[5].itemId = 6; strcpy(restaurants[6].menu[5].itemName, "Curd Rice"); restaurants[6].menu[5].price = 110.00; restaurants[6].menu[5].availability = 1;

    // Restaurant 8: Sweet Tooth (Desserts)
    restaurants[7].restaurantId = 8;
    strcpy(restaurants[7].restaurantName, "Sweet Tooth");
    restaurants[7].numItems = 6;

    restaurants[7].menu[0].itemId = 1; strcpy(restaurants[7].menu[0].itemName, "Chocolate Cake"); restaurants[7].menu[0].price = 150.00; restaurants[7].menu[0].availability = 1;
    restaurants[7].menu[1].itemId = 2; strcpy(restaurants[7].menu[1].itemName, "Ice Cream"); restaurants[7].menu[1].price = 100.00; restaurants[7].menu[1].availability = 1;
    restaurants[7].menu[2].itemId = 3; strcpy(restaurants[7].menu[2].itemName, "Brownie"); restaurants[7].menu[2].price = 120.00; restaurants[7].menu[2].availability = 1;
    restaurants[7].menu[3].itemId = 4; strcpy(restaurants[7].menu[3].itemName, "Rasmalai"); restaurants[7].menu[3].price = 140.00; restaurants[7].menu[3].availability = 1;
    restaurants[7].menu[4].itemId = 5; strcpy(restaurants[7].menu[4].itemName, "Kheer"); restaurants[7].menu[4].price = 110.00; restaurants[7].menu[4].availability = 1;
    restaurants[7].menu[5].itemId = 6; strcpy(restaurants[7].menu[5].itemName, "Fruit Salad"); restaurants[7].menu[5].price = 130.00; restaurants[7].menu[5].availability = 1;
    
    numRestaurants = 8;
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
    
    int itemId, quantity;
    
    do {
        printf("\n===== MENU FOR %s =====\n", restaurants[index].restaurantName);
        for(int i = 0; i < restaurants[index].numItems; i++) {
            if(restaurants[index].menu[i].availability) {
                printf("%d. %s - Rs.%.2f\n", 
                       restaurants[index].menu[i].itemId,
                       restaurants[index].menu[i].itemName,
                       restaurants[index].menu[i].price);
            }
        }
        
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
    } while(itemId != 0);
}