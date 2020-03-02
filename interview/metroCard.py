def metroCard(lastNumberOfDays):
    month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31]
    output = []
    for i in range(1, 13):
        if lastNumberOfDays == month[i] and month[i + 1] not in output:
            output.append(month[i+1])
    return sorted(output)


print(metroCard(31))