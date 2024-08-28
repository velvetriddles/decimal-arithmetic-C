WWW = -std=c11 -Wall -Werror -Wextra
OS := $(shell uname)

ifeq ($(OS),Linux)
	CHFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	CHFLAGS = -lcheck -lm -lpthread
endif

all: clean s21_decimal.a

s21_decimal.a: s21_decimal.o
	ar -crs s21_decimal.a s21_*.o 

s21_decimal.o: s21_*.c s21_decimal.h
	gcc $(WWW) -c s21_*.c 

unit-test.o: unit-test.c
	gcc $(WWW) -c unit-test.c

test: clean s21_decimal.a
	gcc $(WWW) unit-test.c s21_decimal.a $(CHFLAGS) -o unit-test
	./unit-test

gcov_report: test
	gcc --coverage -lcheck unit-test.c s21_*.c -o unit-test
	./unit-test
	lcov -t "unit-test" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.gcov



clean:
	rm -rf *.o *.a unit-test
	rm -rf *.gcno *gcda *.gcov gcov program
	rm -rf report report.info
