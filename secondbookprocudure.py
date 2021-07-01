#secondbookprocudure
responses={}
polling_avtive=True
while polling_avtive:
    name=input("\nWhat is your name? ")
    response=input("Which mountain would you like to climb someday?")
    responses[name]=response
    repeat=input("Would you like to let another person respond?(yes/no)")
    if repeat=='no':
        polling_avtive=False

for name,response in responses.items():    
    print(f"{name}would like to climb {response}")
