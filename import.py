import argparse
import os

library_path = os.getenv('LIBRARY_PATH').split(':')[-1]

def getHeader(file, headers):
    for raw_line in open(file):
        line = raw_line.strip()
        if line == '#pragma once':
            continue
        if line == '' or line[0] != '#' or line[-1] != '"':
            print raw_line,
            continue
        header = line.split('"')[1]
        if header not in headers:
            headers.append(header)
            getHeader(library_path + header, headers)

parser = argparse.ArgumentParser(description='include local library')
parser.add_argument('file', help='source file')
args = parser.parse_args()

headers = []
getHeader(args.file, headers)
