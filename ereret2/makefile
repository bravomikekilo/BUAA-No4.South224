Studenttest:student_main.o Student.o Date.o
	g++ student_main.o Student.o Date.o -o Studenttest

Student.o:Student.cpp Student.h 
Date.o:Date.cpp Date.h

.PHONY:clean
clean:
	rm -rf *.o Studenttest 
