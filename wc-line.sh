#!/bin/bash
find . "(" -name "*.sh" -or  -name "*.cpp" -or -name "*.h" -or -name "*.java" -or -name "*.c" -or -name "*.py" -or -name "*.md" ")" -print | xargs wc -l

