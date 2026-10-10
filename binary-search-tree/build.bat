@ECHO OFF

::  Compiler flags
SET CC=cl
SET LNK=link
SET OPTIONS=/c
SET STD_C89=/Za /Tc
SET WARNING_FLAGS=/W4 /WX

::  Variables
SET EXECUTABLE=Binary Search Tree.exe

ECHO Cleaning old build artifacts...
::  Clean build artifacts
IF EXIST *.obj DEL *.obj
IF EXIST "%EXECUTABLE%" DEL "%EXECUTABLE%"
ECHO Cleanup complete.

::  Compile and build object files
%CC% %WARNING_FLAGS% %OPTIONS% %STD_C89% *.c

::  Compilation failed, exit and set exit code to 1
IF ERRORLEVEL 1 (
    ECHO Compilation Failed!
    EXIT /B 1
)

::  Link object files and create executable
%LNK% *.obj /OUT:"%EXECUTABLE%"

::  Linking failed, exit and set exit code to 1
IF ERRORLEVEL 1 (
    ECHO Failed to create %EXECUTABLE%!
    EXIT /B 1
)