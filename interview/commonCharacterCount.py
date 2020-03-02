def commonCharacterCount(s1, s2):
    return sum(min(s1.count(x), s2.count(x)) for x in set(s1))

s1 = "aabcc"
s2 = "adcaa"