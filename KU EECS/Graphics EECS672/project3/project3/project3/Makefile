CPP = g++
INC = -I../cryphutil -I../fontutil -I../glslutil -I../mvcutil
C_FLAGS = -fPIC -g -c -DGL_GLEXT_PROTOTYPES $(INC)

LINK = g++ -fPIC -g
LOCAL_UTIL_LIBRARIES = ../lib/libcryph.so ../lib/libfont.so ../lib/libglsl.so ../lib/libmvc.so
OGL_LIBRARIES = -lglfw -lGLU -lGL

OBJS = project2.o ModelViewWithPhongLighting.o Block.o person.o ModelView_Additions.o drops.o island.o ControllerSub.o test.o sword.o ObjReader.o

project2: $(OBJS) $(LOCAL_UTIL_LIBRARIES)
	$(LINK) -o project2 $(OBJS) $(LOCAL_UTIL_LIBRARIES) $(OGL_LIBRARIES)

../lib/libcryph.so: ../cryphutil/AffVector.h ../cryphutil/AffVector.c++ ../cryphutil/AffPoint.h ../cryphutil/AffPoint.c++
	(cd ../cryphutil; make)

../lib/libfont.so: ../fontutil/CFont.h ../fontutil/CFont.c++ ../fontutil/CGLString.h ../fontutil/CGLString.c++
	(cd ../fontutil; make)

../lib/libglsl.so: ../glslutil/ShaderIF.h ../glslutil/ShaderIF.c++
	(cd ../glslutil; make)

../lib/libmvc.so: ../mvcutil/Controller.h ../mvcutil/Controller.c++ ../mvcutil/ModelView.h ../mvcutil/ModelView.c++
	(cd ../mvcutil; make)

project2.o: project2.c++
	$(CPP) $(C_FLAGS) project2.c++
ModelView_Additions.o: ModelView_Additions.c++
	$(CPP) $(C_FLAGS) ModelView_Additions.c++
ModelViewWithPhongLighting.o: ModelViewWithPhongLighting.h ModelViewWithPhongLighting.c++
	$(CPP) $(C_FLAGS) ModelViewWithPhongLighting.c++
Block.o: Block.h Block.c++
	$(CPP) $(C_FLAGS) Block.c++
person.o: person.h person.c++
	$(CPP) $(C_FLAGS) person.c++
test.o: test.h test.c++
	$(CPP) $(C_FLAGS) test.c++
drops.o: drops.h drops.c++
		$(CPP) $(C_FLAGS) drops.c++
island.o: island.h island.c++
		$(CPP) $(C_FLAGS) island.c++
ControllerSub.o: ControllerSub.h ControllerSub.c++
				$(CPP) $(C_FLAGS) ControllerSub.c++
sword.o: sword.h sword.c++
				$(CPP) $(C_FLAGS) sword.c++
ObjReader.o: ObjReader.h ObjReader.c++
				$(CPP) $(C_FLAGS) ObjReader.c++
