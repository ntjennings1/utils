""" Native imports. """
import os
import time
import socket
import requests
import threading
import tkinter as tk
import multiprocessing as mp
from multiprocessing import Pool

class Host():
    """
    A class representation of a host.
    
    ```
    Attributes
    ----------
    scene : The test suite's scenario
    request : Simple HTTP request
    url : The host's URL
    con : The host's connection description
    status : The host's connection status
    content_type : The host's content type(s)
    ipv4 : The host's ipv4 address
    ipv6 : The host's ipv6 address
    hostname : The host's hostname
    oports : The host's open ports
    cports : The host's closed ports
    psize : Test suite packet size
    length : Test suite loop length
    reports : Test suite reports
    
    ```
    Methods
    -------
    check_con : Checks connection to the host
    show_info : Shows available information
    fetch_ipv4 : Fetches host's ipv4 address
    fetch_ports : Fetches host's ports
    fetch_others : Fetches host's other characteristics
    add_report : Address report to the host's reports
    print_reports : Prints the host's reports
    inform : Informs the test suite on host characteristics
    pod : Performs Ping of Death
    quick : Performs quick testing
    """
    
    """ Initialize the class instance.
    
    @param scene : Test suite device
    @type scene : Object.class
    """
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
    
    """ Returns the test suite's scenario.
    
    @return scene : The scenerio
    @rtype scene : Object.class
    """
    def get_scene(self):
        return self.scene
    
    """ Sets the test suite's scenario.
    
    @param scene : The scenario
    @type scene : Object.class
    """
    def set_scene(self, scene):
        self.scene = scene  
    
    """ Returns the host's request.
    
    @return request : The request
    @rtype request : Request.get()
    """
    def get_request(self):
        return self.request
    
    """ Sets the host's request.
    
    @param request : The request
    @type request : Request.get()
    """
    def set_request(self, request):
        self.request = request
    
    """ Return the host's connection description.
    
    @return con : The description
    @rtype con : string
    """
    def get_con(self):
        return self.con
    
    """ Sets the host's connection description.
    
    @param con : The description
    @type con : string
    """
    def set_con(self, con):
        self.con = con
    
    """ Returns the host's status code.
    
    @return status : The host's status code
    @rtype status : int
    """
    def get_status(self):
        return self.status
    
    """ Sets the host's status code.
    
    @param status : The host's status code
    @type status : int
    """
    def set_status(self, status):
        self.status = status
    
    """ Returns the host's content type.
    
    @return content_type : The host's content type(s)
    @rtype content_type : list
    """    
    def get_content_type(self):
        return self.content_type
    
    """ Sets the host's content type.
    
    @param content_type : The host's content type(s)
    @type content_type : list
    """
    def set_content_type(self, content_type):
        self.content_type = content_type
    
    """ Returns the host's URL.
    
    @return url : The host's URL
    @rtype url : string
    """    
    def get_url(self):
        return self.url
    
    """ Sets the host's URL.
    
    @param url : The host's URL
    @type url : string
    """
    def set_url(self, url):
        self.url = url
    
    """ Returns the host's ipv4 address.
    
    @return ipv4 : The host's ipv4
    @rtype ipv4 : string
    """
    def get_ipv4(self):
        return self.ipv4
    
    """ Sets the host's ipv4 address.
    
    @param ipv4 : The host's ipv4
    @type ipv4 : string
    """
    def set_ipv4(self, ipv4):
        self.ipv4 = ipv4
    
    """ Returns the host's ipv6 address.
    
    @return ipv6 : The host's ipv6
    @rtype ipv6 : string
    """
    def get_ipv6(self):
        return self.ipv6
    
    """ Sets the host's ipv6 address.
    
    @param ipv6 : The host's ipv6
    @type ipv6 : string
    """
    def set_ipv6(self, ipv6):
        self.ipv6 = ipv6
    
    """ Returns the host's hostname.
    
    @return hostname : The host's hostname
    @rtype hostname : string
    """
    def get_hostname(self):
        return self.hostname
    
    """ Sets the host's hostname.
    
    @param hostname : The host's hostname
    @type hostname : string
    """
    def set_hostname(self, hostname):
        self.hostname = hostname
    
    """ Returns the host's open ports.
    
    @return oports : The host's open ports
    @rtype oports : list
    """
    def get_oports(self):
        return self.oports
    
    """ Sets the host's open ports.
    
    @param oports : The host's open ports.
    @type oports : list
    """
    def set_oports(self, oports):
        self.oports = oports
    
    """ Adds an open port to the host's open ports.
    
    @param oport : An open port
    @type oport : string
    """    
    def add_oport(self, oport):
        self.oports.append(oport)
    
    """ Returns the host's closed ports.
    
    @return cports : The host's closed ports
    @rtype cports : list
    """
    def get_cports(self):
        return self.cports
    
    """ Sets the host's closed ports.
    
    @param cports : The host's closed ports
    @type cports : list
    """
    def set_cports(self, cports):
        self.cports = cports
    
    """ Adds a closed port to the host's closed ports.
    
    @param cport : A closed port
    @type cport : string
    """
    def add_cport(self, cport):
        self.get_cports().append(cport)
    
    """ Returns the packet size.
    
    @return psize : Packet size
    @rtype psize : int
    """
    def get_psize(self):
        return self.psize
    
    """ Sets the packet size.
    
    @param psize : Packet size
    @type psize : int
    """
    def set_psize(self, psize):
        self.psize = psize
    
    """ Returns the suite's loop length.
    
    @return length : Loop length
    @rtype length : int
    """    
    def get_length(self):
        return self.length
    
    """ Sets the suite's loop length.
    
    @param length : Loop length
    @type length : int
    """
    def set_length(self, length):
        self.length = length
    
    """ Returns the host's reports.
    
    @return reports : The host's reports
    @rtype reports : list
    """
    def get_reports(self):
        return self.reports
    
    """ Sets the host's reports.
    
    @param reports : The host's reports
    @type reports : list
    """
    def set_reports(self, reports):
        self.reports = reports
    
    """ Adds a report to the host's reports.
    
    @param report : A report
    @type report : string
    """    
    def add_report(self, report):
        self.reports.append(report)
    
    """ Performs the Ping of Death (DOS) attack.
    
    @return null.
    """    
    def pod(self):
        '''def kill_threads(threads):
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
            print(ex)'''
            
        try:
            ran = []
            for n in range(1,100000):
                ran.append(n)
            with Pool(processes=4) as pool:
                results = pool.map(self.get_scene().ping(self.get_ipv4(), self.get_psize(), self.get_length), ran)
            print(results)
        except Exception as ex:
            print(ex)
    
    """ Prints all host reports.
    
    @return null
    """    
    def print_reports(self):
        for r in self.get_reports():
            print(r)
    
    """ Shows the host's characteristics.
    
    @return null
    """
    def show_info(self):
        print("URL: " + self.get_url())
        print("IPv4 : " + self.get_ipv4())
        print("Hostname : " + self.get_hostname())
                
        print("\nOpened Ports (port/service): ")
        for o in self.get_oports():
            print()

    """ Fetches the host's other characteristics.
    
    @return null
    """
    def fetch_others(self):
        try:
            temp = socket.gethostbyaddr(self.get_ipv4())
            check = self.get_ipv4().replace('.','-')
        
            out = temp[0].replace(check, "")
            self.set_hostname(out)
        except Exception as ex:
            self.set_hostname("")
            
            self.set_reports([])
            self.add_report('F.Oth')
            self.add_report(ex)
            self.add_report("The test suite will be limited without a hostname.\n")
            self.print_reports()
    
    """ Fetches the host's ports.
    
    @return null
    """            
    def fetch_ports(self):
        print()
    
    """ Fetches the host's ipv4 address.
    
    @return null
    """    
    def fetch_ipv4(self):
        try:
            turl = self.get_url().replace('https://www.', '')
            self.set_ipv4(socket.gethostbyname(turl))
            self.set_status(self.get_request().headers['content-type'])
            
        except Exception as ex:
            self.set_ipv4("")
            
            self.set_reports([])
            self.add_report('F.IPs.')
            self.add_report(ex)
            self.add_report("Try a different URL.\n")
            self.print_reports()

    """ Informs the test suite on the host's characteristics.
    
    @return null
    """
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
    
    """ Checks the connection to the host.
    
    @return null
    """
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
            self.add_report('C.Con')
            self.add_report(ex)
            self.add_report("The test suite will not work without a reachable network.\n")
            self.print_reports()

    """ Performs a quick test on the selected host.
    
    @return null.
    """
    def quick(self):
        self.check_con()
        self.inform()
        #self.show_info()
