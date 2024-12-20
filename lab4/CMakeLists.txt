cmake_minimum_required(VERSION 3.10)

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

# Укажите имя вашего проекта
project(BalagurFate4)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 20)

# Укажите директории с заголовочными файлами
include_directories(include)

# Создайте исполняемый файл
add_executable(BalagurFate3 ${SOURCES} main.cpp)

# Добавьте тесты
enable_testing()
add_executable(lab4_tests tests/test_lab4.cpp ${SOURCES})
target_link_libraries(lab4_tests gtest gtest_main pthread)
add_test(NAME lab4 COMMAND lab4_tests)
