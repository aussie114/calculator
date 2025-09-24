#!/usr/bin/env python
from tkinter import *
from tkinter import font
import ctypes

# Load tinyepr
te = ctypes.CDLL("./tinyexpr.so")
te.te_interp.argtypes = [ctypes.c_char_p, ctypes.POINTER(ctypes.c_int)]
te.te_interp.restype = ctypes.c_double

font_size = 12

class Widgets:
    pass                                                                                                          
widgets = Widgets() 

def main():
    widgets.window = Window()
    widgets.output = Output() 
    widgets.input = Input() 

    widgets.window.mainloop()

class Window(Tk):
    def __init__(self):
        super().__init__()
        self.title("calculator")
        self.resizable(False, False)
        self.configure(background="#383c4a")
        self.bind("<Escape>", self.terminate)

    def terminate(self, event):
        self.destroy()

class Input(Entry):
    def __init__(self):
        super().__init__(
            background="#444a58",
            borderwidth=0,
            foreground="#c6cdd6",
            highlightbackground="#2b2e39",
            highlightcolor="#5294e2",
            highlightthickness=1,
            insertbackground="#d3dae3",
            relief="flat",
            selectbackground="#5294e2",
            selectforeground="#e7f0fb",
            font=("TkfixedFont", font_size)
        )

        self.grid(row=1, column=0, sticky="WE", padx=2, pady=2)
        self.focus()
        self.bind("<Return>", self.on_text_submitted)
        self.bind("<KP_Enter>", self.on_text_submitted)

    def on_text_submitted(self, event):
        expression = self.get()
        result = te.te_interp(expression.encode("utf-8"), None)

        if result.is_integer():
            result = str(int(result))
        else:
            result = str(result)

        widgets.output.configure(state="normal")
        widgets.output.insert("end", "%s = %s\n" % (expression, result))
        widgets.output.see("end")
        widgets.output.configure(state="disabled")

class Output(Text):
    def __init__(self):
        super().__init__(
            background="#444a58",
            borderwidth=0,
            foreground="#c6cdd6",
            highlightbackground="#2b2e39",
            highlightcolor="#5294e2",
            highlightthickness=1,
            insertbackground="#d3dae3",
            selectbackground="#5294e2",
            selectforeground="#e7f0fb",
            state="disabled",
            wrap="none",
            width=30,
            height=15,
            font=("TkfixedFont", font_size)
        )
        self.grid(row=0, column=0, padx=2, pady=2)
main()
