project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SRC storage.cpp stock.cpp date.cpp)


add_executable(index index.cpp ${SRC})
