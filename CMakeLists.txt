cmake_minimum_required(VERSION 3.10)
project(FlatDrawer C)

set(CMAKE_C_STANDARD 11)

add_executable(FlatDrawer main.c app.c app.h screen.h screen.c Shapes/shape.c Shapes/shape.h Shapes/point.c Shapes/point.h Shapes/line.c Shapes/line.h Shapes/rect.c Shapes/rect.h Shapes/square.c Shapes/square.h Shapes/circle.c Shapes/circle.h Shapes/polygon.c Shapes/polygon.h layer.c layer.h utils.c utils.h commands.c commands.h)
