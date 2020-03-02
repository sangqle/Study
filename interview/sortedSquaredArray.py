print("hello")
# Input = [-6, -4, 1, 2, 3, 5]
input = [-6, -4, 1, 2, 3, 5]
lef = 0
rig = len(input) - 1 
output = []
while(lef <= rig):
    if(abs(input[lef]) > abs(input[rig])):
        output.append(input[lef]**2)
        lef+=1
    else:
        output.append(input[rig]**2)
        rig-=1

print(input)
print(output)