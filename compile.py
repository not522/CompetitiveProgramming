import os

path = os.path.abspath(os.path.dirname(__file__))
library_path = os.getenv('LIB_PATH')

for root, dir, files in os.walk(path):
    if '.git' in root:
        continue
    for file in files:
        file_path = os.path.join(root, file)
        if '.cpp' in file:
            os.system('g++ -O0 -Wall -Wextra -Wno-char-subscripts -std=gnu++14 -fsyntax-only -I{0} {1}'.format(library_path, file_path))
            os.system('python {0}/import.py {1} > /dev/null'.format(path, file_path))
        if '.hpp' in file:
            find = False
            for raw_line in open(file_path):
                line = raw_line.strip()
                if line == '#pragma once':
                    find = True
            if not find:
                print file, ' : missing #pragma once'
