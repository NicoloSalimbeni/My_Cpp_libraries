cmake_minimum_required(VERSION 3.27.0) # my current version

project(myLibs)

# Set the source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

# Get a list of all the .cpp files in the src directory
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# Create a list of library names by stripping the extension from each .cpp file
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE_NAME ${SRC_FILE} NAME_WE)
    list(APPEND LIB_NAMES ${FILE_NAME})
endforeach()

# Iterate over the list of library names
foreach(LIB_NAME ${LIB_NAMES})
    # Create a library for each .cpp file and add it to the lib directory
    add_library(${LIB_NAME} STATIC ${SRC_DIR}/${LIB_NAME}.cpp)

    # Link any necessary dependencies here, e.g., target_link_libraries(${LIB_NAME} YourOtherLibrary)

    # Set the include directories for the library
    target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_DIR})
    
    # Specify where to save the generated library files
    set_target_properties(${LIB_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR}
    )
endforeach()