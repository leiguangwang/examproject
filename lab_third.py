#实验室第三题
import os

filelist=[]
filenames=[]
choice=eval(input("打包文件请输入1，解包文件请输入2:"))
if choice==1:
    newfile=input("请输出新文件的路径及文件名(输入QUIT结束输入：")
    Newfile=open(newfile,'w')
    while True:
        filepath=input("请输入需要合并的文件路径：")
        if filepath=="QUIT":
            break
        filename=input("请输入文件名：")
        if filepath=="QUIT":
            break
        filelist.append(filepath+filename)
        filenames.append(filename)
        Newfile.write(bin(len(filelist))+'\n')
    for file in filenames:
        Newfile.write(bin(len(filename))+' ')
    for file in filelist:
        Newfile.write(bin(os.path.getsize(file))+'\n\n')
    for file in filelist:
        x=open(file,encoding='utf-8')
        Newfile.write(x.read())