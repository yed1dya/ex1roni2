# 2074049997
CC = gcc
AR = ar
FLAGS = -Wall -g
BASIC = basicClassification.o
ADVANCEDLOOP = advancedClassificationLoop.o
ADVANCEDREC = advancedClassificationRecursion.o
NUMCLASS = NumClass.h

all : mains maindloop maindrec libclassloops.a

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

basicClassification.o : $(NUMCLASS)
	$(CC) $(FLAGS) -c -fPIC basicClassification.c

advancedClassificationLoop.o : $(NUMCLASS)
	$(CC) $(FLAGS) -c -fPIC advancedClassificationLoop.c

advancedClassificationRecursion.o : $(NUMCLASS)
	$(CC) $(FLAGS) -c -fPIC advancedClassificationRecursion.c

main.o : main.c $(NUMCLASS)
	$(CC) -c main.c

libclassloops.a : $(BASIC) $(ADVANCEDLOOP)
	$(AR) -rcs libclassloops.a $(BASIC) $(ADVANCEDLOOP)

libclassrec.a : $(BASIC) $(ADVANCEDREC)
	$(AR) -rcs libclassrec.a $(BASIC) $(ADVANCEDREC)

libclassloops.so : $(BASIC) $(ADVANCEDLOOP)
	$(CC) -shared -o libclassloops.so $(BASIC) $(ADVANCEDLOOP)

libclassrec.so : $(BASIC) $(ADVANCEDREC)
	$(CC) -shared -o libclassrec.so $(BASIC) $(ADVANCEDREC)

mains : main.o libclassrec.a
	$(CC) -o mains main.o libclassrec.a

maindloop : main.o libclassloops.so
	$(CC) -o maindloop main.o ./libclassloops.so

maindrec : main.o libclassrec.so
	$(CC) -o maindrec main.o ./libclassrec.so

.PHONY: all clean

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
