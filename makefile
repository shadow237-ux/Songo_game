main_Tedongap:fonction_Tedongap.o main_Tedongap.o 
	gcc  fonction_Tedongap.o main_Tedongap.o -o main_Tedongap 
main_Tedongap.o:main_Tedongap.c
	gcc -c main_Tedongap.c 
fonction_Tedongap.o: fonction_Tedongap.c
	gcc -c fonction_Tedongap.c 