class A:
    def __init__(self,x = 0) -> None:
        self.x = x
    
    def talk(self):
        if self.x < 14:
            return lambda i: self.__plus__(i)
        else:
            return lambda args: self.__do_nothing__(args)
    
    def __plus__(self,i):
        self.x += i
        print("i:",i,"x:",self.x)
        return self.talk()
    
    
    def __do_nothing__(self,args):
        return None

if __name__ == "__main__":
    a=A()
    res = a.talk()
    i = 0
    while(res):
        i+=1
        res = res(i)