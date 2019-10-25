cmake_minimum_required(VERSION 3.0)
project(demineur)

set(SRCS
  src/main.c
  src/demineur.c
)

set(HEADER
  include/demineur.h
)
set(EXECUTABLE_OUTPUT_PATH "bin")
add_executable(Demineur ${SRCS} ${HEADERS})
