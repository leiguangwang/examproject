#with open("D:\\f.txt",'a+') as file_object:
#    contents=file_object.read()
#    file_object.write("\n63589742")
#with open("D:\\f.txt",'w') as file_object:
#    for line in file_object:
#        print(line.rstrip())
#    contents=file_object.read()
#print(contents)
import json
#contents="我是一个无比热爱自己祖国的中国人"
numbers=[2,3,5,7,11,13]
filename='C:\\Users\\HP\\Desktop\\homework\\numbers.json'
try:
    with open(filename,'w') as f:
        json.dump(numbers,f)
except FileNotFoundError:
    print("Sorry,this file doesn't exist")
#else:
#    words=jieba.lcut(contents)

#a=len(title.split())
#print(words)
#words=jieba.lcut(contents)
#print(words)