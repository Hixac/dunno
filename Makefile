# compiler
CXX := g++
CC := gcc
CXXFLAGS := -std=c++23 -Wall -Wpedantic \
			-Iext/glfw-static/include/ -Iext/glad/include/ -Iext/ -Isrc/ -Iext/stb/ -Iext/imgui/
DEPFLAGS := 

# deps
EXEC := main

EXT_DIR := ext
SRC_DIR := src

LDFLAGS := -Lext/glfw-static/ -Lext/glm/
LIBS := -lglfw3 -lglm

SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
HEADERS := $(shell find $(SRC_DIR) -name '*.hpp')
OBJS := $(addsuffix .o,$(basename $(notdir $(SOURCES)))) glad.o \
		imgui.o imgui_demo.o \
		imgui_draw.o imgui_tables.o \
		imgui_widgets.o imgui_impl_glfw.o \
		imgui_impl_opengl3.o
DEPS := $(patsubst %.cpp,%.d,$(SOURCES))

VPATH = $(shell find $(SRC_DIR) -maxdepth 1 -type d) $(EXT_DIR)/imgui $(EXT_DIR)/glm

# rules
.PHONY: all debug clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) $(LIBS)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

glad.o: $(EXT_DIR)/glad/src/glad.c
	$(CC) -c $^ -Iext/glad/include/

clean:
	rm -f *.o $(EXEC)
