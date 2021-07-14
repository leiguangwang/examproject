import os
from sys import path
import fire

def StrOfSize(file):

    size=os.path.getsize(file)
    def strofsize(integer, remainder, level):
        if integer >= 1024:
            remainder = integer % 1024 /1024
            integer //= 1024
            level += 1
            return strofsize(integer, remainder, level)
        else:
            return integer, remainder, level

    units = ['', 'KB', 'MB', 'GB', 'TB', 'PB']
    integer, remainder, level = strofsize(size, 0, 0)
    if level+1 > len(units):
        level = -1
    if integer>=10:
        return ('{} {}'.format(integer,units[level]))
    else:
        return ( '{}{:>.1f} {}'.format(integer, remainder, units[level]) )

categories={}

def filesort(path):
    files=os.listdir(path)
    for f in files:
        if len(f.split('.'))==1:   #判断是否为空扩展名
            categories['.']=[].append(f)
        
    folder_name='.'+f.split('.')[-1]
    if folder_name not in categories.keys():
        categories[folder_name]=[]
        categories[folder_name].append(f)

    else:
        categories[folder_name].append(f)
        categories[folder_name].sort()

    for category in categories.keys():
        print(category)
        try:
            for x in categories[category]:
                print(f"{x} {StrOfSize(path+x)}")
        except:
            pass

if __name__=='__main__':
    fire.Fire(filesort)