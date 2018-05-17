CXX = g++
CFLAGS =
LDFLAGS = -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CXX) -c $(CFLAGS) $<

ALL = producer consumer producer_s consumer_s prodcons dining dining2 prodcons_m prodcons_s

all: $(ALL)

producer: producer.o 
	$(CXX) -o $@ $< $(LDFLAGS)

consumer: consumer.o 
	$(CXX) -o $@ $< $(LDFLAGS)

producer_s: producer_s.o semlib.o
	$(CXX) -o $@ $? $(LDFLAGS)

consumer_s: consumer_s.o semlib.o
	$(CXX) -o $@ $? $(LDFLAGS)

prodcons: prodcons.o
	$(CXX) -o $@ $< $(LDFLAGS)

dining: dining.o
	$(CXX) -o $@ $< $(LDFLAGS)

dining2: dining2.o
	$(CXX) -o $@ $< $(LDFLAGS)

prodcons_m: prodcons_m.o
	$(CXX) -o $@ $< $(LDFLAGS)

prodcons_s: prodcons_s.o semlib2.o
	$(CXX) -o $@ $? $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
