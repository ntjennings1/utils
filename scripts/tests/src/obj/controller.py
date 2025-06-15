import time
import tkinter as tk

class Controller(tk.Frame):

    def __init__(self, master, window, host):
        super().__init__(master)
        self.master = master
        self.window = window
        self.host = host
        self.labels = []
        self.entries = []
        self.buttons = []

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

    def get_labels(self):
        return self.labels

    def set_labels(self, labels):
        self.labels= labels

    def get_entries(self):
        return self.entries

    def set_entries(self, entries):
        self.entries = entries
        
    def get_buttons(self):
        return self.buttons
    
    def set_buttons(self, buttons):
        self.buttons = buttons
        
    def help(self):
        
        mes = "The test suite can do the following: "
        
    def exit(self):
        self.get_master().destroy()

    def place(self, row, col):
        self.grid(row=row, column=col)

    def customize(self):
        labels = []
        entries = []
        buttons = []
        
        url_label = tk.Label(self, text="URL : ")
        labels.append(url_label)
        ipv4_label = tk.Label(self, text="IPv4 Address : ")
        labels.append(ipv4_label)
        ipv6_label = tk.Label(self, text="IPv6 Address : ")
        labels.append(ipv6_label)
        hostname_label = tk.Label(self, text="Hostname : ")
        labels.append(hostname_label)
        port_label = tk.Label(self, text="Port # : ")
        labels.append(port_label)
        usr_label = tk.Label(self, text="User : ")
        labels.append(usr_label)
        psw_label = tk.Label(self, text="Password : ")
        labels.append(psw_label)
        
        url_text = tk.StringVar(value="https://www.github.com")
        ipv4_text = tk.StringVar(value="192.168.1.1")
        ipv6_text = tk.StringVar(value="2001:db8:85a3::8a2e:370:7334")
        hostname_text = tk.StringVar(value="localhost")
        port_text = tk.StringVar(value="80")
        usr_text = tk.StringVar(value="username")
        psw_text = tk.StringVar(value="password")
        
        url_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=url_text)
        entries.append(url_entry)
        ipv4_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=ipv4_text)
        entries.append(ipv4_entry)
        ipv6_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=ipv6_text)
        entries.append(ipv6_entry)
        hostname_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=hostname_text)
        entries.append(hostname_entry)
        port_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=port_text)
        entries.append(port_entry)
        usr_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=usr_text)
        entries.append(usr_entry)
        psw_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=psw_text)
        entries.append(psw_entry)
        
        inform_button = tk.Button(self, width=10, state='active',
                                text="Inform", command=lambda:self.get_host().inform())
        buttons.append(inform_button)
        help_button = tk.Button(self, width=10, state='active',
                                text="Help", command=lambda:self.help())
        stop_button = tk.Button(self, width=10, state='disabled',
                                text="Stop")
        buttons.append(stop_button)
        exit_button = tk.Button(self, width=10, state='active',
                                text="Exit", command=lambda:self.exit())
        buttons.append(exit_button)
        
        url_label.grid(row=0, column=0)
        url_entry.grid(row=0, column=1)

        ipv4_label.grid(row=1, column=0)
        ipv4_entry.grid(row=1, column=1)

        ipv6_label.grid(row=2, column=0)
        ipv6_entry.grid(row=2, column=1)

        hostname_label.grid(row=3, column=0)
        hostname_entry.grid(row=3, column=1)

        port_label.grid(row=4, column=0)
        port_entry.grid(row=4, column=1)

        usr_label.grid(row=5, column=0)
        usr_entry.grid(row=5, column=1)

        psw_label.grid(row=6, column=0)
        psw_entry.grid(row=6, column=1)
        
        inform_button.grid(row=8, column=0, pady=(50, 0))
        stop_button.grid(row=9, column=0)
        exit_button.grid(row=10, column=0)
        
        self.set_labels(labels)
        self.set_entries(entries)
        