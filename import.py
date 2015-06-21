import argparse

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
            getHeader('/home/not/git/procon/lib/' + header, headers)

parser = argparse.ArgumentParser(description='include local library')
parser.add_argument('file', help='source file')
args = parser.parse_args()

headers = []
getHeader(args.file, headers)
