#实验室考核第二题
x,y,z=eval(input("请输入三个整数:"))
nums=[1,1,1,1,1,1]
sizes=[]
if z-y>=y-x:
    print(-1)
else:
    nums[0]=2*(2*y-x-z)
    if nums[0]>y-x:
        print(-1)
    else:
        nums[2]=y-x-nums[0]
        nums[4]=int(nums[0]/2)
        for num in nums:
            print(num,end=' ')