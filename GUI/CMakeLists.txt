cmake_minimum_required(VERSION 3.20)
project(GUI C)

set(CMAKE_C_STANDARD 11)
set(SDL2_INCLUDE_DIR SDL2-devel-2.0.20-VC/SDL2-2.0.20/include)
set(SDL2_LIBRARY_DIR SDL2-devel-2.0.20-VC/SDL2-2.0.20/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY_DIR})

link_libraries(ws2_32 wsock32)

add_executable(GUI main.c Window/Game/Game.c Window/Game/GameConstantes.h cJSON/cJSON.c cJSON/cJSON.h Clientes/Cliente.c Clientes/Cliente.h Window/MainWindow/MainWindow.c Window/MainWindow/MainWindow.h Window/MainWindow/MainWindowConstantes.h Window/SelectionMenu/SelectionMenu.c Window/SelectionMenu/SelectionMenu.h Window/SelectionMenu/SelectionMenuConstates.h LinkedList/LinkedList.c LinkedList/LinkedList.h)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
