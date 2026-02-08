#!/usr/bin/python3
import sys

def decode_l(c: int) -> str:
    if c + 13 <= ord('z'):
        return (chr(c + 13))
    return (chr(c + 12 + ord('a') - ord('z')))

def decode_u(c: int) -> str:
    if c + 13 <= ord('Z'):
        return (chr(c + 13))
    return (chr(c + 12 + ord('A') - ord('Z')))

def decode_rot13(s: str) -> str:
    res = []
    for c in s:
        ch = ord(c)
        if ord('a') <= ch <= ord('z'):
            res.append(decode_l(ch))
        elif ord('A') <= ch <= ord('Z'):
            res.append(decode_u(ch))
        else:
            res.append(c)
    return ''.join(res)

if len(sys.argv) < 2:
    print("./decode key")
    sys.exit(1)

with open(sys.argv[1], 'r', encoding='utf-8') as file:
    code = file.read()

print(decode_rot13(code))
