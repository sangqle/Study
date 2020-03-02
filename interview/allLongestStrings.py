str = ["aba", 
 "aa", 
 "ad", 
 "vcd", 
 "aba"]
def allLongestStrings(str):
    longStr = len(str[0])
    for i in range(1, len(str)):
        if len(str[i]) > longStr:
            longStr = len(str[i])
    
    allLongStrs = []
    for i in range(len(str)):
        if len(str[i]) == longStr:
            allLongStrs.append(str[i])
    print(allLongStrs)
allLongestStrings(str)