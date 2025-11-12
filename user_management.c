#include "food_ordering_system.h"

// Function to load users from binary file
void loadUsers() {
    FILE *fp = fopen("users.dat", "rb");
    if(fp == NULL) {
        // Create file if it doesn't exist
        fp = fopen("users.dat", "wb");
        fclose(fp);
        userCount = 0;
        return;
    }
    
    // Read all users from file
    userCount = 0;
    while(fread(&users[userCount], sizeof(User), 1, fp)) {
        userCount++;
    }
    
    fclose(fp);
}

// Function to save users to binary file
void saveUsers() {
    FILE *fp = fopen("users.dat", "wb");
    if(fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for(int i = 0; i < userCount; i++) {
        fwrite(&users[i], sizeof(User), 1, fp);
    }
    
    fclose(fp);
}

// Function to register a new user
void registerUser() {
    if(userCount >= MAX_ITEMS) {
        printf("Maximum user limit reached!\n");
        return;
    }
    
    User newUser;
    newUser.userId = getUserId();
    
    printf("Enter your name: ");
    scanf(" %[^\n]s", newUser.name);
    
    printf("Enter your email: ");
    scanf(" %[^\n]s", newUser.email);
    
    printf("Enter password: ");
    scanf(" %[^\n]s", newUser.password);
    
    // Add user to array
    users[userCount] = newUser;
    userCount++;
    
    // Save to file
    saveUsers();
    
    printf("Registration successful! Your User ID is %d\n", newUser.userId);
}

// Function to login user
int loginUser() {
    char email[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter your email: ");
    scanf(" %[^\n]s", email);
    
    printf("Enter password: ");
    scanf(" %[^\n]s", password);
    
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].email, email) == 0 && strcmp(users[i].password, password) == 0) {
            currentUser = users[i];
            printf("Login successful! Welcome %s\n", currentUser.name);
            return 1;
        }
    }
    
    printf("Invalid credentials!\n");
    return 0;
}

// Function to generate new user ID
int getUserId() {
    static int id = 1000;
    return ++id;
}