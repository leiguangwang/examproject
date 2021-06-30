#learnpractice
cities={
    'beijing':{
        'country':'China',
        'population':5000,
        'fact':'old'},
    'london':{
        'country':'England',
        'population':3000,
        'fact':'wealthy'},
    'New York':{
        'country':'Amercia',
        'population':4000,
        'fact':'mass'},  
        }
for city,details in cities.items():
    print(f"city:{city}")
    print(f"\tcountry:{details['country']}")
    print(f"\tpopulation:{details['population']}")
    print(f"\tfact:{details['fact']}")