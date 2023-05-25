#!/bin/bash

# 格式化
# clang-format -i `find include/ -type f -name *.hpp`
clang-format -i `find CodeTop/ -type f -name *.cc`

# 统计代码行数
cloc --git `git branch --show-current`
