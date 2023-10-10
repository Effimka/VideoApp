@echo off

IF EXIST "Build" (
    echo directory exists
) ELSE (
    echo Not EXIST 
    mkdir Build
    echo directory created
)

cd Build
cmake ..
cmake --build .