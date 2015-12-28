CPP = g++
C_FLAGS = -fPIC -g -c -DGL_GLEXT_PROTOTYPES

LINK = g++ -fPIC -g
OGL_LIBRARIES = -lglfw -lGLU -lGL

OBJS = hello.o ShaderIF.o

hello: $(OBJS)
	$(LINK) -o hello $(OBJS) $(OGL_LIBRARIES)

hello.o: hello.c++
	$(CPP) $(C_FLAGS) hello.c++
ShaderIF.o: ShaderIF.h ShaderIF.c++
	$(CPP) $(C_FLAGS) ShaderIF.c++
