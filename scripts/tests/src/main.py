""" Native imports. """
import threading
import argparse

""" Class imports. """
from obj.scenario import Scenario
from obj.window import Window
from obj.host import Host

""" Throws errors.

@return null
"""
def throw_error(mes):
    
    if mes == 'size':
        print('The test suite reqiures a valid packet size.')
    elif mes == 'url':
        print('The test suite requires a valid URL.')
    elif mes == 'ex':
        print('Test Suite Failure.')

""" Creates the command line parser.

@return null
"""
def make_parser():

    parser = argparse.ArgumentParser()

    parser.add_argument('-o', '--out', choices=['f', 's'], 
        default='f', help="Output option")
    parser.add_argument('-g', '--gui', action='store_true',
        help='Opens GUI')

    parser.add_argument('-u', '--url', help="Target endpoint URL")
    parser.add_argument('-i4', '--i4addr', help="Target IPv4 address")
    parser.add_argument('-i6', '--i6addr', help="Target IPv6 address")
    parser.add_argument('-hn', '--hostname', help="Target Hostname")
    parser.add_argument('-p', '--port', help="Target port number")
    parser.add_argument('-un', '--username', help="Target username")
    parser.add_argument('-pw', '--password', help="Target password")

    parser.add_argument('-i', '--info', action='store_true',
        help="Analyze URL")
    parser.add_argument('-log', '--login', action='store_true',
        help="Perform login")
    parser.add_argument('-dict', '--dictionary', action='store_true',
        help="Perform Dictionary Attack")
    parser.add_argument('-pod', '--pingdeath', action='store_true',
        help="Perform Ping of Death Attack")
    
    parser.add_argument('-l', '--len', help="Desired loop length")
    parser.add_argument('-s', '--size', help="Desired packet size")
    
    return parser 

""" Accepts command line arguments to run the test suite.

@return null
"""
def main(parser):
    args = parser.parse_args()
    
    try:
        scene = Scenario()
        host = Host(scene)
    
        if args.gui:
            while True:
                scene.clear_screen()
                
                window = Window(host)
                window.open()
        else:
            if args.info:
                scene.clear_screen()
                print('Informing ...')
                if args.url:
                    host.set_url(args.url)
                    
                    ithread = threading.Thread(target=host.quick())
                    ithread.start()
                    ithread.join()
            
                    if args.pingdeath:
                        if args.size:
                            print("Simulating Ping of Death @ " + args.url)
                            
                            host.set_psize(args.size)
                            pod_thread = threading.Thread(target=host.pod())
                            pod_thread.start()
                            pod_thread.join()
                        else:
                            throw_error('size')
                    else:
                        host.show_info()
                else:
                    throw_error('url')
            else:
                print("Choose a mode.")
                    
    except Exception as ex:
        throw_error('ex')

""" Crafts the parser and runs the main program.

@return null
"""
if __name__ == '__main__':

    parser = make_parser()
    
    main(parser)