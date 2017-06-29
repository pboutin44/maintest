BIN = shaders
CC = gcc
FLAGS = -DAPPLE -Wall -pedantic -mmacosx-version-min=10.5 -arch x86_64 -fmessage-length=0 -UGLFW_CDECL -fprofile-arcs -ftest-coverage
INC = -I ~/.brew/include -I/sw/include -I/usr/local/include
LIB_PATH = ~/.brew/lib
LOC_LIB = $(LIB_PATH)/libGLEW.a $(LIB_PATH)/libglfw.3.dylib@
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
SRC = main3.c gl_utils.c

all:
	${CC} ${FLAGS} ${FRAMEWORKS} -o ${BIN} ${SRC} ${INC} ${LOC_LIB}

