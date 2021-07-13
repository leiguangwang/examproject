#实验室考核第一题
n=input("请输入一个正整数")
n=int(n)
steps=[]
cnt=0
while n!=1:
    if n%2==0:
        cnt+=1
        n/=2
        steps.append('^')
    elif n==3:
        cnt+=1
        n-=1
        steps.append('-')
    else:
        if (n+1)%4==0:
            cnt+=1
            n+=1
            steps.append('+')
        else:
            cnt+=1
            n-=1
            steps.append('-')
print(cnt)
for step in steps:
    print(step,end='')