
def increasing(arr):
    if len(arr) == 1:
        return True
    lef = 0
    rig = len(arr) - 1
    while(lef <= rig):
        if arr[lef+1] <= arr[lef] or arr[rig] <= arr[rig-1]:
            return False
        lef+=1
        rig-=1
    return True
def almostIncreasingSequence(sequence):
    i = 0
    lenSequence = len(sequence)
    while i < lenSequence:
        element = sequence[i]
        del sequence[i]
        # code here
        if increasing(sequence) == True:
            return True
        sequence.insert(i, element)
        i+=1
    return False

arr = [3, 5, 67, 98, 3]
rs = almostIncreasingSequence(arr)
print(rs)
