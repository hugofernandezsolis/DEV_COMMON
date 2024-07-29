###############################################################################
###                      INTEGRATE EXTERNAL LIBRARIES                       ###
###############################################################################
## Integrate GTest for unit testing.
###############################################################################

include(FetchContent)

# Download and configure Google Test as part of the build
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main  # Specify the version you need
)

FetchContent_MakeAvailable(googletest)

find_package(
  GTest
    REQUIRED
)

find_package(
  Boost
    REQUIRED
)


###############################################################################
###                               COMPONENTS                                ###
###############################################################################
## Include project components and subdirectories.
###############################################################################

# Get a list of subdirectories in the current directory
set (
  COMPONENTS
    Logger
)

# Iterate over each subdirectory
foreach(COMPONENT ${COMPONENTS})
  # Set the name of the component library.
  set (COMPONENT_LIB ${COMPONENT})
  # Enter into the component
  add_subdirectory(${COMPONENT})
  # Link the new lib to the executable
  target_link_libraries (
    ${PROJECT_NAME}
      ${COMPONENT_LIB}
  )
endforeach()