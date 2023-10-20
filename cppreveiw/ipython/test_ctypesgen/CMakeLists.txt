cmake_minimum_required(VERSION 3.12)

project(test)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src/ SRCLIST)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

add_library(app SHARED ${SRCLIST})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

add_executable(testapp main.c)

target_link_libraries(testapp  app)

add_custom_target(ctypesgenapp ALL
    COMMAND ctypesgen 
    --output-language=py32
    -I ${CMAKE_CURRENT_SOURCE_DIR}/inc/
    -L ${LIBRARY_OUTPUT_PATH} -llibapp.so
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/app_c.h -o ${LIBRARY_OUTPUT_PATH}/app.py
)


# add_custom_target(copyto ALL
#     COMMAND cp  ${CMAKE_CURRENT_SOURCE_DIR}/build/lib/app.py ${CMAKE_CURRENT_SOURCE_DIR}
#     DEPENDS ctypesgenapp
# )