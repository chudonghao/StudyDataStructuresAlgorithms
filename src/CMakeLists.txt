file(GLOB SRCS *.cpp)

foreach (SRC ${SRCS})
    message(${SRC})
    get_filename_component(EXE_NAME ${SRC} NAME_WE)
    add_executable(${EXE_NAME} ${SRC})
endforeach ()