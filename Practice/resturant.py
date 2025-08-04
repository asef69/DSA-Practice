import tkinter as tk
from tkinter import messagebox

class RestaurantApp:
    def __init__(self, root):
        self.root = root
        self.root.title("🍽️ Restaurant Management System")
        self.root.geometry("500x600")
        self.root.configure(bg="#f4f4f4")

        self.menu = {
            "Burger": 5.99,
            "Pizza": 8.99,
            "Pasta": 7.49,
            "Salad": 4.99,
            "Soda": 1.99
        }

        self.item_vars = {}
        self.qty_vars = {}

        title = tk.Label(root, text="Welcome to Pythonic Diner!", font=("Helvetica", 18, "bold"), bg="#f4f4f4", fg="#333")
        title.pack(pady=10)

        self.menu_frame = tk.Frame(root, bg="#ffffff", bd=2, relief="groove")
        self.menu_frame.pack(padx=20, pady=10, fill="x")

        tk.Label(self.menu_frame, text="Menu", font=("Helvetica", 16, "bold"), bg="#ffffff").grid(row=0, column=0, columnspan=3, pady=5)

        for i, (item, price) in enumerate(self.menu.items()):
            var = tk.IntVar()
            qty_var = tk.IntVar()
            self.item_vars[item] = var
            self.qty_vars[item] = qty_var

            chk = tk.Checkbutton(self.menu_frame, text=f"{item} - ${price:.2f}", variable=var, bg="#ffffff", command=lambda i=item: self.toggle_entry(i))
            chk.grid(row=i + 1, column=0, sticky="w", padx=10)

            qty_entry = tk.Entry(self.menu_frame, textvariable=qty_var, width=5, state="disabled")
            qty_entry.grid(row=i + 1, column=1, padx=5)

        # Buttons
        btn_frame = tk.Frame(root, bg="#f4f4f4")
        btn_frame.pack(pady=10)

        tk.Button(btn_frame, text="🧾 Generate Bill", font=("Helvetica", 12), bg="#4CAF50", fg="white", command=self.calculate_total).grid(row=0, column=0, padx=10)
        tk.Button(btn_frame, text="🔁 Reset", font=("Helvetica", 12), bg="#f44336", fg="white", command=self.reset).grid(row=0, column=1, padx=10)

        # Result area
        self.result_text = tk.Text(root, height=10, width=50, font=("Courier", 10), bg="#fdfdfd")
        self.result_text.pack(padx=20, pady=10)

    def toggle_entry(self, item):
        if self.item_vars[item].get() == 1:
            self.qty_vars[item].set(1)
            entry_widget = self.menu_frame.grid_slaves(row=list(self.menu.keys()).index(item) + 1, column=1)[0]
            entry_widget.config(state="normal")
        else:
            self.qty_vars[item].set(0)
            entry_widget = self.menu_frame.grid_slaves(row=list(self.menu.keys()).index(item) + 1, column=1)[0]
            entry_widget.config(state="disabled")

    def calculate_total(self):
        self.result_text.delete("1.0", tk.END)
        total = 0
        bill_details = "------ Your Bill ------\n"

        for item, price in self.menu.items():
            if self.item_vars[item].get():
                qty = self.qty_vars[item].get()
                if qty > 0:
                    cost = qty * price
                    total += cost
                    bill_details += f"{item:<10} x {qty:<2} = ${cost:.2f}\n"

        if total == 0:
            messagebox.showinfo("No Selection", "Please select and enter quantity for at least one item.")
            return

        bill_details += f"\nTotal Bill: ${total:.2f}"
        bill_details += "\nThank you! 😊"
        self.result_text.insert(tk.END, bill_details)

    def reset(self):
        for item in self.menu:
            self.item_vars[item].set(0)
            self.qty_vars[item].set(0)
            entry_widget = self.menu_frame.grid_slaves(row=list(self.menu.keys()).index(item) + 1, column=1)[0]
            entry_widget.config(state="disabled")
        self.result_text.delete("1.0", tk.END)

# Run the app
if __name__ == "__main__":
    root = tk.Tk()
    app = RestaurantApp(root)
    root.mainloop()
