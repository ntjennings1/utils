import time
import tkinter as tk
from tkinter import scrolledtext

class Viewer(tk.Frame):

    def __init__(self, master, window, host):
        super().__init__(master)
        self.master = master
        self.window = window
        self.host = host
        self.view = None

        self.customize()

    def get_window(self):
        return self.window
    
    def set_window(self, window):
        self.window = window
        
    def get_master(self):
        return self.master
    
    def set_master(self, master):
        self.master = master
    
    def get_host(self):
        return self.host

    def set_host(self, host):
        self.host = host    
        
    def get_view(self):
        return self.view

    def set_view(self, view):
        self.view = view

    def place(self, row, col):
        self.grid(row=row, column=col)
    
    def add_line(self, line):
        self.get_view().insert(tk.END, line)
    
    def clear_text(self):
        self.get_view().delete("1.0", tk.END)
        self.get_view().insert(tk.END, "")
    
    def customize(self):
        self.set_view(scrolledtext.ScrolledText(self))
        
        boot_info = [
            "Welcome to the test suite. \n",
            "\n",
            "Here you can analyze and test endpoints. \n"
        ]
        for line in boot_info:    
            self.get_view().insert(tk.END, line)
            
        self.get_view().config(bg='white', height=24, state='disabled')
        self.get_view().grid(row=0, column=0)