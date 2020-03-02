import time
start_time = time.time()

matrix = [[0,1,1,2], 
        [0,5,0,0], 
        [2,0,3,3]]
        
def matrixElementsSum(matrix):
    epod = 0
    bathSize = len(matrix[0])

    sum = 0
    colHaunted = []
    for i in range(len(matrix) * len(matrix[0])):
        costRoom = matrix[epod][i%bathSize]
        if i % bathSize == 0 and i > 0:
            epod += 1
        if costRoom == 0:
            colHaunted.append(i%bathSize)
        if i%bathSize not in colHaunted:
            sum += costRoom

    return sum

print(matrixElementsSum(matrix))

print("Runtime: %s ms" % ((time.time() - start_time)*1000))