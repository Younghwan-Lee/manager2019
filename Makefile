CC = gcc
CFLAGS = -W -Wall
TARGET = manager
TARGET_D = manager_d
OBJECTS = menu.o user.o main.c
OBJECTS_D = menu_d.o user_d.o main.c

all : $(TARGET)

$(TARGET_D) : $(OBJECTS_D)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

user_d.o : user.c
	gcc -DDEBUG_MODE -c -o user_d.o user.c

menu_d.o : menu.c
	gcc -DDEBUG_MODE -c -o menu_d.o menu.c

clean :
	rm *.o manager

clean_d :
	rm *.o manager_d
