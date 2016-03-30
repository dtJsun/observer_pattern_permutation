OBJS = main.o heapobserver.o subject.o btrackingobserver.o checkinput.o
CC = clang++
DEBUG = -g
CFLAG = -Wall -c $(DEBUG)
LFLAG = -Wall $(DEBUG)

run : $(OBJS)
	$(CC) $(LFLAG) $(OBJS) -o run

main.o : main.cpp subject.h observer.h heapobserver.h
	$(CC) $(CFLAG) main.cpp

heapobserver.o : heapobserver.cpp heapobserver.h subject.h
	$(CC) $(CFLAG) heapobserver.cpp

btrackingobserver.o : btrackingobserver.cpp btrackingobserver.h subject.h
	$(CC) $(CFLAG) btrackingobserver.cpp
    
subject.o : subject.cpp subject.h heapobserver.h
	$(CC) $(CFLAG) subject.cpp

checkinput.o : checkinput.cpp checkinput.h
	$(CC) $(CFLAG) checkinput.cpp

clean:
	\rm *.o run output_Backtracking output_Heap