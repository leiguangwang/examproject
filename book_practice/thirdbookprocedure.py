#thirdbookprocedure
def show_message(a):
    print("\nThe following are the models")
    for model in a:
        print(model)
def send_message(a,b):
    while a:
        temp=a.pop()
        print(f"xing:{temp}")
        b.append(temp)
a=['zhao','qian','sun','li']
b=[]
show_message(a)
send_message(a[:],b)
show_message(a)