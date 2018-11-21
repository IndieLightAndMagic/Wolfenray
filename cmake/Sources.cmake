function(SOURCES_INCLUDE)
    include_directories(${CMAKE_SOURCE_DIR}/src)
    include_directories(${CMAKE_SOURCE_DIR}/src/json/include)
endfunction()

function(SOURCES_TO_COMPILE PROJECT_NAME)
    add_executable(${PROJECT_NAME}

            ${CMAKE_SOURCE_DIR}/src/main.cpp
            ${CMAKE_SOURCE_DIR}/src/game.cpp
            ${CMAKE_SOURCE_DIR}/src/keyboard.cpp

            ${CMAKE_SOURCE_DIR}/src/timermanager.cpp
            ${CMAKE_SOURCE_DIR}/src/timermanager.h
            ${CMAKE_SOURCE_DIR}/src/timer.cpp
            ${CMAKE_SOURCE_DIR}/src/timer.h

            ${CMAKE_SOURCE_DIR}/src/Sprite.cpp


            )
endfunction() 


function(GTECH_HEADER_AND_LINK PROJECT_NAME)

    target_include_directories(   ${ProjectName} PUBLIC 
        ${GTECH_DIR}/3rd/include/)
    
    target_link_libraries(        ${ProjectName} 
        ${GTECH_DIR}/3rd/lib/libsdlwrapper.a)

endfunction()


function(LINK_STANDARD_LIBRARIES PROJECT_NAME)
    target_link_libraries(${ProjectName} "-liconv" "-lm")
endfunction()