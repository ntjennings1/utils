import os
import time
import socket
import requests
import threading
import tkinter as tk
import multiprocessing as mp

class Host():
    def __init__(self, scene):
        self.scene = scene
        self.request = None
        self.url = ""
        self.con = ""
        self.status = ""
        self.content_type = ""
        self.ipv4 = ""
        self.ipv6 = ""
        self.hostname = ""
        self.oports = []
        self.cports = []
        self.psize = ""
        self.length = ""
        
        self.reports = []
                
    def get_scene(self):
        return self.scene
    
    def set_scene(self, scene):
        self.scene = scene  
        
    def get_request(self):
        return self.request
    
    def set_request(self, request):
        self.request = request
        
    def get_con(self):
        return self.con
    
    def set_con(self, con):
        self.con = con
        
    def get_status(self):
        return self.status
    
    def set_status(self, status):
        self.status = status
        
    def get_content_type(self):
        return self.content_type
    
    def set_content_type(self, content_type):
        self.content_type = content_type
    
    def set_status(self, status):
        self.status = status
        
    def get_content_type(self):
        return self.content_type
    
    def set_content_type(self, content_type):
        self.content_type = content_type
    
    def get_url(self):
        return self.url
    
    def set_url(self, url):
        self.url = url
        
    def get_ipv4(self):
        return self.ipv4
    
    def set_ipv4(self, ipv4):
        self.ipv4 = ipv4
    
    def get_ipv6(self):
        return self.ipv6
    
    def set_ipv6(self, ipv6):
        self.ipv6 = ipv6
    
    def get_hostname(self):
        return self.hostname
    
    def set_hostname(self, hostname):
        self.hostname = hostname
        
    def get_oports(self):
        return self.oports
    
    def set_oports(self, oports):
        self.oports = oports
        
    def add_oport(self, oport):
        self.oports.append(oport)
        
    def get_cports(self):
        return self.cports
    
    def set_cports(self, cports):
        self.cports = cports
        
    def add_cport(self, cport):
        self.get_cports().append(cport)
        
    def get_psize(self):
        return self.psize
    
    def set_psize(self, psize):
        self.psize = psize
        
    def get_length(self):
        return self.length
    
    def set_length(self, length):
        self.length = length
        
    def get_reports(self):
        return self.reports
    
    def set_reports(self, reports):
        self.reports = reports
        
    def add_report(self, report):
        self.reports.append(report)
        
    def pod(self):
        def kill_threads(threads):
            for t in threads:
                t.stop()
        
        def ping():
            self.get_scene().ping(self.get_ipv4(), self.get_psize(), self.get_length())
        
        try:
            threads = []
            i = 0         
            while True:
                i = i + 1
                print(i)
                p_thread = threading.Thread(target=ping())
                p_thread.start()
                threads.append(p_thread)
                
            kill_threads(threads)
        
        except Exception as ex:
            print(ex)
                        
    def show_info(self):
        print("URL: " + self.get_url())
        print("IPv4 : " + self.get_ipv4())
        print("Hostname : " + self.get_hostname())
                
        print("\nOpened Ports (port/service): ")
        for o in self.get_oports():
            print()
                
    def fetch_others(self):
        try:
            temp = socket.gethostbyaddr(self.get_ipv4())
            check = self.get_ipv4().replace('.','-')
        
            out = temp[0].replace(check, "")
            self.set_hostname(out)
        except Exception as ex:
            self.set_hostname("")
            
            self.set_reports([])
            self.add_report(ex)
            self.add_report("The test suite will be limited without a hostname.")
            print(ex)
            print('foth')
                
    def fetch_ports(self):
        print()
        
    def fetch_ipv4(self):
        try:
            turl = self.get_url().replace('https://www.', '')
            self.set_ipv4(socket.gethostbyname(turl))
            self.set_status(self.get_request().headers['content-type'])
            
        except Exception as ex:
            self.set_ipv4("")
            
            self.set_reports([])
            self.add_report(ex)
            self.add_report("Try a different URL.")
            print(ex)
            print('fips')
                
    def inform(self):
        try:
            self.get_scene().clear_screen()
            
            ip_thread = threading.Thread(target=self.fetch_ipv4())
            ip_thread.start()
            ip_thread.join()
            
            port_thread = None
            
            other_thread = threading.Thread(target=self.fetch_others())
            other_thread.start()
            other_thread.join()
                                            
        except Exception as ex:
            print(ex)
            print('inform')
            
    def check_con(self):
        try:
            self.set_request(requests.get(self.get_url()))
            self.set_status(self.get_request().status_code)
            if self.get_status() == 200:
                self.set_con('Safely connected to "' + self.get_url() + '". \n\nTry informing.')
            else:
                self.set_con('Connection to "' + self.get_url() + '" is not safe. \n\nCheck the URL.')

        except Exception as ex:
            
            self.set_reports([])
            self.add_report(ex)
            self.add_report("The test suite will not work without a reachable network")
            print(ex)
            print('con')
            
    def quick(self):
        self.check_con()
        self.inform()
        self.show_info()
