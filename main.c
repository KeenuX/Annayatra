#include "food_ordering_system.h"

// Global variables
User currentUser;
Restaurant restaurants[MAX_RESTAURANTS];
CartItem *cart = NULL;
int cartCount = 0;
int cartCapacity = 0;
int numRestaurants = 0;
User users[MAX_ITEMS];
int userCount = 0;

int main() {
    initializeSystem();
    
    int choice;
    
    while(1) {
        printf("\n===== Annayatra (अन्नयात्रा) =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if(loginUser()) {
                    // User successfully logged in
                    int userChoice;
                    do {
                        printf("\n===== WELCOME %s =====\n", currentUser.name);
                        printf("1. Browse Restaurants\n");
                        printf("2. View Cart\n");
                        printf("3. Checkout\n");
                        printf("4. Logout\n");
                        printf("Enter your choice: ");
                        
                        scanf("%d", &userChoice);
                        
                        switch(userChoice) {
                            case 1:
                                displayRestaurants();
                                break;
                            case 2:
                                viewCart();
                                break;
                            case 3:
                                if(cartCount > 0) {
                                    checkout();
                                } else {
                                    printf("Your cart is empty!\n");
                                }
                                break;
                            case 4:
                                printf("Logged out successfully!\n");
                                break;
                            default:
                                printf("Invalid choice! Please try again.\n");
                        }
                    } while(userChoice != 4);
                }
                break;
            case 3:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void initializeSystem() {
    // Load initial data
    loadRestaurants();
    loadUsers();
    
    // Initialize cart
    cartCapacity = 10;
    cart = (CartItem*)malloc(cartCapacity * sizeof(CartItem));
    if(cart == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Seed random number generator
    srand(time(NULL));
}