import tkinter as tk

from obj.controller import Controller
from obj.viewer import Viewer

class Window():
    def __init__(self, host): 
        self.host = host
        self.root = tk.Tk()
        
        self.controller = None
        self.viewer = None
        
    def get_host(self):
        return self.host

    def set_host(self, host):
        self.host = host

    def get_root(self):
        return self.root
    
    def set_root(self, root):
        self.root = root

    def get_controller(self):
        return self.controller

    def set_controller(self, controller):
        self.controller = controller

    def get_viewer(self):
        return self.viewer

    def set_viewer(self, viewer):
        self.viewer = viewer

    def fill(self):
        self.set_viewer(Viewer(self.get_root(), self, self.get_host()))
        self.set_controller(Controller(self.get_root(), self, self.get_host()))
        self.get_controller().set_viewer(self.get_viewer())

    def customize(self):

        self.get_controller().place(0,0)
        self.get_controller().config(padx=10)
    
        self.get_viewer().place(1,0)
        self.get_viewer().get_view().config(width=60, padx=2)

    def open(self):
        self.fill()
        self.customize()
        self.get_root().mainloop()