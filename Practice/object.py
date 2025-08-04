class Phone:
    price=19000
    color='blue'
    brand='samsung'
    def __init__(self,owner,brand,price):
        self.owner=owner
        self.brand=brand
        self.price=price        
    def call(self):
        print("calling a person")
    def sms(self,phone,SMS):
        text=f"Text from {phone} to message {SMS}"
        return text    
my_phone=Phone('Asef','xiaomi',26000)
print(my_phone.sms(+8801912094002,"I love you MA"))
print(my_phone.call())
print(my_phone.price)

# print(my_phone)
# print(my_phone.brand)
# print(my_phone.color)
# print(my_phone.price)