from random import choice

class RandomWalk:

    def __init__(self,num_points=2000):
        """初始化随机漫步的属性"""
        self.num_points=num_points

        #所有随机漫步都始于(0,0)
        self.x_value=[0]
        self.y_value=[0]

    def fill_walk(self):
        """计算随机漫步包含的所有点"""
        while len(self.x_value)<self.num_points:

            #决定前进方向以及沿这个方向前进的距离
            x_direction=choice([1,-1])
            X_distance=choice([0,1,2,3,4])
            x_step=x_direction*X_distance

            y_direction=choice([1,-1])
            y_distance=choice([0,1,2,3,4])
            y_step=y_direction*y_distance

            #拒绝原地踏步
            if x_step ==0 and y_step ==0:
                continue

            #计算下一个点的x,y值
            x=self.x_value[-1]+x_step
            y=self.y_value[-1]+y_step

            self.x_value.append(x)
            self.y_value.append(y)