@ECHO OFF

::  Compiler flags
SET CC=cl
SET STD_C89=/Za /Tc
SET WARNING_FLAGS=/W4 /WX

%CC% %WARNING_FLAGS% %STD_C89% binary-search-tree.c queue.c tester.c