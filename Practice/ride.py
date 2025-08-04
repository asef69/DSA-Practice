import tkinter as tk
from tkinter import ttk, messagebox
import random

# Simulated drivers
drivers = [
    {"name": "Alice", "location": random.randint(1, 10)},
    {"name": "Bob", "location": random.randint(1, 10)},
    {"name": "Charlie", "location": random.randint(1, 10)},
    {"name": "Diana", "location": random.randint(1, 10)}
]

class RideSharingApp:
    def __init__(self, root):
        self.root = root
        self.root.title("🚗 Ride Sharing App")
        self.root.geometry("500x500")
        self.root.configure(bg="#f7f7f7")

        self.notebook = ttk.Notebook(root)
        self.notebook.pack(expand=True, fill="both")

        self.rider_tab = tk.Frame(self.notebook, bg="#f7f7f7")
        self.driver_tab = tk.Frame(self.notebook, bg="#f0f0f0")

        self.notebook.add(self.rider_tab, text="🚕 Rider")
        self.notebook.add(self.driver_tab, text="🧑‍✈️ Driver")

        self.build_rider_tab()
        self.build_driver_tab()

    # --- Rider Tab ---
    def build_rider_tab(self):
        tk.Label(self.rider_tab, text="Request a Ride", font=("Arial", 16, "bold"), bg="#f7f7f7").pack(pady=20)

        tk.Label(self.rider_tab, text="Your Name:", bg="#f7f7f7").pack()
        self.rider_name = tk.Entry(self.rider_tab)
        self.rider_name.pack(pady=5)

        tk.Label(self.rider_tab, text="Your Location (1-10):", bg="#f7f7f7").pack()
        self.rider_location = tk.Entry(self.rider_tab)
        self.rider_location.pack(pady=5)

        tk.Label(self.rider_tab, text="Destination (1-10):", bg="#f7f7f7").pack()
        self.destination = tk.Entry(self.rider_tab)
        self.destination.pack(pady=5)

        tk.Button(self.rider_tab, text="🚗 Find Ride", bg="#28a745", fg="white", command=self.find_ride).pack(pady=15)

        self.ride_result = tk.Label(self.rider_tab, text="", font=("Arial", 12), bg="#f7f7f7", fg="#333")
        self.ride_result.pack(pady=10)

    def find_ride(self):
        try:
            name = self.rider_name.get()
            loc = int(self.rider_location.get())
            dest = int(self.destination.get())

            if not name or loc < 1 or dest < 1 or loc > 10 or dest > 10:
                raise ValueError

            nearest_driver = min(drivers, key=lambda d: abs(d['location'] - loc))
            driver_name = nearest_driver["name"]
            driver_loc = nearest_driver["location"]
            distance = abs(loc - dest)
            fare = distance * 2.5 + random.uniform(1.5, 3.0)

            self.ride_result.config(
                text=f"🚕 Driver {driver_name} is on the way!\nFrom location {driver_loc} to {loc}\nEstimated Fare: ${fare:.2f}"
            )

        except ValueError:
            messagebox.showerror("Input Error", "Please enter valid numbers (1-10) for locations.")

    # --- Driver Tab ---
    def build_driver_tab(self):
        tk.Label(self.driver_tab, text="Available Drivers", font=("Arial", 16, "bold"), bg="#f0f0f0").pack(pady=20)

        self.driver_list = tk.Listbox(self.driver_tab, font=("Arial", 12), height=8, width=40)
        self.driver_list.pack(pady=10)

        self.update_driver_list()

        tk.Button(self.driver_tab, text="🔄 Refresh", bg="#007bff", fg="white", command=self.update_driver_list).pack(pady=10)

    def update_driver_list(self):
        self.driver_list.delete(0, tk.END)
        for d in drivers:
            self.driver_list.insert(tk.END, f"{d['name']} - Location: {d['location']}")

# Run app
if __name__ == "__main__":
    root = tk.Tk()
    app = RideSharingApp(root)
    root.mainloop()
