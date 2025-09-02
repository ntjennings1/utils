""" Native imports. """
import os
import asyncio
import subprocess

class Scenario():
    """
    A class representation of a scenario.
    
    ```
    Attributes
    ----------
    system : The name of the system running the test suite.
    
    ```
    Methods
    -------
    eval : Evaluates the system
    clear_screen : Clears the systems terminal
    ping : Performs a ping
    """
    
    """ Initializes the class instance.
    
    @return null
    """
    def __init__(self):
        self.system = ""
        
        self.eval()

    """ Returns the systems name.
    
    @return system : The system's name
    @rtype system : string
    """
    def get_system(self):
        return self.system
    
    """ Sets the systems name.
    
    @param system : The system's name
    @type system : string
    """
    def set_system(self, system):
        self.system = system
    
    """ Performs a ping.
    
    @param ipv4 : Host ipv4 address
    @type ipv4 : string
    
    @param size : Packet size
    @type size : int
    
    @param length : Loop length
    @type length : int
    """
    def ping(self, ipv4, psize, length):
        try:
            if self.get_system() == 'Windows':
                results = subprocess.run(["ping", '-n', '2', '-l', psize, ipv4])
            else:
                results = subprocess.run(["ping", '-c', '2', '-s', psize, ipv4])
            
        except Exception as ex:
            print(ex)
    
    """ Clears the system's terminal.
    
    @return null
    """
    def clear_screen(self):
        if self.get_system() == 'Windows':
            os.system('cls')
        else:
            os.system('clear')
    
    """ Evaluates the system.
    
    @return null
    """    
    def eval(self):
        if os.name == 'nt':
            self.set_system('Windows')
        else:
            self.set_system('Linux')
