@ECHO OFF

::  Compiler flags
SET CC=cl
SET STD_C89=/Za /Tc

%CC% /EHsc %STD_C89% binary-search-tree.c queue.c tester.c