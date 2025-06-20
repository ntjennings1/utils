import os
import subprocess

class Scenario():
    def __init__(self):
        self.system = ""
        
        self.eval()
        
    def get_system(self):
        return self.system
    
    def set_system(self, system):
        self.system = system
        
    def ping(self, ipv4, psize, length):
        try:
            if self.get_system() == 'Windows':
                results = subprocess.run(["ping", '-n', '2', '-l', psize, ipv4])
            else:
                results = subprocess.run(["ping", '-c', '2', ipv4])
            
        except Exception as ex:
            print(ex)
        
    def clear_screen(self):
        if self.get_system() == 'Windows':
            os.system('cls')
        else:
            os.system('clear')
        
    def eval(self):
        if os.name == 'nt':
            self.set_system('Windows')
        else:
            self.set_system('Linux')
