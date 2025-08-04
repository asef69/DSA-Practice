#inheritance
class gadget:
    def __init__(self,name,model,price,color):
        self.name=name
        self.model=model
        self.price=price
        self.color=color
    def __repr__(self):
        return f"My gadget is {self.name} and its price is {self.price}"
class phone(gadget):
    def __init__(self, name, model, price, color,camera):
        self.camera=camera
        super().__init__(name, model, price, color)
class iphone(phone):
    def __init__(self, name, model, price, color, camera,storage):
        self.storage=storage
        super().__init__(name, model, price, color, camera)                
class family(phone,iphone):
    def __init__(self, name, model, price, color, camera,storage):
        iphone().__init__(self,storage)
        super().__init__(name, model, price, color, camera)        