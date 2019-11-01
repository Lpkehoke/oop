project(Lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SRC storage.cpp stock.cpp date.cpp base_storage.cpp storage1.cpp storage2.cpp)

add_executable(index index.cpp ${SRC})
