""" Native imports. """
import time
import tkinter as tk
from tkinter import scrolledtext

class Viewer(tk.Frame):
    """
    A class representation of a viewer.
    
    ```
    Attributes
    ----------
    master : The viewer's master
    window : The test suite's window
    host : The test suite's host
    view : The viewer's view
    
    ```
    Methods
    -------
    place : Places the viewer in the test suite
    customize : Customizes the viewers entities
    add_line : Adds a line to the view
    clear_text : Clears the view
    """
    
    """ Initializes the class instance.
    
    @param master : The viewer's master
    @type master : tk.Tk()
    
    @param window : The test suite's window
    @type window : Object.class    
    
    @param host : The test suite's host
    @type host : Object.class
    """
    def __init__(self, master, window, host):
        super().__init__(master)
        self.master = master
        self.window = window
        self.host = host
        self.view = None

        self.customize()

    """ Returns the viewer's window.
    
    @return window : The viewer's window
    @rtype window : Object.class
    """
    def get_window(self):
        return self.window
    
    """ Sets the viewer's window.
    
    @param window : The viewer's window
    @type window : Object.class
    """
    def set_window(self, window):
        self.window = window
    
    """ Returns the viewers master.
    
    @return master : The viewer's master
    @rtype master : tk.Tk()
    """    
    def get_master(self):
        return self.master
    
    """ Sets the viewer's master.
    
    @param master : The viewer's master
    @type master : tk.Tk()
    """
    def set_master(self, master):
        self.master = master
    
    """ Returns the viewer's host.
    
    @return host : The viewer's host
    @rtype host : Object.class
    """
    def get_host(self):
        return self.host

    """ Sets the viewer's host.
    
    @param host : The viewer's host
    @type host : Object.class
    """
    def set_host(self, host):
        self.host = host    
    
    """ Returns the viewer's view.
    
    @return view : The viewer's view
    @rtype view : tk.ScrolledText()
    """    
    def get_view(self):
        return self.view

    """ Sets the viewer's view.
    
    @param view : The viewer's view
    @type view : tk.ScrolledText()
    """
    def set_view(self, view):
        self.view = view

    """ Places the viewer in the test suite.
    
    @return null
    """
    def place(self, row, col):
        self.grid(row=row, column=col)
    
    """ Adds lines to the view.
    
    @param line : A line
    @type line : string
    """
    def add_line(self, line):
        self.get_view().insert(tk.END, line)
    
    """ Clears the viewer's text.
    
    @return null
    """
    def clear_text(self):
        self.get_view().delete("1.0", tk.END)
        self.get_view().insert(tk.END, "")
    
    """ Customizes the viewer's entity.
    
    @return null
    """
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