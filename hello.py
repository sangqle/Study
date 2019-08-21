print("Hello python")
# name=input()
# print('hello', name)

# a = 5
# b = 10
# if a > b:
  # c = a - b
# else:
  # c = a + b
  # print(c)
  
# while
# c = 0
# d = 10
# while c < d:
  # print(c)
  # c+=1
  
def arrAppend(arrList, element):
  arrList.append(element)
  return arrList
	
cats = [1, 3, 3, 4, 5, 6, 7, 2]

newCats = arrAppend(cats, 3)

dict = {'name': 'sang'}
print(dict['name'])
dict['age'] = 23

a = dict.items()
print(a)
























