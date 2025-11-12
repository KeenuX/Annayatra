CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = food_ordering_system
SRCS = main.c user_management.c restaurant_management.c cart_management.c order_processing.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o
	del $(TARGET).exe

run: $(TARGET)
	./$(TARGET).exe

.PHONY: clean run