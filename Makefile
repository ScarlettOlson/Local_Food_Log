
CC = gcc
CFLAGS = -Wall

Object_Tests: Object_Tests.o
	$(CC) $(CFLAGS) -o Tests.exe Object_Tests.o

Object_Tests.o: Testing/Object_Tests.c
	$(CC) $(CFLAGS) -c Testing/Object_Tests.c Food_Tracking/Objects/*.c

clean:
	rm -f *.o 
	rm -f *.gch

	rm -rf Testing/*.o 
	rm -rf Testing/*.gch

	rm -f Food_Tracking/*.o 
	rm -f Food_Tracking/*.gch 

	rm -f Food_Tracking/*/*.o
	rm -f Food_Tracking/*/*.gch
