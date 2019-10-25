cmake_minimum_required(VERSION 3.0)
project(demineur)

set(SRC
  src/demineur.c
)

set(HEADER
  include/demineur.h
)
add_executable(Demineur ${SRC} ${HEADERS})
