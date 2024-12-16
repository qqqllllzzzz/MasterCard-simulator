# CMakeLists.txt: проект CMake для BankSimulator; включите исходный код и определения.

cmake_minimum_required(VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("BankSimulator")

# Добавьте источник в исполняемый файл этого проекта.
add_executable(BankSimulator 
    "BankSimulator.cpp" 
    "BankSimulator.h" 
    "interface.hpp" 
    "interface/define.h"
    "ForCompile/resource.rc"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BankSimulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.