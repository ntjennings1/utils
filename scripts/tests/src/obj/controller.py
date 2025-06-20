import time
import threading
import tkinter as tk

class Controller(tk.Frame):

    def __init__(self, master, window, host):
        super().__init__(master)
        self.master = master
        self.window = window
        self.viewer = None
        self.host = host
        self.labels = []
        self.entries = []
        self.buttons = []
        self.threads = []

        self.customize()
        
    def get_window(self):
        return self.window
    
    def set_window(self, window):
        self.window = window
        
    def get_viewer(self):
        return self.viewer
    
    def set_viewer(self, viewer):
        self.viewer = viewer
        
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
        
    def get_threads(self):
        return self.threads
    
    def set_threads(self, threads):
        self.threads = threads
        
    def show_reports(self):
        i = 0
        for e in self.get_host().get_reports():
            self.get_viewer().get_view().insert(tk.END, str(i) + ": \n")
            self.get_viewer().get_view().insert(tk.END, e)
            self.get_viewer().get_view().insert(tk.END, "\n")
            i = i + 1
        
    def inform(self):
    
        self.get_viewer().get_view().config(state='normal')
        self.get_viewer().clear_text()
        self.get_viewer().get_view().insert(tk.END, "Informing ...\n\nPlease wait.")
        
        try:
            self.get_host().set_url(self.get_entries()[0][0].get())
            info_thread = threading.Thread(target=self.get_host().inform())
            info_thread.start()
            info_thread.join()
                
            self.get_viewer().clear_text()
            self.get_viewer().get_view().insert(tk.END, "The suite is now informed ...")
            self.get_viewer().get_view().insert(tk.END, "\nAny errors will appear here: \n")
            
            self.show_reports()
            
            self.get_viewer().get_view().insert(tk.END, "\n\nProceed.")
            self.get_viewer().get_view().config(state='disabled')
            
            for e in self.get_entries():
                if e[1] == 'ipv4':
                    ipv4_text = tk.StringVar(value=self.get_host().get_ipv4())
                    e[0].config(state='normal')
                    e[0].config(textvariable=ipv4_text)
                    e[0].config(state='disabled')
                if e[1] == 'hostname':
                    hostname_text = tk.StringVar(value=self.get_host().get_hostname())
                    e[0].config(state='normal')
                    e[0].config(textvariable=hostname_text)
                    e[0].config(state='disabled')
            for b in self.get_buttons():
                if b[1] == 'pod':
                    b[0].config(state='normal')
                if b[1] == 'inform':
                    b[0].config(state='disabled')
            
        except Exception as ex:            
           self.show_reports()
        
    def start(self):
        self.get_viewer().get_view().config(state='normal')
        self.get_viewer().clear_text()
        self.get_viewer().get_view().insert(tk.END, "Checking connection ...\n\nPlease wait.")
        
        try:         
            mes = ["\nNow you can progress futher into the test suite.",
                   "\n",
                   "Start by allowing the test suite to automatically inform itself:",
                   "1: Select the 'Inform' Button"]
               
            self.get_host().set_url(self.get_entries()[0][0].get())
            info_thread = threading.Thread(target=self.get_host().check_con())
            info_thread.start()
            info_thread.join()
            
            self.get_viewer().get_view().config(state='normal')
            self.get_viewer().clear_text()
            self.get_viewer().get_view().insert(tk.END, self.get_host().get_con())
            
            for e in self.get_entries():
                if e[1] == 'url':
                    e[0].config(state='disabled')
            
            for b in self.get_buttons():
                if b[1] == 'inform' or b[1] == 'reset' or b[1] == 'stop':
                    b[0].config(state='normal')
                elif b[1] == 'start':
                    b[0].config(state='disabled')

        except Exception as ex:          
           self.show_reports()
            
    def exit(self):
        exit(0)
          
    def help(self):
        
        ''' Inform on enpoint
            Simulate Attacks
                - Ping of Death
                - Dictionary Attack
            Integrate power levels        
                - GPU
                - Threading

        '''
        
        logo = '''
        
        |||||||||||||||||
            ||||       |
            ||||       +
            ||||
            ||||
            ||||
        
        \n
        '''
        
        
        mes = ["The test suite requires detailed information on an endpoint to begin. ",
        "Follow these steps to inform the suite of the endpoint:",
        "\n",
        "1: Enter the URL of the desired endpoint.\n",
        "2: Select the 'Start' button.\n",
        "3: Wait for the suite to confirm connection.\n",
        "\n",
        "\n",
        "Once the suite is connected, you can start the automated informer:",
        "\n",
        "1: Select the 'Inform' button.\n",
        "2: Wait for the suite to extract critical data.\n",
        "\n",
        "\n",
        "Once the suite is informed, you can simulate a number of different actions:\n",
        "1: SYN-ACK Flood\n",
        "2: Ping of Death\n",
        "3: Dicitonary Attack\n"]
        
        self.get_viewer().get_view().config(state='normal')
        self.get_viewer().clear_text()
        self.get_viewer().add_line(logo)
        for l in mes:
            self.get_viewer().add_line(l)
        self.get_viewer().get_view().config(state='disabled')
        
    def stop(self):
        
        for t in self.get_threads():
            t.kill()
        
        for e in self.get_entries():
            if e[1] == 'url':
                e[0].config(state='normal')
            
        for b in self.get_buttons():
            if b[1] == 'inform' or b[1] == 'stop':
                b[0].config(state='disabled')
            elif b[1] == 'start' or b[1] == 'reset':
                b[0].config(state='normal')
        
    def reset(self):
        self.get_master().destroy()

    def place(self, row, col):
        self.grid(row=row, column=col)
        
    def customize(self):
        labels = []
        entries = []
        buttons = []
        
        button_container=tk.Frame(self.get_master())
        check_container=tk.Frame(self.get_master())
        
        # Labels
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
        
        #Entry Texts
        url_text = tk.StringVar(value="https://www.place4us.net")
        ipv4_text = tk.StringVar(value="000.000.000.000")
        ipv6_text = tk.StringVar(value="0000:000:0000:0000:000:0000")
        hostname_text = tk.StringVar(value="xxx-xxx-x.com")
        port_text = tk.StringVar(value="00000")
        usr_text = tk.StringVar(value="xxxxxx")
        psw_text = tk.StringVar(value="xxxxxx")
        
        # Entries
        url_entry = tk.Entry(self, state='normal', width=40,
                            textvariable=url_text)
        entries.append([url_entry, 'url'])
        ipv4_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=ipv4_text)
        entries.append([ipv4_entry, 'ipv4'])
        ipv6_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=ipv6_text)
        entries.append([ipv6_entry, 'ipv6'])
        hostname_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=hostname_text)
        entries.append([hostname_entry, 'hostname'])
        port_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=port_text)
        entries.append([port_entry, 'port'])
        usr_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=usr_text)
        entries.append([usr_entry, 'username'])
        psw_entry = tk.Entry(self, state='disabled', width=40,
                            textvariable=psw_text)
        entries.append([psw_entry, 'password'])
        
        # Buttons
        start_button = tk.Button(button_container, width=35, state='active',
                                text='Start', command=lambda:self.start())
        buttons.append([start_button, 'start'])
        inform_button = tk.Button(button_container, width=35, state='disabled',
                                text="Inform", command=lambda:self.inform())
        buttons.append([inform_button, 'inform'])
        pod_button = tk.Button(button_container, width=35, state='disabled',
                                text="POD", command=lambda:self.pod())
        buttons.append([pod_button, 'pod'])
        reset_button = tk.Button(button_container, width=35, state='disabled',
                                text="Reset", command=lambda:self.reset())
        buttons.append([reset_button, 'reset'])
        help_button = tk.Button(button_container, width=35, state='active',
                                text="Help", command=lambda:self.help())
        buttons.append([help_button, 'help'])
        stop_button = tk.Button(button_container, width=35, state='disabled',
                                text="Stop", command=lambda:self.stop())
        buttons.append([stop_button, 'stop'])
        exit_button = tk.Button(button_container, width=35, state='active',
                                text="Exit", command=lambda:self.exit())
        buttons.append([exit_button, 'exit'])
        
        # Checks
        gpu_check = tk.Checkbutton(check_container, text='GPU')
        
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

        start_button.grid(row=0, column=0)
        stop_button.grid(row=1, column=0)
        help_button.grid(row=2, column=0)
        exit_button.grid(row=3, column=0)
        reset_button.grid(row=0, column=1)
        inform_button.grid(row=1, column=1)
        pod_button.grid(row=2, column=1)
        
        gpu_check.grid(row=0, column=0)
        
        button_container.grid(row=3, column=0)
        check_container.grid(row=2, column=0)
        
        self.set_labels(labels)
        self.set_entries(entries)
        self.set_buttons(buttons)
        