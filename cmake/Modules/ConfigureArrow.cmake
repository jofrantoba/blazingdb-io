#=============================================================================
# Copyright 2018 BlazingDB, Inc.
#     Copyright 2018 Percy Camilo Triveño Aucahuasi <percy@blazingdb.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#=============================================================================

if (NOT ARROW_VERSION)
    set(ARROW_VERSION "apache-arrow-0.11.1")
endif()

# Download and unpack arrow at configure time
configure_file(${CMAKE_SOURCE_DIR}/cmake/Templates/Arrow.CMakeLists.txt.cmake ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/thirdparty/arrow-download/CMakeLists.txt)

execute_process(
    COMMAND ${CMAKE_COMMAND} -F "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/thirdparty/arrow-download/
)

if(result)
    message(FATAL_ERROR "CMake step for Arrow failed: ${result}")
endif()

execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/thirdparty/arrow-download)

if(result)
    message(FATAL_ERROR "Build step for Arrow failed: ${result}")
endif()
 

set(ENV{ARROW_HOME} ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/thirdparty/arrow-install/)
