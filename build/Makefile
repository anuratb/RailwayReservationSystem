IDIR = ../include/
SDIR = ../src/
TIDIR = ../test_include/
TSDIR = ../test_src/
CC = g++
CFLAGS = 


gender :  main.o gender.o genderTypes.o
	$(CC) $(CFLAGS) -o main main.o gender.o genderTypes.o
pass_date : main.o passenger.o date.o
	$(CC) $(CFLAGS) -o main main.o passenger.o date.o
clean_testapp :
	rm testapp.o
clean_testunit :
	rm testunit.o
clean_main :
	rm main.o

railways.o : station.o
	$(CC) $(CFLAGS) -c $(SDIR)railways.cpp
passenger.o : date.o	
	$(CC) $(CFLAGS) -c $(SDIR)passenger.cpp
station.o : 
	$(CC) $(CFLAGS) -c $(SDIR)station.cpp 
gender.o : 
	$(CC) $(CFLAGS) -c $(SDIR)gender.cpp 
genderTypes.o :
	$(CC) $(CFLAGS) -c $(SDIR)genderTypes.cpp 

Concessions.o : 
	$(CC) $(CFLAGS) -c $(SDIR)Concessions.cpp

divyangConcessions.o : 
	$(CC) $(CFLAGS) -c $(SDIR)divyangConcessions.cpp
genConcessions.o : 
	$(CC) $(CFLAGS) -c $(SDIR)genConcessions.cpp
LadiesConcession.o : 
	$(CC) $(CFLAGS) -c $(SDIR)LadiesConcession.cpp
srcitizenConcessions.o : 
	$(CC) $(CFLAGS) -c $(SDIR)srcitizenConcessions.cpp

Divyang.o :
	$(CC) $(CFLAGS) -c $(SDIR)Divyang.cpp
DivyangNames.o :
	$(CC) $(CFLAGS) -c $(SDIR)DivyangNames.cpp

booking.o : station.o  date.o bookingclass.o
	$(CC) $(CFLAGS) -c $(SDIR)booking.cpp 
bookingname.o : booking.o
	$(CC) $(CFLAGS) -c $(SDIR)bookingname.cpp 

date.o : 
	$(CC) $(CFLAGS) -c $(SDIR)date.cpp 

bookingclass.o : 
	$(CC) $(CFLAGS) -c $(SDIR)bookingclass.cpp
BookingClassNames.o : bookingclass.o
	$(CC) $(CFLAGS) -c $(SDIR)BookingClassNames.cpp

BookingCategory.o : 
	$(CC) $(CFLAGS) -c $(SDIR)BookingCategory.cpp
BookingCategoryNames.o : BookingCategory.o
	$(CC) $(CFLAGS) -c $(SDIR)BookingCategoryNames.cpp
bad_date.o :
	$(CC) $(CFLAGS) -c $(SDIR)bad_date.cpp
bad_booking.o :
	$(CC) $(CFLAGS) -c $(SDIR)bad_booking.cpp
bad_railways.o :
	$(CC) $(CFLAGS) -c $(SDIR)bad_railways.cpp
bad_station.o :
	$(CC) $(CFLAGS) -c $(SDIR)bad_station.cpp
bad_passenger.o :
	$(CC) $(CFLAGS) -c $(SDIR)bad_passenger.cpp

testunit : testunit.o railways.o passenger.o station.o bookingclass.o BookingClassNames.o BookingCategory.o BookingCategoryNames.o date.o booking.o bookingname.o bad_booking.o bad_date.o bad_passenger.o bad_railways.o bad_station.o gender.o genderTypes.o Concessions.o divyangConcessions.o genConcessions.o LadiesConcession.o srcitizenConcessions.o Divyang.o DivyangNames.o
	$(CC) $(CFLAGS) -o testunit testunit.o railways.o passenger.o station.o bookingclass.o BookingClassNames.o BookingCategory.o BookingCategoryNames.o date.o booking.o bookingname.o bad_booking.o bad_date.o bad_passenger.o bad_railways.o bad_station.o gender.o genderTypes.o Concessions.o divyangConcessions.o genConcessions.o LadiesConcession.o srcitizenConcessions.o Divyang.o DivyangNames.o
testunit.o :
	$(CC) $(CFLAGS) -c $(TSDIR)testunit.cpp
testapp : testapp.o railways.o passenger.o station.o bookingclass.o BookingClassNames.o BookingCategory.o BookingCategoryNames.o date.o booking.o bookingname.o bad_booking.o bad_date.o bad_passenger.o bad_railways.o bad_station.o gender.o genderTypes.o Concessions.o divyangConcessions.o genConcessions.o LadiesConcession.o srcitizenConcessions.o Divyang.o DivyangNames.o
	$(CC) $(CFLAGS) -o testapp testapp.o railways.o passenger.o station.o bookingclass.o BookingClassNames.o BookingCategory.o BookingCategoryNames.o date.o booking.o bookingname.o bad_booking.o bad_date.o bad_passenger.o bad_railways.o bad_station.o gender.o genderTypes.o Concessions.o divyangConcessions.o genConcessions.o LadiesConcession.o srcitizenConcessions.o Divyang.o DivyangNames.o
testapp.o :
	$(CC) $(CFLAGS) -c $(TSDIR)testapp.cpp
clean :
	rm *.o

