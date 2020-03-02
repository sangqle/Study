print("Hello")
a = [2, 4, 3, 5, 1]
def firstDup(a):
    for i in range(len(a)):
        if a[abs(a[i])-1] < 0:
            return abs(a[i])
        else:
            a[abs(a[i]) - 1] = - a[abs(a[i])-1]
    return -1

print(firstDup(a))