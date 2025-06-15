import nmap

class Host():
    def __init__(self):
        url=""
        ipv4 = ""
        ipv6 = ""
        hostname = ""
        oports = []
        cports = []
        
        scanner = None
        
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
        self.hostame = hostname
        
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
        
    def get_scanner(self):
        return self.scanner
    
    def set_scanner(self, scanner):
        self.scanner = scanner
            
    def show_info(self):
        print("URL: " + self.get_url())
        print("IPv4 : " + self.get_ipv4())
                
        print("\nOpened Ports (port/service): ")
        for o in self.get_oports():
            print("Port: " + str(o) + "/" + self.get_scanner()[self.get_ipv4()]['tcp'][o]['name'])
    
    def inform(self):
        try:
            print()
        except Exception as ex:
            print(ex)        
        
    def info(self):
        try:
            self.set_scanner(nmap.PortScanner())
            self.get_scanner().scan(hosts=self.get_url())
            
            for host in self.get_scanner().all_hosts():
                self.set_ipv4(host)
                for proto in self.get_scanner()[host].all_protocols():
                    ports = self.get_scanner()[host][proto].keys()
                    self.set_oports(ports)

        except Exception as ex:
            print(ex)
        