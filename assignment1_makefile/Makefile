CC = gcc					#변수 CC = gcc
CFLAGS = -Wall				#변수 CFLAGS = -Wall(모호한 코딩에 대해서 경고를 보내는 옵션)

PATH_DEST_BIN=../../bin     #변수 PATH_DEST_BIN = ../../bin 디렉토리 설정 
PATH_DEST_LIB=../../lib 	#변수 PATH_DEST_LIB = ../../lib 디렉토리 설정 
PATH_TEST=./test 			#변수 PATH_TEST = ./test 디렉토리 설정

D2VTEST=d2v_test  			#변수 D2VTEST = d2v_test 실행파일 
TARGET_LIB=libd2v.so  		#변수 TARGET_LIB = libd2v.so libd2v.so 공유 라이브러리

LIB_OBJS=d2v_naive.o gtt_naive.o  #변수 LIB_OBJS = d2v_naive.o gtt_naive.o 오브젝트 파일

all:$(D2VTEST) $(TARGET_LIB) 	    	#all은 d2v_test와 d2v_naive.o gtt_naive.o 에 의존성을 가진다.
	cp $(D2VTEST) $(PATH_DEST_BIN)  	#d2v_test파일을 ../../bin에 복사한다.
	mv $(D2VTEST) $(PATH_TEST)			#d2v_test파일을 ./test으로 옮긴다. 
	cp $(TARGET_LIB) $(PATH_DEST_LIB)   #libd2v.so파일을 ../../lib으로 복사한다.
	cp test.txt $(PATH_DEST_BIN)		#test.txt파일을 ../../bin으로 복사한다.

$(D2VTEST): test.o d2v_naive.o gtt_naive.o $(TARGET_LIB)			#d2v_test은 test.o d2v_naive.o gtt_naive.o libd2v.so 의 의존성을 가진다.
	$(CC) $(CFLAGS) -o $@ test.o d2v_naive.o gtt_naive.o -ld2v -L. -lindex-TEST -L$(PATH_DEST_LIB) -liconv   
	#gcc -Wall : 모호한 코딩에 대해서 경고를 보낸다.
	#-o $@ : d2v_test 실행 파일을 만든다.
	#test.o d2v_naive.o gtt_naive.o : d2v_test를 만들 때 test.o d2v_naive.o gtt_naive.o를 이용한다.
	#-ld2v : libd2v.a 정적 라이브러리를 포함시킨다.
	#-L. : 현재 디렉토리를 라이브러리 위치로 지정한다. 
	#-lindex-TEST : libindex-TEST.a 정적 라이브러리를 포함시킨다. 
	#-L../../lib : ../../lib 디렉토리를 라이브러리 위치로 지정한다.
	#-liconv : libiconv.a 정적 라이브러리를 포함시킨다.
$(TARGET_LIB): $(LIB_OBJS) $(PATH_DEST_LIB)							#libd2v.so 공유 라이브러리는 d2v_naive.o gtt_naive.o와 ../../lib에 의존성을 가진다. 
	$(CC) -shared -Wl -o $@ $(LIB_OBJS) 
	# gcc -shared -Wl -o $@ : libd2v.so 공유 라이브러리를 만든다.
	# d2v_naive.o gtt_naive.o 파일을 링크에 바로 전달 

d2v_naive.o : d2v_naive.c 											#d2v_naive.o은 d2v_naive.c에 의존성을 가진다. 
	$(CC) $(CFLAGS) -c d2v_naive.c -fPIC -o $@
	#gcc -Wall : 모호한 코딩에 대해서 경고를 보낸다.
	#-c d2v_naive.c : d2v_naive.c 파일을 컴파일 한다.
	#-fPIC : d2v_naive.o 파일을 동적라이브러리로 사용하도록 컴파일 하는 옵션

gtt_naive.o : ../gttlib/gtt_naive.c   								#gtt_naive.o은 ../gttlib/gtt_naive.c에 의존성을 가진다.
	$(CC) $(CFLAGS) -c ../gttlib/gtt_naive.c -fPIC -o $@ 
	#gcc -Wall : 모호한 코딩에 대해서 경고를 보낸다.
	#-c ../gttlib/gtt_naive.c : ../gttlib/gtt_naive.c파일을 컴파일한다.
	#-fPIC : d2v_naive.o 파일을 동적라이브러리로 사용하도록 컴파일 하는 옵션

clean :
	@rm -f *.o  							#모든 오브젝트 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다. 
	@rm -f $(D2VTEST) 						#d2v_test 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.
	@rm -f $(TARGET_LIB) 					#libd2v.so 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.
	@rm -f $(PATH_DEST_BIN)/$(D2VTEST) 		#../../bin/d2v_test 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.
	@rm -f $(PATH_DEST_LIB)/$(TARGET_LIB) 	#../../lib/libd2v.so 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.
	@rm -f $(PATH_DEST_BIN)/test.txt  		#../../bin/test.txt 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.
	@rm -f $(PATH_TEST)/$(D2VTEST) 			#./test/d2v_test 파일을 삭제한다. 커멘드 창에 작업 과정을 남기진 않는다.

#gcc -Wall -c d2v_naive.c
#  gcc -Wall -o test test.c d2v_naive.o gtt_naive.o
