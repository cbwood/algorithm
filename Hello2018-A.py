# coding=utf-8

a = int(input())
b = int(input())
print(b if a >= 32 else b % (1 << a))
