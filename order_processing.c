#include "food_ordering_system.h"

// Function to calculate bill
float calculateBill() {
    float total = 0;
    for(int i = 0; i < cartCount; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

// Function to generate random delivery time
int generateDeliveryTime() {
    // Generate random time between 20-60 minutes
    return 20 + rand() % 41;
}

// Function to checkout and place order
void checkout() {
    float total = calculateBill();
    int deliveryTime = generateDeliveryTime();
    
    printf("\n===== BILL DETAILS =====\n");
    for(int i = 0; i < cartCount; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        printf("%s - ₹%.2f x %d = ₹%.2f\n", 
               cart[i].itemName, cart[i].price, cart[i].quantity, itemTotal);
    }
    printf("TOTAL: ₹%.2f\n", total);
    printf("Estimated Delivery Time: %d minutes\n", deliveryTime);
    
    // Clear the input buffer before reading confirmation
    while(getchar() != '\n');
    
    int confirm;
    printf("\nConfirm order? (1 for Yes, 0 for No): ");
    if(scanf("%d", &confirm) != 1) {
        printf("Invalid input! Order cancelled.\n");
        // Clear the input buffer
        while(getchar() != '\n');
        return;
    }
    
    if(confirm) {
        // Create order
        Order order;
        static int orderId = 10000;
        order.orderId = ++orderId;
        order.userId = currentUser.userId;
        
        // Get current date and time
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(order.orderDate, sizeof(order.orderDate), "%Y-%m-%d %H:%M:%S", tm);
        
        order.totalAmount = total;
        order.numItems = cartCount;
        order.estimatedDeliveryTime = deliveryTime;
        
        // Copy cart items to order
        for(int i = 0; i < cartCount; i++) {
            order.items[i] = cart[i];
        }
        
        // Save order
        saveOrder(order);
        saveOrderToLog(order);
        
        // Clear cart
        cartCount = 0;
        
        printf("Order placed successfully! Order ID: %d\n", order.orderId);
        printf("Expected delivery time: %d minutes\n\n", deliveryTime);
        
        // Special greeting and offer messages
        const char* greetings[] = {
            "धन्यवाद! आपका ऑर्डर सफलतापूर्वक स्थापित किया गया है!",
            "Thank you! Your order has been successfully placed!",
            "शुक्रिया! आपला ऑर्डर यशस्वीरित्या स्थापित केला गेला आहे!",
            "ধন্যবাদ! আপনার অর্ডারটি সফলভাবে স্থাপন করা হয়েছে!"
        };
        
        const char* quotes[] = {
            "खाना खाओ और खुश रहो!",
            "Food is the ingredient that binds us together.",
            "In food we trust, in flavor we believe.",
            "Life is uncertain. Eat dessert first."
        };
        
        const char* offers[] = {
            "अगले ऑर्डर पर 10%% की छूट पाएं!",
            "Get 10%% off on your next order!",
            "Order one more time and get a free dessert!",
            "Refer a friend and get ₹100 in your wallet!"
        };
        
        // Generate random indices
        int greetIndex = rand() % 4;
        int quoteIndex = rand() % 4;
        int offerIndex = rand() % 4;
        
        printf("========== SPECIAL MESSAGE FOR YOU ==========\n");
        printf("%s\n\n", greetings[greetIndex]);
        printf("\"%s\"\n\n", quotes[quoteIndex]);
        printf("🎉 SPECIAL OFFER: %s\n", offers[offerIndex]);
        printf("============================================\n");
    } else {
        printf("Order cancelled.\n");
    }
}

// Function to save order to binary file
void saveOrder(Order order) {
    FILE *fp = fopen("orders.dat", "ab");
    if(fp == NULL) {
        printf("Error opening orders file!\n");
        return;
    }
    
    fwrite(&order, sizeof(Order), 1, fp);
    fclose(fp);
}

// Function to save order to text log
void saveOrderToLog(Order order) {
    FILE *fp = fopen("order_log.txt", "a");
    if(fp == NULL) {
        printf("Error opening order log file!\n");
        return;
    }
    
    fprintf(fp, "Order ID: %d | User ID: %d | Date: %s | Total: ₹%.2f | Items: ",
            order.orderId, order.userId, order.orderDate, order.totalAmount);
    
    for(int i = 0; i < order.numItems; i++) {
        fprintf(fp, "%s(x%d) ", order.items[i].itemName, order.items[i].quantity);
    }
    
    fprintf(fp, "| Delivery Time: %d minutes\n", order.estimatedDeliveryTime);
    fclose(fp);
}