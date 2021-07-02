#forthbookprocedure
class Car:
    """一次模拟汽车的简单尝试"""
    def __init__(self,make,model,year):
        """初始化描述汽车的性质"""
        self.make=make
        self.model=model
        self.year=year
    def get_descriptive_name(self):
        """返回整洁的描述信息"""
        long_name=f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        """打印一条指出汽车里程的消息"""
        print(f"this car has {self.read_odometer} miles on it.")
    def update_odometer(self,mileage):
        """将里程表设置为指定的值"""
        self.read_odometer=mileage
class Battery:
    def __init__(self,battery_size=75):
        """初始化电瓶的性质"""
        self.battery_size=battery_size
    def describe_battery(self):
        print(f"this car's battery size is {self.battery_size}")
class Electroniccar(Car):
    """电动车的独特之处"""
    def __init__(self,make,model,year):
        """初始化父类的属性
        再初始化子类的属性"""
        super().__init__(make,model,year)
        self.battery=Battery()
my_tesla=Electroniccar('tesla' ,'madel s' ,2019)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery