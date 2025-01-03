INCS = -Iext/glfw-static/include/ -Iext/glad/include/ -Isrc/
LIBS = -Lext/glfw-static/

EXEC = main

all: main_goal

main_goal: main.o window.o glad.o shader_program.o shader.o
	g++ -o $(EXEC) main.o window.o shader_program.o shader.o glad.o $(LIBS) -lglfw3

main.o: src/main.cpp 
	g++ -c src/main.cpp $(INCS)

window.o: src/window.cpp
	g++ -c src/window.cpp $(INCS)

shader_program.o: src/shader_program.cpp
	g++ -c src/shader_program.cpp $(INCS)

shader.o: src/shader.cpp
	g++ -c src/shader.cpp $(INCS)

glad.o: ext/glad/src/glad.c
	g++ -c ext/glad/src/glad.c -Iext/glad/include/

clean:
	rm *.o $(EXEC)
