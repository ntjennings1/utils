""" Native imports. """
import tkinter as tk

""" Class imports. """
from obj.controller import Controller
from obj.viewer import Viewer

class Window():
    """
    A class representation of a window.
    
    ```
    Attributes
    ----------
    host : The test suite's host
    root : The applications host
    controller : The test suite's controller
    viewer : The test suite's viewer
    
    ```
    Methods
    -------
    fill : Fills the window
    customize : Customizes entities in the window
    open : Opens the window
    """
    
    """ Initializes the class instance.
    
    @param host : The test suite's host
    @type host : Object.class
    """
    def __init__(self, host): 
        self.host = host
        self.root = tk.Tk()
        
        self.controller = None
        self.viewer = None
    
    """ Returns the test suite's host.
    
    @return host : The test suite's host
    @rtype host : Object.class
    """
    def get_host(self):
        return self.host

    """ Sets the test suite's host.
    
    @param host : The test suite's host
    @type host : Object.host
    """
    def set_host(self, host):
        self.host = host

    """ Returns the application's root.
    
    @return root : The application's root
    @rtype root : tk.Tk()
    """
    def get_root(self):
        return self.root
    
    """ Sets the application's root.
    
    @param root : The application's root
    @type root : tk.Tk()
    """
    def set_root(self, root):
        self.root = root

    """ Returns the test suite's controller.
    
    @return controller : The test suite's controller
    @rtype controller : Object.class
    """
    def get_controller(self):
        return self.controller

    """ Sets the test suite's controller.
    
    @param controller : The test suite's controller
    @type controller : Object.class
    """
    def set_controller(self, controller):
        self.controller = controller

    """ Returns the test suite's viewer.
    
    @return viewer : The test suite's viewer
    @rtype viewer : Object.class
    """
    def get_viewer(self):
        return self.viewer

    """ Sets the test suite's viewer.
    
    @param viewer : The test suite's viewer
    @type viewer : Object.class
    """
    def set_viewer(self, viewer):
        self.viewer = viewer

    """ Fills the window.
    
    @return null
    """
    def fill(self):
        self.set_viewer(Viewer(self.get_root(), self, self.get_host()))
        self.set_controller(Controller(self.get_root(), self, self.get_host()))
        self.get_controller().set_viewer(self.get_viewer())

    """ Customizes the windows entities.
    
    @return null
    """
    def customize(self):

        self.get_controller().place(0,0)
        self.get_controller().config(padx=10)
    
        self.get_viewer().place(1,0)
        self.get_viewer().get_view().config(width=60, padx=2)

    """ Opens the window.
    
    @return null
    """
    def open(self):
        self.fill()
        self.customize()
        self.get_root().mainloop()