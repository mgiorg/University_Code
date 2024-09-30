import tkinter as tk

class Calculator(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Calculator")
        self.geometry("300x400")

        self.expression = ""

        # Entry widget for displaying the expression
        self.display = tk.Entry(self, font=("Arial", 20), borderwidth=2, relief="ridge")
        self.display.pack(expand=True, fill="both")

        # Create buttons
        button_frame = tk.Frame(self)
        button_frame.pack()

        buttons = [
            '7', '8', '9', '/',
            '4', '5', '6', '*',
            '1', '2', '3', '-',
            'C', '0', '=', '+'
        ]

        # Create and place buttons in the grid
        row_val = 0
        col_val = 0
        for button in buttons:
            btn = tk.Button(button_frame, text=button, font=("Arial", 18), borderwidth=1, relief="ridge",
                            command=lambda b=button: self.on_button_click(b))
            btn.grid(row=row_val, column=col_val, sticky="nsew", ipadx=10, ipady=10)
            col_val += 1
            if col_val > 3:
                col_val = 0
                row_val += 1

        # Configure grid to expand properly
        for i in range(4):
            button_frame.grid_columnconfigure(i, weight=1)
            button_frame.grid_rowconfigure(i, weight=1)

    def on_button_click(self, button):
        if button == 'C':
            self.expression = ""
            self.display.delete(0, tk.END)
        elif button == '=':
            try:
                result = eval(self.expression)
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, str(result))
                self.expression = str(result)
            except Exception as e:
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, "Error")
                self.expression = ""
        else:
            self.expression += button
            self.display.delete(0, tk.END)
            self.display.insert(tk.END, self.expression)

if __name__ == "__main__":
    calculator = Calculator()
    calculator.mainloop()
