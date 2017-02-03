import argparse
import os
import pyperclip

library_path = os.getenv('LIB_PATH').split(':')[-1]

def getHeader(file, headers):
    output = ''
    for raw_line in open(file):
        line = raw_line.strip()
        if line == '#pragma once':
            continue
        if line == '' or line[0] != '#' or line[-1] != '"':
            output += raw_line
            continue
        header = line.split('"')[1]
        if header not in headers:
            headers.append(header)
            output += getHeader(library_path + header, headers)
    return output

parser = argparse.ArgumentParser(description='include local library')
parser.add_argument('file', help='source file')
args = parser.parse_args()

headers = []
pyperclip.copy(getHeader(args.file, headers))
