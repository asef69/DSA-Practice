class Product:
    def __init__(self, name, quantity, price):
        self.name = name
        self.quantity = quantity
        self.price = price

    def __str__(self):
        return f"{self.name} -> {self.price} (stock: {self.quantity})"


class Shop:
    def __init__(self):
        self.products = {}

    def add_product(self, product):
        if product.name in self.products:
            self.products[product.name].quantity += product.quantity
        else:
            self.products[product.name] = product
        print(f"Added {product.quantity} of {product.name} to the shop.")

    def buy_product(self, name, quantity):
        if name not in self.products:
            print(f"Sorry, the product is not available in the shop.")
            return

        product = self.products[name]

        if product.quantity < quantity:
            print(f"Sorry, only {product.quantity} of {name} are left in stock.")
            return

        product.quantity -= quantity
        print(f"🎉 Congo! You have bought {quantity} of {name} for ${product.price * quantity}.")

        if product.quantity == 0:
            print(f"Sorry, {name} is now out of stock.")


# Example usage
shop = Shop()

apple = Product("Apple", 10, 0.5)   # quantity first, price second
banana = Product("Banana", 5, 0.3)

shop.add_product(apple)
shop.add_product(banana)

shop.buy_product("Apple", 3)
shop.buy_product("Orange", 2)  # Not available
shop.buy_product("Banana", 5)  # Buy all bananas
shop.buy_product("Banana", 1)  # Try buying out-of-stock item
