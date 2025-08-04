import tkinter as tk
from tkinter import ttk, messagebox

class SchoolApp:
    def __init__(self, root):
        self.root = root
        self.root.title("🏫 School Management System")
        self.root.geometry("700x500")
        self.root.config(bg="#e9f5f9")

        self.students = []

        # --- Title ---
        tk.Label(root, text="📚 Python Academy", font=("Helvetica", 20, "bold"), bg="#e9f5f9", fg="#333").pack(pady=10)

        # --- Tabs ---
        self.tabs = ttk.Notebook(root)
        self.tabs.pack(expand=True, fill="both")

        self.register_tab = tk.Frame(self.tabs, bg="white")
        self.view_tab = tk.Frame(self.tabs, bg="white")

        self.tabs.add(self.register_tab, text="📝 Register Student")
        self.tabs.add(self.view_tab, text="📋 View Students")

        self.build_register_tab()
        self.build_view_tab()

    def build_register_tab(self):
        frame = tk.Frame(self.register_tab, bg="white")
        frame.pack(pady=20)

        tk.Label(frame, text="Full Name:", bg="white", font=("Arial", 12)).grid(row=0, column=0, sticky="e", padx=10, pady=5)
        self.name_entry = tk.Entry(frame, width=30)
        self.name_entry.grid(row=0, column=1)

        tk.Label(frame, text="Age:", bg="white", font=("Arial", 12)).grid(row=1, column=0, sticky="e", padx=10, pady=5)
        self.age_entry = tk.Entry(frame, width=30)
        self.age_entry.grid(row=1, column=1)

        tk.Label(frame, text="Grade:", bg="white", font=("Arial", 12)).grid(row=2, column=0, sticky="e", padx=10, pady=5)
        self.grade_entry = tk.Entry(frame, width=30)
        self.grade_entry.grid(row=2, column=1)

        tk.Label(frame, text="Section:", bg="white", font=("Arial", 12)).grid(row=3, column=0, sticky="e", padx=10, pady=5)
        self.section_entry = tk.Entry(frame, width=30)
        self.section_entry.grid(row=3, column=1)

        # Buttons
        btn_frame = tk.Frame(self.register_tab, bg="white")
        btn_frame.pack(pady=10)

        tk.Button(btn_frame, text="➕ Add Student", bg="#28a745", fg="white", font=("Arial", 12),
                  command=self.add_student).grid(row=0, column=0, padx=10)
        tk.Button(btn_frame, text="🧹 Clear", bg="#dc3545", fg="white", font=("Arial", 12),
                  command=self.clear_form).grid(row=0, column=1, padx=10)

    def build_view_tab(self):
        top = tk.Frame(self.view_tab, bg="white")
        top.pack(pady=10)

        self.count_label = tk.Label(top, text="Total Students: 0", font=("Arial", 14), bg="white", fg="#007bff")
        self.count_label.pack()

        self.tree = ttk.Treeview(self.view_tab, columns=("Name", "Age", "Grade", "Section"), show="headings")
        self.tree.heading("Name", text="Name")
        self.tree.heading("Age", text="Age")
        self.tree.heading("Grade", text="Grade")
        self.tree.heading("Section", text="Section")
        self.tree.pack(padx=20, pady=10, fill="both", expand=True)

        style = ttk.Style()
        style.configure("Treeview.Heading", font=("Arial", 12, "bold"))
        style.configure("Treeview", font=("Arial", 11))

    def add_student(self):
        name = self.name_entry.get()
        age = self.age_entry.get()
        grade = self.grade_entry.get()
        section = self.section_entry.get()

        if not name or not age or not grade or not section:
            messagebox.showwarning("Input Error", "Please fill in all fields.")
            return

        self.students.append((name, age, grade, section))
        self.tree.insert("", tk.END, values=(name, age, grade, section))
        self.clear_form()
        self.count_label.config(text=f"Total Students: {len(self.students)}")
        messagebox.showinfo("🎉 Success", f"Student '{name}' has been added!")

    def clear_form(self):
        self.name_entry.delete(0, tk.END)
        self.age_entry.delete(0, tk.END)
        self.grade_entry.delete(0, tk.END)
        self.section_entry.delete(0, tk.END)

# --- Run App ---
if __name__ == "__main__":
    root = tk.Tk()
    app = SchoolApp(root)
    root.mainloop()
