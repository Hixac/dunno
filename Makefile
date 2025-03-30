INCS := -Iext/glfw-static/include/ -Iext/glad/include/ -Isrc/ -Isrc/ -Iext/stb/ -Iext/imgui/
DIR_LIBS := -Lext/glfw-static/ -Lext/glm/
LIBS := -lglfw3 -lglm

SOURCES := $(shell find src/ -name '*.cpp')
HEADERS := $(shell find src/ -name '*.hpp')
OBJS := $(notdir $(SOURCES:%.cpp=%.o))
OBJS += glad.o imgui.o imgui_demo.o imgui_draw.o imgui_impl_glfw.o imgui_tables.o imgui_widgets.o imgui_impl_opengl3.o

CXX := g++
FLAGS := -std=c++23 -Wall -Wpedantic

EXEC := main

.PHONY: all debug main_goal clean

all: main_goal

main_goal: $(OBJS)
	$(CXX) $(FLAGS) -o $(EXEC) $(OBJS) $(DIR_LIBS) $(LIBS)

%.o: src/%.cpp
	$(CXX) $(FLAGS) -c $^ $(INCS)

%.o: src/engine/%.cpp
	$(CXX) $(FLAGS) -c $^ $(INCS)

%.o: src/transforms/%.cpp
	$(CXX) $(FLAGS) -c $^ $(INCS)

%.o: src/objects/%.cpp
	$(CXX) $(FLAGS) -c $^ $(INCS)

%.o: ext/imgui/%.cpp
	$(CXX) $(FLAGS) -c $^ $(INCS)

glad.o: ext/glad/src/glad.c
	gcc -c $^ -Iext/glad/include/

clean:
	rm -f *.o $(EXEC)

debug: FLAGS += -g
debug: clean main_goal
	gdb $(EXEC)
