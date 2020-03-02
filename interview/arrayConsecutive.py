# statues = [6, 2, 3, 8]
# def makeArrayConsecutive2(statues):
#     if len(statues) == 1:
#         return 0
#     i = len(statues) - 1
#     sum = 0
#     while(i >= 0):
#         j = 0
#         while(j < i):
#             if statues[i] < statues[j]:
#                 temp = statues[j]
#                 statues[j] = statues[i]
#                 statues[i] = temp
#             j+=1
#         if (i < len(statues) - 1):
#             sum += statues[i + 1] - statues[i] - 1
#         i-=1
#     return sum

# print(makeArrayConsecutive2(statues))

""" For statues = [6, 2, 3, 8], the output should be
makeArrayConsecutive2(statues) = 3.

Ratiorg needs statues of sizes 4, 5 and 7. """
def makeArrayConsecutive2(statues):
    return max(statues) - min(statues) + 1 - len(statues)