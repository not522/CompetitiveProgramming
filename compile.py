import os

for root, dir, files in os.walk('/home/not/git/procon/'):
    if '.git' in root:
        continue
    for file in files:
        filepath = os.path.join(root, file)
        if '.cpp' in file:
            os.system('g++ -O0 -Wall -Wextra -Wno-char-subscripts -std=c++11 -fsyntax-only -I/home/not/git/procon/lib ' + filepath)
            os.system('/home/not/git/procon/import.sh ' + filepath)
        if '.hpp' in file:
            find = False
            for raw_line in open(filepath):
                line = raw_line.strip()
                if line == '#pragma once':
                    find = True
            if not find:
                print file, ' : missing #pragma once'
