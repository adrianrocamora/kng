try:
    print("In try case")
    raise IndexError("This is an index error")
except IndexError as e:
    print("In except case")
    pass
else:
    print("In else case")
    pass
finally:
    print("In finally case")
