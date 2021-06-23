cmake_minimum_required (VERSION 3.11)
project(salee_qspi)

# enable generation of compile_commands.json, helpful for IDEs to locate include files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# custom CMake Modules are located in the cmake directory.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalAnalyzerSDK)

set(SOURCES 
source/QSPIAnalyzerCommands.cpp 
source/QSPIAnalyzer.cpp 
source/QSPIAnalyzerResults.cpp 
source/QSPIAnalyzerSettings.cpp  
source/QSPISimulationDataGenerator.cpp
source/QSPIAnalyzerCommands.h  
source/QSPIAnalyzer.h   
source/QSPIAnalyzerResults.h  
source/QSPIAnalyzerSettings.h 
source/QSPISimulationDataGenerator.h
)

add_analyzer_plugin(salee_qspi SOURCES ${SOURCES})

