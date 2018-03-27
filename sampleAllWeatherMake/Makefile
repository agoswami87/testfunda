# Simplified makefile of vRSC
#
CC = gcc
CXX = g++
CFLAGS = -g -fPIC
CPPFLAGS =
INCPATH=$(shell find . -path "*/include")
CINCPATH=$(foreach inPath, $(INCPATH), -I${inPath})
#CINCPATH=$(INCPATH:%=-I%) #both works
LIBPATH = -lpthread

SRCS=$(shell find . -name '*.c')
OBJS= $(SRCS:.c=.o) #same as foreach as mentioned above
TARGET=vRSC

.PHONY:all
	all:${TARGET}

${TARGET} : ${OBJS} #can mention if you like to compile some other targets
	@echo "All SRCs=" ${SRCS}
	@echo "All OBJS=" ${OBJS}
	@echo "All INC=" ${CINCPATH}
	${CC} ${CINCPATH} $^ ${LIBPATH} -o $@ #add LIBPATH and add CINCPATH 

%.o : %.c
	${CC} ${CFLAGS} ${CINCPATH} -c $< -o $@

clean:
	rm -rf ${OBJS} ${TARGET}

