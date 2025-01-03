INCS = -Iext/glfw-static/include/ -Iext/glad/include/ -Isrc/
LIBS = -Lext/glfw-static/

OBJS = main.o window.o glad.o shader_program.o shader.o vertex_array.o vertex_buffer.o

EXEC = main

all: main_goal

main_goal: $(OBJS)
	g++ -o $(EXEC) $(OBJS) $(LIBS) -lglfw3

main.o: src/main.cpp 
	g++ -c src/main.cpp $(INCS)

window.o: src/window.cpp
	g++ -c src/window.cpp $(INCS)

shader_program.o: src/shader_program.cpp
	g++ -c src/shader_program.cpp $(INCS)

shader.o: src/shader.cpp
	g++ -c src/shader.cpp $(INCS)

vertex_array.o: src/vertex_array.cpp
	g++ -c src/vertex_array.cpp $(INCS)

vertex_buffer.o: src/vertex_buffer.cpp
	g++ -c src/vertex_buffer.cpp $(INCS)

glad.o: ext/glad/src/glad.c
	g++ -c ext/glad/src/glad.c -Iext/glad/include/

clean:
	rm *.o $(EXEC)
