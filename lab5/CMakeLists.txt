cmake_minimum_required(VERSION 3.10)
project(lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
# Убираем специфическую опцию, заменяем на более общую
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключение библиотек
include_directories(include)

# Создание основной библиотеки как INTERFACE
add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)
target_include_directories(${CMAKE_PROJECT_NAME}_lib INTERFACE include)

# Создание исполняемого файла основного приложения
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Добавление тестов
enable_testing()

add_executable(lab5_tests tests/test_lab5.cpp)
target_link_libraries(lab5_tests PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Регистрация тестов
add_test(NAME MyProjectTests COMMAND lab5_tests)
