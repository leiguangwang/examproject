#实验室第三题
import zipfile

choice=eval(input("打包文件请输入1，解包文件请输入2:"))
if choice==1:
    file_path=input("请输入新文件的路径信息:")
    file=zipfile.ZipFile(file_path,'w')
    while True:
        filename=input("请输需要打包文件的路径信息(停止请输入quit):")
        if filename=='quit':
            break
        else:
            file.write(filename)
    file.close()
    print(file.namelist())
elif choice==2:
    file_path2=input("请输入拆分文件的路径信息:")
    file2=zipfile.ZipFile(file_path2)
    _path=input("请输入文件拆分后存入的路径信息")
    file2.extractall(path=_path)
    file2.close()