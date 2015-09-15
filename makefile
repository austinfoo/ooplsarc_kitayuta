INCDIRS:=/Users/dmielke/Documents/oopl/trees/googletest/googletest/include
LIBDIRS:=/Users/dmielke/Documents/oopl/trees/googletest/googletest/make

FILES :=                              \
    .travis.yml                       \
    kitayuta-tests/EID-RunKitayuta.in   \
    kitayuta-tests/EID-RunKitayuta.out  \
    kitayuta-tests/EID-TestKitayuta.c++ \
    kitayuta-tests/EID-TestKitayuta.out \
    Kitayuta.c++                       \
    Kitayuta.h                         \
    Kitayuta.log                       \
    html                              \
    RunKitayuta.c++                    \
    RunKitayuta.in                     \
    RunKitayuta.out                    \
    TestKitayuta.c++                   \
    TestKitayuta.out                   \
    ColalatzBundle.c++

# Call gcc and gcov differently on Darwin
ifeq ($(shell uname), Darwin)
  CXX      := g++
  GCOV     := gcov
  VALGRIND := echo Valgrind not available on Darwin
else
  CXX      := g++-4.8
  GCOV     := gcov-4.8
  VALGRIND := valgrind
endif

CXXFLAGS   := -pedantic -std=c++11 -Wall -I$(INCDIRS)
LDFLAGS    := -lgtest -lgtest_main -pthread -L$(LIBDIRS)
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunKitayuta
	rm -f RunKitayuta.tmp
	rm -f TestKitayuta
	rm -f TestKitayuta.tmp
	rm -f KitayutaBundle

config:
	git config -l

bundle:
	cat Kitayuta.h Kitayuta.c++ RunKitayuta.c++ | sed -e "s/#include \"Kitayuta.h\"//g" > KitayutaBundle.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) KitayutaBundle.c++ -o KitayutaBundle

scrub:
	make  clean
	rm -f  Kitayuta.log
	rm -rf kitayuta-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunKitayuta.tmp TestKitayuta.tmp

RunKitayuta: Kitayuta.h Kitayuta.c++ RunKitayuta.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Kitayuta.c++ RunKitayuta.c++ -o RunKitayuta

RunKitayuta.tmp: RunKitayuta
	./RunKitayuta < RunKitayuta.in > RunKitayuta.tmp
	diff RunKitayuta.tmp RunKitayuta.out

TestKitayuta: Kitayuta.h Kitayuta.c++ TestKitayuta.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Kitayuta.c++ TestKitayuta.c++ -o TestKitayuta $(LDFLAGS)

TestKitayuta.tmp: TestKitayuta
	./TestKitayuta                                                   >  TestKitayuta.tmp 2>&1
	$(VALGRIND) ./TestKitayuta                                       >> TestKitayuta.tmp
	$(GCOV) -b Kitayuta.c++     | grep -A 5 "File 'Kitayuta.c++'"     >> TestKitayuta.tmp
	$(GCOV) -b TestKitayuta.c++ | grep -A 5 "File 'TestKitayuta.c++'" >> TestKitayuta.tmp
	cat TestKitayuta.tmp
