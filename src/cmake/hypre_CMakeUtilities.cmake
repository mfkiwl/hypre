# A function to add each executable in the list to the build with the
# correct flags, includes, and linkage.
function(add_hypre_executables EXE_SRCS)
  # Add one executable per cpp file
  foreach(SRC_FILE IN LISTS ${EXE_SRCS})
    get_filename_component(SRC_FILENAME ${SRC_FILE} NAME)

    string(REPLACE ".c" "" EXE_NAME ${SRC_FILENAME})
    # Actually add the exe
    add_executable(${EXE_NAME} ${SRC_FILE})
    # Link libraries
    set (HYPRE_LIBS "HYPRE") 

    # Link libraries for Unix systems
    if (UNIX)
      list (APPEND HYPRE_LIBS m)
    endif (UNIX)
  
    # Append the additional libraries and options
    target_link_libraries(${EXE_NAME} PRIVATE "${HYPRE_LIBS}") 
  endforeach(SRC_FILE)
endfunction()
