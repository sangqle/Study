def almostIncreasingSequence(sequence):
    count = 0
    for i in range(len(sequence) - 1):
        if sequence[i] >= sequence[i+1]:
            count += 1
        
    return count < 2

arr = [1, 3, 2, 1]
rs = almostIncreasingSequence(arr)
print(rs)