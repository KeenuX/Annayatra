#include "food_ordering_system.h"

// Function to add item to cart
void addToCart(int restaurantId, int itemId, int quantity) {
    int index = restaurantId - 1;
    
    // Find the item in the restaurant menu
    MenuItem *item = NULL;
    for(int i = 0; i < restaurants[index].numItems; i++) {
        if(restaurants[index].menu[i].itemId == itemId) {
            item = &restaurants[index].menu[i];
            break;
        }
    }
    
    if(item == NULL) {
        printf("Item not found!\n");
        return;
    }
    
    if(!item->availability) {
        printf("Item is currently unavailable!\n");
        return;
    }
    
    // Check if item already exists in cart
    int existingIndex = -1;
    for(int i = 0; i < cartCount; i++) {
        if(cart[i].itemId == itemId) {
            existingIndex = i;
            break;
        }
    }
    
    if(existingIndex != -1) {
        // Item already in cart, update quantity
        cart[existingIndex].quantity += quantity;
        printf("Updated quantity of %s to %d\n", item->itemName, cart[existingIndex].quantity);
    } else {
        // Add new item to cart
        // Check if we need to expand cart capacity
        if(cartCount >= cartCapacity) {
            cartCapacity *= 2;
            cart = (CartItem*)realloc(cart, cartCapacity * sizeof(CartItem));
            if(cart == NULL) {
                printf("Memory allocation failed!\n");
                return;
            }
        }
        
        // Add item to cart
        cart[cartCount].itemId = itemId;
        strcpy(cart[cartCount].itemName, item->itemName);
        cart[cartCount].price = item->price;
        cart[cartCount].quantity = quantity;
        cartCount++;
        
        printf("Added %d x %s to cart\n", quantity, item->itemName);
    }
}

// Function to view cart
void viewCart() {
    if(cartCount == 0) {
        printf("Your cart is empty!\n");
        return;
    }
    
    printf("\n===== YOUR CART =====\n");
    float total = 0;
    
    for(int i = 0; i < cartCount; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        total += itemTotal;
        printf("%d. %s - ₹%.2f x %d = ₹%.2f\n", 
               i+1, cart[i].itemName, cart[i].price, cart[i].quantity, itemTotal);
    }
    
    printf("TOTAL: $%.2f\n", total);
    
    int choice;
    printf("\n1. Continue shopping\n");
    printf("2. Clear cart\n");
    printf("Enter your choice: ");
    if(scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    
    if(choice == 2) {
        cartCount = 0;
        printf("Cart cleared!\n");
    }
}